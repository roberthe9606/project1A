#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <fstream>
#include <vector>
#include "hashtable.h"

using namespace std;

        HashTable::HashTable(ifstream& fileConstants){
            string line;
            getline(fileConstants,line);
            p = stoi(line);
            getline(fileConstants,line);
            c = stoi(line);
            if(p!=0){
                HashBucket *table;
                table = new HashBucket[p];
            }
        }

        HashTable::~HashTable(){
            for(int i = 0;i < p; i++){
                delete[] table[i].word;
            }
            delete[] table;
        }

        bool check(string* table, string word, int size){
            for(int i = 0; i < size; i++){
                if(table[i].compare(word) == 0){
                    return false;
                }
            }
            return true;

        }


        double HashTable::hash(string s, int c, int p) const{
            int h = 0;

            for(int i = 0; i < s.size(); i++){
                h = h + (char)s[i]*pow(c,i);
            }
            h = h % p;
            return h;
        }


      

        void HashTable::store(ifstream& fileDataset){
            string line;
            int index;

            //if p is 0, then hash table doesn't exist
            /*if(p == 0){
                while(getline(fileDataset,line) && (line.length()>0)){
                    totalNumWordsInput++;
                }
            return;
            }*/

            //first pass - find number of words inputted
            while(getline(fileDataset,line) && (line.length() > 0)){
                index = hash(line);
                //table[index].numWords++;
                totalNumWordsInput++;
            }
            fileDataset.clear();
            fileDataset.seekg(0);

            //second pass - initialize array at each index and add words
            while(getline(fileDataset,line) && (line.length() > 0)){
                index = hash(line);
                if(table[index].word == nullptr){
                    table[index].word = new string[table[index].numWords];
                    table[index].word[0] = line; 
                    totalNumWordsTable++;
                }
                else{
                    for(int i = 0; i < table[index].numWords; i++){
                        //test for duplicates
                        if(table[index].word[i] == line){
                            //no ned to resize array, space negligible
                            table[index].numWords--;
                            break;
                        }
                        //insert if no duplicates found
                        if(table[index].word[i] == ""){
                            table[index].word[i] = line; 
                            totalNumWordsTable++;
                            break;
                        }
                    }
                }
            }

            //third pass - find the index of hashbucket with the most collisions
                for(index = 0; index < p; index++){
                    if((table[index].numWords) > maxCollisions){
                        maxCollisions = table[index].numWords;
                        indexMax = index;
                    }
                }
                if(maxCollisions != 0){
                    maxCollisions--;
                }
        }

        void HashTable::print() const{
            cout << "Size of input: " <<  totalNumWordsInput << endl;
            cout << "Number of words in table: " << totalNumWordsTable << endl;
            cout << "Primary array size: " << p << endl;
            cout << "Maximum number of collisions in a hashbucket: " << maxCollisions << endl;
            cout << "The number of hashbuckets b with x elements:" << endl;

            int b = 0;
            for(int i = 0; i < 21; i++){
                for(int j = 0; j < p; j++){
                    if(table[j].numWords == i){
                        b++;
                    }
                }
                cout << "x= " << i << " : b=" << b << endl;
            }
            cout << "Keys in most populated bucket:";
            if(p == 0 || totalNumWordsTable == 0){
                return;
            }
            for(int i = 0; i < table[indexMax].numWords; i++){
                cout << " " <<  table[indexMax].word[i];
            }
        }



        bool find(string* table, string key, int c, int p, long* sizeTable){
            int index = hash(key, c, p);
            for(int i = 0; i < sizeTable[index]; i++){
                if(key.compare(table[index][i]) == 0){
                    cout << "Key \"" << key << "\" exists at (" << index << ", " << i << ")." << endl;
                    return true;
                }
            }
            cout << "Key \"" << key << "\" does not exist " << endl;
            return false;
        }
/*
        void HashTable::query(ifstream& fileQuery) const{
            string line;
            int index;

            cout << "Queries" << endl;

            while (getline(fileQuery,line) && (line.length() > 0)){
                if(p == 0){
                    cout << "Key \"" << line << "\" does not exist " << endl;
                }
                index = hash(line);
                for(int i = 0; i < table[index].numWords; i++){
                    if(table[index].word[i] == line){
                        cout << "Key \"" << line << "\" exists at (" << index << ", " << i << ")." << endl;
                    }
                }
            }
            //cout << "Key " << line << "does not exist." << endl;
        }
*/