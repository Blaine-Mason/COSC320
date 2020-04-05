#ifndef PROCESSREQUESTRECORD_CLASS
#define PROCESSREQUESTRECORD_CLASS

#include <iostream>
#include <string>

using namespace std;

class procReqRec
{
	public:
		// default constructor
		procReqRec()
		{}

		// constructor
		procReqRec(const string& nm, int p){
			name = nm;
			priority = p;
		}

		// access functions
		int getPriority(){
			return priority;
		}
		string getName(){
			return name;
		}

		// update functions
		void setPriority(int p){
			priority = p;
		}
		void setName(const string& nm){
			name = nm;
		}

		// for maintenance of a minimum priority queue
		friend bool operator< (procReqRec& left,
			 procReqRec& right){
				if (left.getPriority() < right.getPriority()){
					return true;
				}else{
					return false;
				}
			}

		// output a process request record in the format
		//   name: priority
		friend ostream& operator<< (ostream& ostr,
	 procReqRec& obj){
		ostr << obj.getName() << ": " << obj.getPriority() << "\n";
		return ostr;
	}

	private:
		string name;	// process name
		int priority;	// process priority
};

#endif	// PROCESSREQUESTRECORD_CLASS
