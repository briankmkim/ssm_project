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
        idleTime += (time - getTimeNextAvail());

        timeNextAvailable = (time + p.getScanTime());
		
		packetsScanned++;
    }

};

#endif // DPI_HPP_INCLUDED
