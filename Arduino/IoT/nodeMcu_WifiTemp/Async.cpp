#include "Async.h"

Async::Async(int interval)
	:interval(interval),timer(0)
	{}

void Async::increaseInterval(){
	if(this->timer >= interval){
		this->intervalAction();
		resetInterval();
	}
	else{
		++this->timer;
	}
}

void Async::resetInterval(){
	this->timer = 0;
}