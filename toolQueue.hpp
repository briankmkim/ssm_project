#ifndef TOOL_QUEUE_HEADER
#define TOOL_QUEUE_HEADER
#include <string>
#include <Packet>
#include <iostream>
#include <queue>

class ToolQueue{

	private:
	const int MAX = 75;

    public:
    int packetsDropped;
    // packetsProcessed is moving to each individual DPI tool object
    queue<Packet> myStack;

    ToolQueue(){
        packetsAdded = 0;
        packetsDropped = 0;
        myStack = new queue<Packet>();
    }

    void insert(Packet p){
		if(myStack.size() >= MAX) {
			packetsDropped++;
		} else {
        	myStack.push(p);
		}
    }

	// This is fairly dangerous and shouldn't ever be used.
    Packet peek(){
        return myStack.top();
    }

    Packet getNextPacket(float currentTime) {
        if(myStack.isEmpty()){
            return null;
        } else {
            return myStack.pop();
        }
    }
	
	bool isEmpty() {
		return myStack.isEmpty();
	}
}

#endif
