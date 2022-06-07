// all headers included here
#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

#include "gtest/gtest.h"
#include <iostream>
#include "../Algorithm\Sorting/Sorting.h"
#include "../BitOperations/8bit.h"
#include "../Timer/my_timer.h"
#include "../Multithreading/ProcessCommunicator/PRCM.h"
#include "../_DataStructures/MyList/MyList.h"
#include "../_DataStructures/MyList/2WayList.h"

namespace project_manager {

	class ProjectsManager
	{
	private:
		int *argc;
		char** argv;

	public:
		ProjectsManager(int& argc, char* argv[]);
		
		
		//Data_Structures

		// Multithreading/ProcessCommunicator
		void process_communicator();
		void process_communicator_tests();

		// My_List

		void run_my_list();
		void run_my_2way_list();
       
	   // my_timer();
	   // my_sort::entry_point();
	   // _8bit::entry_point();
	};

} // project_manager
#endif // PROJECT_MANAGER_H