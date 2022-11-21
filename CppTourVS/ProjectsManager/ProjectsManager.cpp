#include "ProjectsManager.h"

#include <future>
#include <iostream>

#include "../Algorithm\Sorting/Sorting.h"
#include "../BitOperations/8bit.h"
#include "../Messenger/Messenger.h"
#include "../Multithreading/Future/my_future.h"
#include "../Multithreading/ProcessCommunicator/PRCM.h"
#include "../Timer/my_timer.h"
#include "../_DataStructures/MyList/2WayList.h"
#include "../_DataStructures/MyList/MyList.h"
#include "../bmp_loader/bmp_loader.h"
#include "../dictionary/dict_v1/dictionary.h"
#include "../dictionary/dict_v2/dct2.h"
#include "gtest/gtest.h"

namespace project_manager {

ProjectsManager::ProjectsManager(int& argc, char* argv[]) {
  this->argc = &argc;
  this->argv = argv;
}

// Multithreading/ProcessCommunicator

void ProjectsManager::process_communicator() {
  bool _exit = false;
  pr_cmm::ProcessCommunicator prc;
  std::thread th1(pr_cmm::sprocess_1, std::ref(_exit));
  std::thread th2(pr_cmm::sprocess_2, std::ref(_exit));
  th1.detach();
  th2.detach();

  std::cin.get();
  _exit = true;
}

void ProjectsManager::process_communicator_tests() {
  testing::InitGoogleTest(this->argc, this->argv);
  testing::GTEST_FLAG(filter) = "ProcessCommunicator_Tests*";
  RUN_ALL_TESTS();
}

void ProjectsManager::run_dictionary_v1() {
  my_dictionary::MyDictionary md;
  md.MainLoop();
}

void ProjectsManager::run_dictionary_v2() {
  DictionaryV2 dct2;
  dct2.MainLoop();
}

void ProjectsManager::run_my_timer() {
  SimpleTimer SmT;
  std::this_thread::sleep_for(std::chrono::seconds(2));
  symbol_animation sm;
  // press 'x' to exit;
  sm.animation_run();
}

void ProjectsManager::BmpLoaderStart() {
  std::string filename = "bmp_loader/awsom.bmp";
  std::vector<Bitmap> bitmap_test;
  BMP_Sprites_Hub SHub;
  SHub.bmp_convert(filename, bitmap_test);
  // check out color
  for (Bitmap bmp : bitmap_test) {
    std::cout << " R_:" << (int)bmp.R << " G_:" << (int)bmp.G
              << " B_:" << (int)bmp.B << "\n";
  }
}

void ProjectsManager::run_messenger() { messenger(); }

// _DataStructures//MyList
void ProjectsManager::run_my_list() {
  // std::cout << "adsfgsgd";
  // my_list::sa();

  my_list::List<int> df;
  df.push_back(10);
  df.push_back(20);
  df.push_back(30);
  df.push_back(40);
  df.push_back(50);
  df.push_back(60);
  for (int i = 0; i < df.get_size(); i++) {
    std::cout << df[i] << "\n";
  }

  std::cout << "result:" << std::endl;
  df.push_front(56);
  df.push_front(522);
  for (int i = 0; i < df.get_size(); i++) {
    std::cout << df[i] << "\n";
  }
  // std::cout << df[0] <<"\n";
  // std::cout << df[1] << "\n";
  // std::cout << df[2] << "\n";
}

void ProjectsManager::run_my_2way_list() {
  my_list::TwoWayList<std::string> twl;
  std::string str = "a";
  twl.push_back(str);
  twl.push_back(str);
  twl.push_back(str);
  twl.push_back(str);
  twl.push_back(str);

  for (uint8_t i = 0; i < twl.get_size(); i++) {
    std::cout << "[" << (int)i << "] = " << twl[i] << "\n";
  }
  std::cout << "__get data from adress __________________\n";
  for (uint8_t i = 0; i < twl.get_size(); i++) {
    std::cout << "[" << (int)i << "] = " << twl.get_node_adress(i)->data
              << "\n";
  }
  std::cout << "__remove [2]_______________________________\n";
  twl.remove(5);
  for (uint8_t i = 0; i < twl.get_size(); i++) {
    std::cout << "[" << (int)i << "] = " << twl[i] << "\n";
  }
  std::cout << "__remove [3]_______________________________\n";
  twl.remove(3);
  for (uint8_t i = 0; i < twl.get_size(); i++) {
    std::cout << "[" << (int)i << "] = " << twl[i] << "\n";
  }
  std::cout << "__remove [1]_______________________________\n";
  twl.remove(1);
  for (uint8_t i = 0; i < twl.get_size(); i++) {
    std::cout << "[" << (int)i << "] = " << twl[i] << "\n";
  }
  // std::cout << twl.get_size() << "\n";
}  // void ProjectsManager::run_my_2way_list()

}  // namespace project_manager