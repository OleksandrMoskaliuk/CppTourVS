#include "PRCM.h"
#include "string.h"

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>
#include <cstring>

namespace pr_cmm {

	class BIC_Wrapper
	{

	public:
		template <typename Data>
		static void send_message(std::string msg_name, Data data)
		{
			const char* shared_memory_name = msg_name.c_str();
			try {
				data_size = sizeof(data);

				//Erase previous shared memory
				boost::interprocess::shared_memory_object::remove(shared_memory_name);

				//Create a shared memory object.
				boost::interprocess::shared_memory_object shm(boost::interprocess::create_only, shared_memory_name, boost::interprocess::read_write);

				//Set size
				shm.truncate(data_size);

				//Map the whole shared memory in this process
				boost::interprocess::mapped_region region(shm, boost::interprocess::read_write);

				//Write all the memory
				std::memset(region.get_address(), data, region.get_size());
			}
			catch (boost::interprocess::interprocess_exception& ex) {
				boost::interprocess::shared_memory_object::remove(shared_memory_name);
				std::cout << ex.what() << std::endl;
				return;
			}
		}

		template <typename MsgType>
		static MsgType get_message(std::string msg_name)
		{
			const char* shared_memory_name = msg_name.c_str();
			MsgType mem;
			try {
				//Open already created shared memory object.
				boost::interprocess::shared_memory_object shm(boost::interprocess::open_only, shared_memory_name, boost::interprocess::read_only);

				//Map the whole shared memory in this process
				boost::interprocess::mapped_region region(shm, boost::interprocess::read_only);

				//Check that memory was initialized to 1
				mem = *(int*)(region.get_address());
				//remove message after copy 
				//boost::interprocess::shared_memory_object::remove(shared_memory_name);

			}
			catch (boost::interprocess::interprocess_exception& ex) {
				std::cout << "Unexpected exception: " << ex.what() << std::endl;
				boost::interprocess::shared_memory_object::remove(shared_memory_name);
				return 0;
			}

			return mem;
		}
		static int data_size;

	};
	int BIC_Wrapper::data_size = 0;

	bool exit = false;
	int PRCM_main()
	{
		std::thread th1(worker_1);
		std::thread th2(worker_2);
		th1.detach();
		th2.detach();
		std::cin.get();
		exit = true;


		return 1;
	}

	void worker_1()
	{
		while (!exit)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			//std::cout << "Worker 1 working ..." << std::endl;
			//BIC_Wrapper::send_message<int>("srt", 5);
			using namespace boost::interprocess;
			try {
				//Erase previous shared memory
				shared_memory_object::remove("shared_memory");

				//Create a shared memory object.
				shared_memory_object shm(create_only, "shared_memory", read_write);

				//Set size
				shm.truncate(2);

				//Map the whole shared memory in this process
				mapped_region region(shm, read_write);

				//Write all the memory to 1
				//region.get_address() = '1';
				
				//const char* mem = static_cast<char*>(region.get_address());

				//std::memset(static_cast<char*>(region.get_address()), '1' , 1);
				std::memcpy(region.get_address(), "ab", sizeof("ab"));

			}
			catch (interprocess_exception& ex) {
				shared_memory_object::remove("shared_memory");
				std::cout << ex.what() << std::endl;

			}

		}

	}

	void worker_2()
	{
		while (!exit)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "Worker 2  working ..." << std::endl;
			//int result = BIC_Wrapper::get_message<int>("srt");
			//td::cout << result << std::endl;

			using namespace boost::interprocess;
			//shared_memory_object::remove("shared_memory");
			try {
				//Open already created shared memory object.
				shared_memory_object shm(open_only, "shared_memory", read_only);

				//Map the whole shared memory in this process
				mapped_region region(shm, read_only);

				//Check that memory was initialized to 1
				const char* mem = static_cast<char*>(region.get_address());
				for (std::size_t i = 0; i < region.get_size(); ++i) {
					auto res = *mem++;
					std::cout << res << std::endl;
				}
				std::cout << "Test successful!" << std::endl;
			}
			catch (interprocess_exception& ex) {
				std::cout << "Unexpected exception: " << ex.what() << std::endl;
				shared_memory_object::remove("shared_memory");

			}
			shared_memory_object::remove("shared_memory");


		}
	}

}