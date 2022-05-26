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
		template <class Data>
		static void send_message(Data &dt, std::string message_name);
		template <class Data>
		static void get_message(Data &dt, std::string message_name);

	private:
		static std::map<std::string, int> message_manager;
	};

	int PRCM_main();
	void worker_1(bool& _exit);
	void worker_2(bool& _exit);
}



#endif // PRCM_H