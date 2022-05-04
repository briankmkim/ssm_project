#ifndef DPI_HPP_INCLUDED
#define DPI_HPP_INCLUDED

#include "packet.hpp"

class DPI
{
private:
    double idleTime;
    double timeNextAvailable;
    int packetsScanned;

    //ToolQueue * pointTQ = new ToolQueue();
    //ToolQueue & refTQ = (*pointTQ);

public:

	DPI() {
		idleTime = 0;
		timeNextAvailable = 0;
		packetsScanned = 0;
	}

    double getIdleTime()
    {
        return idleTime;
    }

    double getTimeNextAvail()
    {
        return timeNextAvailable;
    }

    int getPacketsScanned()
    {
        return packetsScanned;
    }

    bool isAvail(double currentTime)
    {
        if (currentTime >= timeNextAvailable){
            return true;
        }
        return false;
    }

    //given a packet and current time, increase idle time, set next time avail, and
	//increment packetsScanned 

    void dpiStatus (Packet p, double time)
    {
		updateIdleTime(time);
		timeNextAvailable = time + p.getScanTime();
		packetsScanned++;
    }

	void updateIdleTime(double time) {
		if(time > timeNextAvailable) {
			idleTime = idleTime + (time - timeNextAvailable);
			timeNextAvailable = time;
		}
	}

	void reset() {
		idleTime = 0;
		timeNextAvailable = 0;
		packetsScanned = 0;
	}

};

#endif // DPI_HPP_INCLUDED
