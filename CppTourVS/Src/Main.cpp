// CppTourVS.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//


#include "../ProjectsManager/ProjectsManager.h"



int main(int argc, char* argv[]) {
    
  project_manager::ProjectsManager PM(argc, argv);
  //PM.run_dictionary_v1();
  //PM.run_my_timer();
  //PM.Run_mysfmlWindow();
  PM.run_dictionary_v2();
}


