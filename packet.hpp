#ifndef PACKET_HEADER
#define PACKET_HEADER
#include <string>

class Packet{

public:
    double entryTime;
    double scanTime;
	/* When would this field ever be used? When packets are popped off the queue
	 * they will no longer be held in reference, so no use in trying to store
	 * this value. If this is a metric we are interested in, we will need to save
	 * in a separate data structure.
	 */
    //double timeProcessed;
	Packet() {}

    Packet(double e, double s) {
		entryTime = e;
        scanTime = s;
    }

	// This constructor should never be called!
	/*
    Packet(double e, double s, double p){
        entryTime = e;
        scanTime = s;
        timeProcessed = p;
    }
	*/

	double getScanTime() {
		return scanTime;
	}

	double getEntryTime() {
		return entryTime;
	}
/*
    bool canServicePacket(float time){
        if(time > entryTime + timeout){
            return false;
        }else{
            return true;
        }
    }

    void servicePacket(float Time){
        if(canServicePacket(time)){
            timeProcessed = time;
        }
    }
*/
};

#endif
