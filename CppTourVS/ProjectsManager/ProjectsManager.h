// all headers included here
#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

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
  void process_communicator_tests();

  // My_List
  void run_my_list();
  void run_my_2way_list();

  // dictionary
  void run_my_dictionary();

  //SFML
  void open_window();

  //Timer
  void run_my_timer();
  // my_timer();
  // my_sort::entry_point();
  // _8bit::entry_point();

  void BmpLoaderStart();
 };

}  // namespace project_manager
#endif  // PROJECT_MANAGER_H