#ifndef TOOL_QUEUE_HEADER
#define TOOL_QUEUE_HEADER
#include <string>
#include <iostream>
#include <queue>

#include "packet.hpp"

using namespace std;

class ToolQueue{

	private:
	const int MAX = 75;
	

    public:
    int packetsDropped;
    // packetsProcessed is moving to each individual DPI tool object
    queue<Packet> myStack;

    ToolQueue(){
        packetsDropped = 0;
    }

    void insert(Packet p){
		if(myStack.size() >= MAX) {
			packetsDropped++;
		} else {
        	myStack.push(p);
		}
    }

	// This is fairly dangerous to the simulation and shouldn't ever be used.
	/*
    Packet peek(){
        return myStack.top();
    }
	*/

    Packet getNextPacket() {
		return myStack.front();
    }

	void popStack() {
		myStack.pop();
	}
	
	bool isEmpty() {
		return myStack.empty();
	}

	int getPacketsDropped() {
		return packetsDropped;
	}
};

#endif
