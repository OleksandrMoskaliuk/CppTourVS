// all headers included here
#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

#include <iostream>

#include "../Algorithm\Sorting/Sorting.h"
#include "../BitOperations/8bit.h"
#include "../Multithreading/ProcessCommunicator/PRCM.h"
#include "../Timer/my_timer.h"
#include "../_DataStructures/MyList/2WayList.h"
#include "../_DataStructures/MyList/MyList.h"
#include "../dictionary/dictionary.h"
#include "gtest/gtest.h"
namespace project_manager {

class ProjectsManager {
 private:
  int* argc;
  char** argv;

 public:
  ProjectsManager(int& argc, char* argv[]);

  // Data_Structures

  // Multithreading/ProcessCommunicator
  void process_communicator();
  void process_communicator_tests(int& argc, char* argv[]);
  void sfml_window_start();

  // My_List

  void run_my_list();
  void run_my_2way_list();
  void run_my_dictionary();

  // my_timer();
  // my_sort::entry_point();
  // _8bit::entry_point();
};

}  // namespace project_manager
#endif  // PROJECT_MANAGER_H
