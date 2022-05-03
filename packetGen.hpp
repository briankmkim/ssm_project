#ifndef PACKET_GEN_HEADER
#define PACKET_GEN_HEADER

/* packetGen.hpp
 * Packet Generator for DPI simulation.
 */

#include "packet.hpp"
#include <random>
#include <queue>

class PacketGen {
	private:
		const double ENT_MEAN = 0.0156143;
		const double ENT_STD_DEV = 0.0861771;
		const double ENT_RANGE = 0.999998;
		const double SCAN_MAX = 0.000027;

		double endTime;
		Queue<Packet> packets;
		

	public:
		PacketGen(double end) {
			this.endTime = end;
			this.packets = new Queue<Packet>();
		};

		double nextPacketArrival();
		Packet getNextPacket();
		void generate();
}

public double nextPacketArrival() {
	return this.packets.top().getEntryTime();
}

public Packet getNextPacket() {
	return this.packets.pop();
}

public void generate() {
	std::default_random_engine generator;
	std::normal_distribution<double> entdist(MEAN, STD_DEV);
	std::uniform_real_distribution<double> scandist(0, SCAN_MAX);

	double time = 0;

	while(time < endTime) {
		this.packets.push(
			new Packet(time, scandist(generator)));

		time += entdist(generator);
	}
	
}

#endif
