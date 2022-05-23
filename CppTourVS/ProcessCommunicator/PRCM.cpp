#include "PRCM.h"


namespace pr_cmm {
	// ProcessCommunicator private variables {
	int ProcessCommunicator::size_of_message = 0;
	// } ProcessCommunicator private variables 
	std::mutex g_i_mutex;
	class BIC_Wrapper
	{

	public:
		template <typename Data>
		static void send_message(std::string msg_name, Data data)
		{
			const std::lock_guard<std::mutex> lock(g_i_mutex);
			const char* shared_memory_name = msg_name.c_str();
			data_size.emplace(msg_name, sizeof(data));
			using namespace boost::interprocess;
			try {
				//Erase previous shared memory
				shared_memory_object::remove(shared_memory_name);

				//Create a shared memory object.
				shared_memory_object shm(create_only, shared_memory_name, read_write);

				//Set size
				shm.truncate(sizeof(data));

				//Map the whole shared memory in this process
				mapped_region region(shm, read_write);

				//Write all the memory to 1
				//region.get_address() = '1';

				//const char* mem = static_cast<char*>(region.get_address());

				//std::memset(static_cast<char*>(region.get_address()), '1' , 1);
				std::memcpy(region.get_address(), &data, sizeof(data));

			}
			catch (interprocess_exception& ex) {
				shared_memory_object::remove(shared_memory_name);
				std::cout << ex.what() << std::endl;

			}
		}

		template <typename MsgType>
		static MsgType get_message(std::string msg_name)
		{
			const std::lock_guard<std::mutex> lock(g_i_mutex);
			const char* shared_memory_name = msg_name.c_str();
			MsgType received_data;
			using namespace boost::interprocess;
			//shared_memory_object::remove("shared_memory");
			try {
				//Open already created shared memory object.
				shared_memory_object shm(open_only, shared_memory_name, read_only);

				//Map the whole shared memory in this process
				mapped_region region(shm, read_only);

				//Check that memory was initialized to 1
				//const char* mem = static_cast<char*>(region.get_address());


				memcpy(&received_data, region.get_address(), data_size[msg_name.c_str()]);

				/*for (std::size_t i = 0; i < region.get_size(); ++i) {
					auto res = *mem++;
					std::cout << res << std::endl;
				}*/
				std::cout << "Test successful!" << std::endl;
			}
			catch (interprocess_exception& ex) {
				std::cout << "Unexpected exception: " << ex.what() << std::endl;
				shared_memory_object::remove(shared_memory_name);

			}
			shared_memory_object::remove(shared_memory_name);

			return received_data;
		}
	private:
		static std::map<std::string, int> data_size;
		static bool blocked;

	};
	std::map<std::string, int> BIC_Wrapper::data_size;
	bool BIC_Wrapper::blocked = false;


	ProcessCommunicator::ProcessCommunicator() {};

	void ProcessCommunicator::send_message() {

		// sending data to shared memory area {
		try {
			//Erase previous shared memory
			boost::interprocess::shared_memory_object::remove("shared_memory");
			//Create a shared memory object.
			boost::interprocess::shared_memory_object shm(boost::interprocess::create_only, "shared_memory", boost::interprocess::read_write);
			//Set size
			this->size_of_message = sizeof(std::string("test"));
			shm.truncate(size_of_message);
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

	void ProcessCommunicator::get_message(std::string &str) {

		
		// getting data from shared memory area {
		try {
			//Open already created shared memory object.
			boost::interprocess::shared_memory_object shm(boost::interprocess::open_only, "shared_memory", boost::interprocess::read_only);
			//Map the whole shared memory in this process
			boost::interprocess::mapped_region region(shm, boost::interprocess::read_only);
			// converting and copy data from shared memory area
			memcpy(&str, region.get_address(), size_of_message);
			std::cout << "Test successful!:" << str << std::endl;
		}
		catch (boost::interprocess::interprocess_exception& ex) {
			std::cout << "Unexpected exception: " << ex.what() << std::endl;
			boost::interprocess::shared_memory_object::remove("shared_memory");

		}
		// } getting data from shared memory area

		
	}

	


	


	


	void sprocess_1( bool &exit)
	{
		ProcessCommunicator prc;
		while (!exit)
		{
			// process stream info {
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			std::cout << "sProcess 1 working ..." << std::endl;
			// } process stream info 
			prc.send_message();

		}
	}

	void sprocess_2( bool& exit)
	{
		ProcessCommunicator prc;
		std::string res = "";
		while (!exit)
		{
			// process stream info {
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			std::cout << "sProcess 2 working ..." << std::endl;
			// } process stream info 
			prc.get_message(res);
			std::cout << "Result > " << res << std::endl;
			

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

	void worker_1(bool &_exit)
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

	void worker_2(bool &_exit)
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

	void writer()
	{


		while (!exit)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(501));
			std::cout << "Worker 1 working ..." << std::endl;

			BIC_Wrapper::send_message<std::string>("str", "test");


		}
	}
	void reader()
	{



		while (!exit)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			std::cout << "Worker 2  working ..." << std::endl;

			std::cout << "result is:" << BIC_Wrapper::get_message<std::string>("str") << std::endl;




		}
	}

	
	


	
}


