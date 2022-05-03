#ifndef DPI_HPP_INCLUDED
#define DPI_HPP_INCLUDED

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

    //given a packet and current time, increase idle time, set next time avail, and change the status to notAvailable

    void dpiStatus (Packet p, double time)
    {
        this.idleTime += (time - this.getTimeNextAvail());

        this.timeNextAvailable = (time + p.getScanTime());

    }

};

#endif // DPI_HPP_INCLUDED