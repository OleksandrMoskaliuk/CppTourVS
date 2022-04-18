#include "dead_lock.h"

namespace dead_lock {

std::mutex Gmtx1;
std::mutex Gmtx2;

void print1() {
  Gmtx2.lock();
  std::cout << "\nGmtx2.lock();\n";
  std::this_thread::sleep_for(std::chrono::seconds(1));
  Gmtx1.lock();
  for (size_t i = 0; i < 10; ++i) {
    for (size_t j = 0; j < 10; ++j) {
      std::cout << "C++";
    }
    std::cout << '\n';
  }
  Gmtx1.unlock();
  Gmtx2.unlock();
}

void print2() {
  Gmtx1.lock();
  std::cout << "\nGmtx1.lock();\n";
  std::this_thread::sleep_for(std::chrono::seconds(1));
  Gmtx2.lock();
  for (size_t i = 0; i < 10; ++i) {
    for (size_t j = 0; j < 10; ++j) {
      std::cout << "C++";
    }
    std::cout << '\n';
  }
  Gmtx2.unlock();
  Gmtx1.unlock();
}

void entry_point() {
  using Thread = std::thread;

  Thread th1([]() { print1(); });

  Thread th2([]() { print2(); });

  th1.join();
  th2.join();
}

}  // namespace dead_lock