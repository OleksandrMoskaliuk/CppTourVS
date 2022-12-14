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
  ~ProjectsManager();

  /* DataStructures/MyList/2WayList.h */
  void run_my_2way_list();
  // Multithreading/ProcessCommunicator
  void process_communicator();
  void process_communicator_tests();
  /* DataStructures/MyList/my_map.h */

  // dictionary
  void run_dictionary_v1();
  //SFML
  void Run_mysfmlWindow();

  //Timer
  void run_my_timer();
  // my_timer();
  // my_sort::entry_point();
  // _8bit::entry_point();

  void BmpLoaderStart();

  // dummy messenger
  void run_messenger();
 };

}  // namespace project_manager
#endif  // PROJECT_MANAGER_H