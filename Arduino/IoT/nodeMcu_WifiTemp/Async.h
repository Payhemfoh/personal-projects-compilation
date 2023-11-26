#ifndef Async_H
#define Async_H

/*
A class which used to implement the timer function to allow async operation to be performed
*/
class Async{
  private:
    int interval;
    int timer;
  public:
	Async(int interval);
    void increaseInterval();
    void resetInterval();
    virtual void intervalAction()=0;
};

#endif