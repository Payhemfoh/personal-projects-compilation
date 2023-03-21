#include <iostream>
#include <ctime>

int main(){
  using namespace std;
  
  const int SIZE = 128;
  time_t currentTime;
  char timeString[SIZE];
  tm* local = new tm;
  
  //get current time
  time(&currentTime);
  localtime_s(local,&currentTime);
  
  //convert current time into string and save into timeString
  strftime(timeString,SIZE,"Current timeL %F,%A,%r", local);
  
  cout<<timeString<<endl;
  
  return 0;
 }
