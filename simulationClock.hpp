#ifndef SIM_CLOCK_HEADER
#define SIM_CLOCK_HEADER
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

		double getTime() {
			return time;
		}

		void advanceClock(double newTime) {
			time = newTime;
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
};

#endif
