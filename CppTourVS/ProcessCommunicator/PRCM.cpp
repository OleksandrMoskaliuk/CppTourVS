#include "PRCM.h"

namespace pr_cmm {

	// ProcessCommunicator private variables {
	int ProcessCommunicator::size_of_message = 0;
	// } ProcessCommunicator private variables 

	ProcessCommunicator::ProcessCommunicator() {};

	template <class Data>
	static void ProcessCommunicator::send_message(Data &dt, std::string message_name) {
		// sending data to shared memory area {
		const char* shared_memory = message_name.c_str();
		try {
			//Erase previous shared memory
			boost::interprocess::shared_memory_object::remove(shared_memory);
			//Create a shared memory object.
			boost::interprocess::shared_memory_object shm(boost::interprocess::create_only, shared_memory, boost::interprocess::read_write);
			//Set size
			size_of_message = sizeof(dt);
			shm.truncate(size_of_message);
			//Map the whole shared memory in this process
			boost::interprocess::mapped_region region(shm, boost::interprocess::read_write);
			std::memcpy(region.get_address(), &dt, size_of_message);
#if ProcessCommunicatorDebug
			std::cout << "Sended messege have: " << size_of_message << " _bytes" << std::endl;
#endif
		}
		catch (boost::interprocess::interprocess_exception& ex) {
#if ProcessCommunicatorDebug
			std::cout << "Unexpected exception when message: " 
				<< message_name << " was received. Exception : " 
				<< ex.what() << std::endl;
#endif // ProcessCommunicatorDebug
			boost::interprocess::shared_memory_object::remove(shared_memory);
		}
		// } sending data to shared memory area

	}
	template <class Data>
	static void ProcessCommunicator::get_message(Data& dt, std::string message_name) {
		// getting data from shared memory area {
		const char* shared_memory = message_name.c_str();
		try {
			//Open already created shared memory object.
			boost::interprocess::shared_memory_object shm(boost::interprocess::open_only, shared_memory, boost::interprocess::read_only);
			//Map the whole shared memory in this process
			boost::interprocess::mapped_region region(shm, boost::interprocess::read_only);
			// converting and copy data from shared memory area
			memcpy(&dt, region.get_address(), size_of_message);
#if ProcessCommunicatorDebug
			std::cout << "Message received! :" << dt << std::endl;
#endif // ProcessCommunicatorDebug

		}
		catch (boost::interprocess::interprocess_exception& ex) {
#if ProcessCommunicatorDebug
			std::cout << "Unexpected exception when message: "
				<< message_name << " was received."
				<< "Exception : " << ex.what() << std::endl;
#endif // ProcessCommunicatorDebug
			boost::interprocess::shared_memory_object::remove(shared_memory);
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

	int PRCM_main()
	{
		bool _exit = false;
		ProcessCommunicator prc;
		std::thread th1(sprocess_1, std::ref(_exit));
		std::thread th2(sprocess_2, std::ref(_exit));
		th1.detach();
		th2.detach();

		std::cin.get();
		_exit = true;

		return 1;
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


