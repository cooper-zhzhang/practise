#include <atomic>
#include <thread>
#include <assert.h>

bool x = false;
std::atomic<bool> y;
std::atomic<int> z;

void write_x_the_y()
{
	x = true;
	std::atomic_thread_fence(std::memory_order_release);
	y.store(true, std::memory_order_release);
}


