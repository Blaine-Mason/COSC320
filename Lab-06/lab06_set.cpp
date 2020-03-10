#include <iostream>
#include <set>
#include <map>

#include "d_state.h"

int main(){
  set<stateCity>  s;

  stateCity dovr("DE", "Dover");
  stateCity oc("MD", "Ocean City");
  stateCity flg("AZ", "FlagStaff");
  stateCity det("MI", "Detroit");
  stateCity sea("WA", "Seattle");

  s.insert(dovr);
  s.insert(oc);
  s.insert(flg);
  s.insert(det);
  s.insert(sea);
  

  string state;

  std::cout << "Enter a state: " << std::endl;
  std::cin >> state;
  
  bool not_found = true;

  set<stateCity>::iterator iter;
  for(iter = s.begin(); iter != s.end(); ++iter){
    if(iter->stateName == state){
      std::cout << *iter << std::endl;
      not_found = false;
    }
  }

  if(not_found){
    std::cout << "City not found" << std::endl;
  }

}


