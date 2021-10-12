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

struct HashBucket{
    int numWords = 0;
    string *word = nullptr;
};

class HashTable{
    public:
        HashTable(ifstream& fileConstants);
        ~HashTable();
        double hash(string s,int c, int p) const;
        void store(ifstream& fileDataset);
        void print() const;
        //void query(ifstream& fileQuery) const;
        bool check(string* table, string word, int size);
        bool find(string** table, string key, int c, int p, long* sizeTable);


 /*       double convert(string s, int n){
            double num;
            stringstream ss;

            ss << s;
            ss >> num;

            return num;
        }*/

 /*       bool is_prime(int n) {
        // Assumes that n is a positive natural number
        // We know 1 is not a prime number
        if (n == 1) {
            return false;
        }

        int i = 2;
        // This will loop from 2 to int(sqrt(x))
        while (i*i <= n) {
            // Check if i divides x without leaving a remainder
            if (n % i == 0) {
                // This means that n has a factor in between 2 and sqrt(n)
                // So it is not a prime number
                return false;
            }
            i += 1;
        }
        // If we did not find any factor in the above loop,
        // then n is a prime number
        return true;
    }
*/
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

        /*int getInt(string s){
            return arr[s];
        }

        string getKey(){
            return key;
        }*/


        /*int hashFunction(int key){
            return key % hashgroups;
        }*/


        
            /*
            for (auto entry : fileDataset){
                i = hashFunction(getInt(entry.getKey()));
                if(isEmpty(arr[i])){
                    arr[i] = entry;
                }
                else{
                    linprob(i,entry);
                }
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
        /*list<pair<int, string>> arr[hashgroups];
        static const int hashgroups;*/
        int p;
        int c;
        int totalNumWordsInput = 0;
        int totalNumWordsTable  = 0;
        int maxCollisions = 0;
        int indexMax;
        HashBucket *table;
        int numWords = 0;
        string *word = nullptr;
        
};
#endif