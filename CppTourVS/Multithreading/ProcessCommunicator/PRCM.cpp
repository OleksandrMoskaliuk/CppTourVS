#include "PRCM.h"

namespace pr_cmm {

#define ProcessCommunicatorDebug 1

	// ProcessCommunicator private variables {
	std::map<std::string, std::pair<int, bool>> ProcessCommunicator::message_manager;
	// } ProcessCommunicator private variables 

	ProcessCommunicator::ProcessCommunicator() {};

	void ProcessCommunicator::remove(const char* message_name)
	{
		message_manager.erase(message_name);
		// simplify erasing data along with data manager
#if ProcessCommunicatorDebug
		std::cout << "Message: '" << message_name << "' _was erased from Message Manager!: " << message_name << std::endl;
#endif // ProcessCommunicatorDebug
		boost::interprocess::shared_memory_object::remove(message_name);
#if ProcessCommunicatorDebug
		std::cout << "Message: '" << message_name << "' _was removed from shared memory!" << std::endl;
#endif // ProcessCommunicatorDebug


	};

	template <class Data>
	static bool ProcessCommunicator::send_message(Data &message_data, const char * message_name) {
		// sending data to shared memory area {
		//check if message exist 
		if (message_manager.count(message_name) > 0)
		{
#if ProcessCommunicatorDebug
			std::cout << "Message: '" << message_name << "' _already exist." << std::endl;
#endif
			return false;
		}
		//add message to message manager
		message_manager.emplace(message_name, std::make_pair(sizeof(message_data),false));
		try {
			//Erase previous shared memory
			//boost::interprocess::shared_memory_object::remove(message_name);
			//Create a shared memory object.
			boost::interprocess::shared_memory_object shm(boost::interprocess::create_only, message_name, boost::interprocess::read_write);
			//Set size
			shm.truncate(message_manager[message_name].first);
			//Map the whole shared memory in this process
			boost::interprocess::mapped_region region(shm, boost::interprocess::read_write);
			std::memcpy(region.get_address(), &message_data, message_manager[message_name].first);
			// Mark message ready \|/
			message_manager[message_name].second = true;
#if ProcessCommunicatorDebug
			std::cout << "Message: '" << message_name << "' copied" << std::endl;
			std::cout << "Sended messege have: " << message_manager[message_name].first << " _bytes" << std::endl;
#endif
			return true;
		}
		catch (boost::interprocess::interprocess_exception& ex) {
#if ProcessCommunicatorDebug
			std::cout << "Unexpected exception when message: '" 
				<< message_name << "' was received.\nException : " 
				<< ex.what() << std::endl;
#endif // ProcessCommunicatorDebug
			remove(message_name);
			return false;
		}
		// } sending data to shared memory area

	}

	//receiving message method \|/
	template <class Data>
	static bool ProcessCommunicator::get_message(Data& message_data, const char * message_name) {
		// getting data from shared memory area {
		// checking if message exist
		if (message_manager.count(message_name) <= 0)
			return false;
		//checking if message ready. Second argument of pair should be true
		if (message_manager[message_name].second != true)
			return false;
		try {
			//Open already created shared memory object
			boost::interprocess::shared_memory_object shm(boost::interprocess::open_only, message_name, boost::interprocess::read_only);
			//Map the whole shared memory in this process
			boost::interprocess::mapped_region region(shm, boost::interprocess::read_only);
			// converting and copy data from shared memory area
			// memcpy(&dest,source,amount of bytes)
			memcpy(&message_data, region.get_address(), message_manager[message_name].first);
#if ProcessCommunicatorDebug
			std::cout << "Message received! :" << message_data << std::endl;
#endif // ProcessCommunicatorDebug
			//remove message from message manager after copy it should be erased from shared memory also
			remove(message_name);
			return true;
		}
		catch (boost::interprocess::interprocess_exception& ex) {
#if ProcessCommunicatorDebug
			std::cout << "Unexpected exception when message: "
				<< message_name << " was received."
				<< "Exception : " << ex.what() << std::endl;
#endif // ProcessCommunicatorDebug
			boost::interprocess::shared_memory_object::remove(message_name);
			return false;
		}
		
		// } getting data from shared memory area	
	}

	void sprocess_1(bool& exit)
	{
		std::string str = "12345";
		int i = 8;
		while (!exit)
		{
			// process stream info {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "sProcess 1 working ..." << std::endl;
			// } process stream info 
			ProcessCommunicator::send_message<int>(i, "supername");
		}
	}

	void sprocess_2(bool& exit)
	{
		std::string res = "";
		int i = 0;
		while (!exit)
		{
			// process stream info {
			std::this_thread::sleep_for(std::chrono::seconds(2));
			std::cout << "sProcess 2 working ..." << std::endl;
			// } process stream info 
			//std::cout << "Result > " << i << std::endl;
			ProcessCommunicator::get_message<int>(i, "supername");
			std::cout << "Result > " << i << std::endl;
		}
	}

	

	void worker_1(bool& _exit)
	{
		while (!_exit)
		{
			// process stream info {
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			std::cout << "Worker 1 working ..." << std::endl;
			// } process stream info 
			// sending data to shared memory area {
			try {
				//Erase previous shared memory
				boost::interprocess::shared_memory_object::remove("shared_memory");
				//Create a shared memory object.
				boost::interprocess::shared_memory_object shm(boost::interprocess::create_only, "shared_memory", boost::interprocess::read_write);
				//Set size
				shm.truncate(sizeof(std::string("test")));
				//Map the whole shared memory in this process
				boost::interprocess::mapped_region region(shm, boost::interprocess::read_write);
				std::string str("test");
				std::memcpy(region.get_address(), &str, sizeof(std::string("test")));
			}
			catch (boost::interprocess::interprocess_exception& ex) {
				std::cout << "Unexpected exception: " << ex.what() << std::endl;
				boost::interprocess::shared_memory_object::remove("shared_memory");

			}
			// } sending data to shared memory area
		}

	}

	void worker_2(bool& _exit)
	{
		std::string str = "";
		while (!_exit)
		{
			// process stream info {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "Worker 2  working ..." << std::endl;
			// } process stream info 
			// getting data from shared memory area {
			try {
				//Open already created shared memory object.
				boost::interprocess::shared_memory_object shm(boost::interprocess::open_only, "shared_memory", boost::interprocess::read_only);
				//Map the whole shared memory in this process
				boost::interprocess::mapped_region region(shm, boost::interprocess::read_only);
				// converting and copy data from shared memory area
				memcpy(&str, region.get_address(), sizeof(std::string("test")));
				std::cout << "Test successful!:" << str << std::endl;
			}
			catch (boost::interprocess::interprocess_exception& ex) {
				std::cout << "Unexpected exception: " << ex.what() << std::endl;
				boost::interprocess::shared_memory_object::remove("shared_memory");
			}
			// } getting data from shared memory area
		}
	}

	
}


