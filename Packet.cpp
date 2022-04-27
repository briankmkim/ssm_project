#include <string>

class Packet{

public:
    float entryTime;
    float timeout;
    float scanTime;
    float timeProcessed;

    Packet(float e, float t, float s){
        entryTime = e;
        timeout = t;
        scanTime = s;
    }

    Packet(float e, float t, float s, float p){
        entryTime = e;
        timeout = t;
        scanTime = s;
        timeProcessed = p;
    }

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
};