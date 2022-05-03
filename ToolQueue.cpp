#include <string>
#include <Packet>
#include <iostream>
#include <queue>

class ToolQueue{

	private:
	const int MAX = 75;

    public:
    int packetsAdded;
    int packetsDropped;
    int packetsProcessed;
    queue<Packet> myStack;

    ToolQueue(){
        packetsAdded = 0;
        packetsDropped = 0;
        packetsProcessed = 0;
        myStack = new queue<Packet>();
    }

    void insert(Packet p){
		if(myStack.size() > MAX) {
			packetsDropped++;
		} else {
        	myStack.push(p);
        	packetsAdded++;
		}
    }

    Packet peek(){
        return myStack.top();
    }

    float nextTime(){
        return myStack.top().timeout;
    }

    Packet nextValidPacket(float currentTime){
        while(!myStack.top().canServicePacket(currentTime)){
            packetsDropped++;
            myStack.pop();
        }
        if(myStack.top() == null){
            return null;
        }else{
            packetsProcessed++;
            Packet temp = myStack.top();
            myStack.pop();
            return temp;
        }
    }
	
	bool isEmpty() {
		return myStack.isEmpty();
	}
}