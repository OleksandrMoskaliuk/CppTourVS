#include "future.h"
#include <future>
#include <iostream>
#include <string>

namespace multithreading {
namespace future {
void future() {
  std::future<int> future = std::async(std::launch::async, []() {
    // std::this_thread::sleep_for(std::chrono::seconds(10));
    return 8;
  });
}

void future_example() {
  std::future<int> future = std::async(std::launch::async, []() {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 8;
  });

  std::cout << "waiting...\n";
  std::future_status status;
  do {
    switch (status = future.wait_for(std::chrono::seconds(1)), status) {
      case std::future_status::deferred:
        std::cout << "deferred\n";
        break;
      case std::future_status::timeout:
        std::cout << "timeout\n";
        break;
      case std::future_status::ready:
        std::cout << "ready!\n";
        break;
    }
  } while (status != std::future_status::ready);
  //   get result
  std::cout << "result is " << future.get() << '\n';
}
}  // namespace future
}  // namespace multithreading
