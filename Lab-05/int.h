#ifndef Integer_H
#define Integer_H

class integer
{
	public:
		// constructor. initialize intValue and set count = 1
		integer(int n){
			intValue = n;
			count = 1;
		}

		// return intValue
		int getInt(){
			return intValue;
		}
		

		// return count
		int getCount(){
			return count;
		}
		

		// increment count
		void incCount(){
			count++;
		}
		

		// compare integer objects by intValue
		friend bool operator< (const integer& lhs, const integer& rhs){
			return lhs.intValue < rhs.intValue;
		}

		friend bool operator== (const integer& lhs, const integer& rhs){
			return lhs.intValue == rhs.intValue;
		}
		
		// output object in format intValue (count)
		friend std::ostream& operator<< (std::ostream& ostr, const integer& obj){
			ostr << obj.intValue << " (" << obj.count << ")";
			return ostr;
		}
		
	private:
		// the integer and its count
		int intValue;
		int count;
};


#endif 
