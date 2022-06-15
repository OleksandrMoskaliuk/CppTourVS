// CppTourVS.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//


#include "../ProjectsManager/ProjectsManager.h"



int main(int argc, char* argv[]) {
    
    project_manager::ProjectsManager PM(argc, argv);
  PM.run_my_dictionary();

   
}

#include <future>
void future() {
    std::future<int> future = std::async(std::launch::async, []() {
        // std::this_thread::sleep_for(std::chrono::seconds(10));
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

    std::cout << "result is " << future.get() << '\n';
}

