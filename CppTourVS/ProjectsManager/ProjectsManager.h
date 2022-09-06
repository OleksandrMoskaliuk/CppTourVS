// all headers included here
#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

#include "gtest/gtest.h"
#include <iostream>
#include "../Algorithm/Sorting/Sorting.h"
#include "../BitOperations/8bit.h"
#include "../Timer/my_timer.h"
#include "../Multithreading/ProcessCommunicator/PRCM.h"
#include "../bmp_loader/bmp_loader.h"
#include "../SFML_window/window.h"

namespace project_manager {

	class ProjectsManager
	{
	public:
		ProjectsManager();
		//Data_Structures

		// Multithreading/ProcessCommunicator
		void process_communicator();
		void process_communicator_tests(int& argc, char* argv[]);
		void sfml_window_start();

	   // my_timer();
	   // my_sort::entry_point();
	   // _8bit::entry_point();
	};

} // project_manager
#endif // PROJECT_MANAGER_H