#include <iostream>
#include <fstream>
#include <string>
#include "hashtable.h"
using namespace std;

int main(int argv, char** argc){
    if((argv != 3) && (argv != 4)){
        cout << "Please provide 2 to 3 file names" << endl;
        return 1;
    }
    ifstream fileConstants (argc[1]);
    ifstream fileDataset (argc[2]);
    ifstream fileQuery;
    if(fileConstants.fail()){
        cout << "Couldn't open file" << argc[1] <<  endl;
        return 1;
    }
    if(fileDataset.fail()){
        cout << "Couldn't open file" << argc[2] << endl;
        return 1;
    }
    if(argv == 4){
        fileQuery.open(argc[3]);
        if(fileQuery.fail()){
            cout << "Couldn't open file" << argc[3] << endl;
            return 1;
        }
    }

    HashTable h(fileConstants);
    fileConstants.close();

    h.store(fileDataset);
    fileDataset.close();
    
}