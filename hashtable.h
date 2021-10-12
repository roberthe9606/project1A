#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <fstream>
#include <list>
#include <vector>


using namespace std;

struct Cells{
        unsigned long int numWords = 0;
        string *words = nullptr;   
};

class HashTable {
    public:
        HashTable(ifstream& fileDataset, const long long int prime, const long long con);        
        ~HashTable();
        int hash(string s,int p, int c) const;
        //void store(ifstream& fileDataset);
        void print() const;
        void query(ifstream& fileQuery, int p, int c) const;
 

/*
        bool isEmpty() const{
            int sum = 0;
            for(int i = 0; i < hashgroups; i++){
                sum += arr[i].size();
            }
            if(!sum){
                return true;
            }
            return false;
        }*/

    
        

/*        void linprob(int i, map<string,int> data){
            if(isEmpty(arr[(i+1)%hashgroups])){
                arr[(i+1)%hashgroups] = data;
            }
            else{
                linprob(i+1,data);
            }
        }
*/


    private:
        int totalInput = 0;
        int total  = 0;
        int maxCollisions = 0;
        int indexMax;
        Cells *table;
        long long int p, c;
        vector<string> list;
        

         
        
};
#endif