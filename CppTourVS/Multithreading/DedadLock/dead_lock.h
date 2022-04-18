#ifndef DEAD_LOCK_H
#define DEAD_LOCK_H

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

namespace dead_lock {

	void print1(); 
	void print2();
    void entry_point();

}

#endif  // !DEAD_LOCK_H
