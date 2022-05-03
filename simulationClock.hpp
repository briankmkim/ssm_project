#include <iostream>
#include <chrono>
#define Queue queue

class SimulationClock {

	private:
		double time;

	public:
		SimulationClock() {
			time = 0.0;
		}

		getTime() {
			return time;
		}

		advanceClock(double addTime) {
			time += addTime;
		}

	/*
	auto start = std::chrono::steady_clock::now();
	while (!queue.isEmpty()) {
		queue.peek();
		//Do something
	}
	auto end = std::chrono::steady_clock::now();

	auto time = end - start;
	std::cout << "Time to analyze packet: " << std::chrono::duration<double, std::milli>(time).count() << " ms\n";
	*/
}
