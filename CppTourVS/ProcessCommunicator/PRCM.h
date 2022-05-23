#ifndef PRCM_H
#define PRCM_H

#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <string>

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>
#include <cstring>

// <map> Used for assign size of transmitted memory area 
#include <map>
namespace pr_cmm {

	class ProcessCommunicator {
	public:
		ProcessCommunicator();
		~ProcessCommunicator() {};
		void send_message();
		void get_message(std::string& str);

	private:
		static int size_of_message;
	};
	

	
	int PRCM_main();
	void worker_1(bool& _exit);
	void worker_2(bool& _exit);
	void writer();
	void reader();
	

}



#endif // PRCM_H
