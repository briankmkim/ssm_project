/* oneDPI.cpp 
 * Driver for DPI simulation using one DPI tool.
 *
 */

#include "toolQueue.hpp"
#include "packet.hpp"
#include "packetGen.hpp"
#include "simulationClock.hpp"
#include "dpi.hpp"

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	// Set simulation constraints
	const double ENDTIME = 60.0;
	const int    RUNS    = 1000;

	// Set simulation variables
	double nextTime;

	// Initialize objects
	ToolQueue queue;
	DPI d1, d2;
	SimulationClock clock;
	PacketGen pg(ENDTIME);

	// Open file output
	ofstream output;
	output.open(argv[1]);
	output << "Run,PktDrops,d1PktServ,d2PktServ,d1IdleTime,d2IdleTime\n";
	
	for(int i = 0; i < RUNS; i++) {
		// Packet generator creates a series of packets
		pg.generate();
	
		// Begin sim loop
		while(clock.getTime() < ENDTIME && !pg.outOfPackets()) {
			//cout << "Simulation loop\n";
			// Find next time an event occurs, and perform it
			// We do this by assuming the next action is the arrival of a new packet
			// and then comparing that time to next time a DPI is available
			nextTime = pg.nextPacketArrival();
			if((d1.getTimeNextAvail() < nextTime) && !queue.isEmpty())
				nextTime = d1.getTimeNextAvail();
			if((d2.getTimeNextAvail() < nextTime) && !queue.isEmpty())
				nextTime = d2.getTimeNextAvail();

			clock.advanceClock(nextTime);
		
			// If the tool is ready to take another packet off the queue before the
			// next packet arrives, AND the queue is not empty, advance the simulation
			// to the point where the DPI tool takes a packet off the queue. Otherwise,
			// advance the simulation clock to the next packet arrival time and
			// arrive the next packet.
			if(d1.isAvail(nextTime)) {
				if(queue.isEmpty()) {	
					// Give d1 the packet
					d1.dpiStatus(pg.getNextPacket(), clock.getTime());
					// Remove the packet from the packet generator
					pg.pop();
				} else {
					// Have DPI tool grab a packet off the queue
					d1.dpiStatus(queue.getNextPacket(), clock.getTime());
					// Delete that packet off the queue
					queue.popStack();
				}

				// Update idle times of other DPI tools
				d2.updateIdleTime(clock.getTime());
			} else if(d2.isAvail(nextTime)) {
				if(queue.isEmpty()) {
                	// Give d2 the packet
                	d2.dpiStatus(pg.getNextPacket(), clock.getTime());
					// Remove that packet from the packet generator
					pg.pop();
				} else {
					// d2 takes a packet off the queue
                	d2.dpiStatus(queue.getNextPacket(), clock.getTime());
					// Delete that packet off the queue
                	queue.popStack();
				}

				//Update idle times
				d1.updateIdleTime(clock.getTime());
			} else {
				// Arrive the next packet from the generator to the queue
				queue.insert(pg.getNextPacket());

				// Delete the packet from the generator's queue
				pg.pop();

				// Update idle times
				d1.updateIdleTime(clock.getTime());
				d2.updateIdleTime(clock.getTime());
			}
		} // end simulation

		// Report outcomes
		output << i;
		output << ",";

		output << queue.getPacketsDropped();
		output << ",";

		output << d1.getPacketsScanned();
		output << ",";
		output << d2.getPacketsScanned();
		output << ",";

		output << d1.getIdleTime();
		output << ",";
		output << d2.getIdleTime();
		output << "\n";
		
		// Clear object statistics
		queue.reset();
		d1.reset();
		d2.reset();
		pg.reset();
		
	} // end sim runs
	output.close();

	return 0;
}
