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

    //Open the file to take in data
    ifstream sptst ("dict.dat");
    if(sptst.is_open()){
        ///temp string to hold current word
        string wrd;
        //insert the word into the hash table 
        for(int i = 0; i < 25025; i++){
            sptst >> wrd;
            htable.insert(wrd);
            //std::cout << wrd << std::endl;
        }
    }else{
        //The file was not found
        std::cout << "File DNE" << std::endl;
    }
    //close the file
    sptst.close();

    //hols the name of the document to be opened
    string docName;

    std::cout << "Enter the document name: " << std::endl;
    std::cin >> docName;

    //opens the file to be read
    ifstream usrFile (docName + ".txt");

    string usrWrd;
    if(usrFile.is_open()){
        //until the file has reached the end
        while(!usrFile.eof()){
            //use the getword function
            getWord(usrFile, usrWrd);
            //if the word is not found, the end is returned
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