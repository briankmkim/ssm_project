#ifndef PACKET_GEN_HEADER
#define PACKET_GEN_HEADER

/* packetGen.hpp
 * Packet Generator for DPI simulation.
 */

#include "packet.hpp"
#include <random>
#include <queue>
#include <chrono>

using namespace std;

class PacketGen {
	private:
		const double ENT_MEAN = 0.0156143;
		const double ENT_STD_DEV = 0.0861771;
		const double ENT_RANGE = 0.999998;
		const double SCAN_MIN = 0.000010;
		const double SCAN_MAX = 0.000027;

		double endTime;
		queue<Packet> packets;
		

	public:
		PacketGen(double end) {
			endTime = end;
		};

		double nextPacketArrival();
		Packet getNextPacket();
		void pop();
		void generate();
		bool outOfPackets();
		void reset();
};

double PacketGen::nextPacketArrival() {
	return packets.front().getEntryTime();
}

Packet PacketGen::getNextPacket() {
	return packets.front();
}

void PacketGen::pop() {
	packets.pop();
}

void PacketGen::generate() {
	std::default_random_engine generator;
	generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::normal_distribution<double> entdist(ENT_MEAN, ENT_STD_DEV);
	std::uniform_real_distribution<double> scandist(SCAN_MIN, SCAN_MAX);

	double time = 0;
	double nextTime = 0;

	while(time < endTime) {
		packets.emplace(time, scandist(generator));
		
		nextTime = entdist(generator);
		while(nextTime > ENT_RANGE || nextTime < 0) {
			nextTime = entdist(generator);
		}
		time = time + nextTime;
	}
	
}

bool PacketGen::outOfPackets() {
	return packets.empty();
}

void PacketGen::reset() {
	while(!packets.empty())
		packets.pop();
}

#endif
