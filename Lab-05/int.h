#ifndef Integer_H
#define Integer_H

class integer
{
	public:
		// constructor. initialize intValue and set count = 1
		integer(int n);

		// return intValue
		int getInt();
		

		// return count
		int getCount();
		

		// increment count
		void incCount();
		

		// compare integer objects by intValue
		friend bool operator< (const integer& lhs, const integer& rhs);

		friend bool operator== (const integer& lhs, const integer& rhs);
		
		// output object in format intValue (count)
		friend ostream& operator<< (ostream& ostr, const integer& obj);
		
	private:
		// the integer and its count
		int intValue;
		int count;
};


#endif 
