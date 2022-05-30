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
		static bool send_message(Data &dt, const char * message_name);
		template <class Data>
		static bool get_message(Data &dt, const char * message_name);

	private:
		static std::map<std::string, std::pair<int, bool>> message_manager;
	};

	void worker_1(bool& _exit);
	void worker_2(bool& _exit);
	void sprocess_1(bool& exit);
	void sprocess_2(bool& exit);
} // namespace pr_cmm




#endif // PRCM_H