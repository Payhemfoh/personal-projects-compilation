#include <iostream>
#include <algorithm>
#include <array>

int main(){
  const int SIZE = 7;
  std::array<int, SIZE> numbers;
  
  for(int i=0;i<SIZE;++i){
    cout<<"Enter number:"<<endl;
    cin>>numbers[i];
  }
  
  std::sort(numbers.begin(),numbers.end(),[](int num1,int num2){return num1 > num2;});
  
  std::cout<<numbers[0];
  
  for(int i=1;i<SIZE;++i){
    cout<<","<<numbers[i];
  }
  
  return 0;
}
