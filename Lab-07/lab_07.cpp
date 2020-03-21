
#include <iostream>
#include <fstream>
#include <string>
#include "d_hashf.h"
#include "d_hash.h"
#include "d_except.h"

void getWord(ifstream& fin, string& w);
int main(){
    int buck = 1373;
    myhash<string, hFstring>htable(buck);

    ifstream sptst ("dict.dat");
    if(sptst.is_open()){
        string wrd;
        for(int i = 0; i < buck; i++){
            sptst >> wrd;
            htable.insert(wrd);
        }
    }else{
        std::cout << "File DNE" << std::endl;
    }

    sptst.close();


    string docName;

    std::cout << "Enter the document name: " << std::endl;
    std::cin >> docName;

    ifstream usrFile (docName + ".txt");

    string usrWrd;
    if(usrFile.is_open()){
        while(!usrFile.eof()){
            
            getWord(usrFile, usrWrd);
            if(htable.end() == htable.find(usrWrd)){
                std::cout << usrWrd << std::endl;
            }
        }
        usrFile.close();
    }else{
        std::cout << "File DNE" << std::endl;
    }


}

//extract a word from fin
void getWord(ifstream& fin, string& w)
{
	char c;

	w = "";	// clear the string of characters

	while (fin.get(c) && !isalpha(c))
		;	// do nothing. just ignore c

	// return on end-of-file
	if (fin.eof())
		return;

	// record first letter of the word
	w += tolower(c);

	// collect letters and digits
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w += tolower(c);

}