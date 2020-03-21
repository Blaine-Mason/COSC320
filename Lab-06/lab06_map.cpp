#include <iostream>
#include <set>
#include <map>

#include "d_state.h"

int main(){
  map<string, string>  s;

  s["DE"] = "Dover";
  s["MD"] = "Ocean City";
  s["AZ"] = "FlagStaff";
  s["MI"] = "Detroit";
  s["WA"] = "Seattle";

  string state;

  std::cout << "Enter a state: " << std::endl;
  std::cin >> state;


  map<string, string>::iterator iter;

  iter = s.find(state);
  if(iter != s.end()){
      std::cout << iter->second << std::endl;
  }else{
      std::cout << "State is not found in map" << std::endl;
  }

}


