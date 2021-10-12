#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <fstream>
#include <vector>
#include "hashtable.h"

using namespace std;

        HashTable::HashTable(ifstream& fileDataset, const long long int prime, const long long con){
            p = prime;
            c = con;
    
            string line;
            while(getline(fileDataset,line)){
                list.push_back(line);
            }
            table = new Cells[p];

            for (auto& entry:list){
                int index = hash(entry,p,c);
                table[index].numWords++;
                totalInput++;

            }

            int index;
            for(auto& entry:list){
                total++;
                int index = hash(entry,p,c);
                if(table[index].words == nullptr){
                    table[index].words = new string[table[index].numWords];
                    table[index].words[0] = entry;
                }
                //collsions
                else{
                    for(int i = 0; i < table[index].numWords; i++){
                        if(table[index].words[i] == entry){
                            //duplicates
                            table[index].numWords--;
                            break;
                        }
                        if(table[index].words[i] == ""){
                            table[index].words[i] = entry;
                            total++;
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
                /*if(maxCollisions != 0){
                    maxCollisions--;
                }*/
        }





        HashTable::~HashTable(){
            for(int i = 0;i < p; i++){
                delete[] table[i].words;
            }
            delete[] table;
        }



        /*bool check(string* table, string word, int size){
            for(int i = 0; i < size; i++){
                if(table[i].compare(word) == 0){
                    return false;
                }
            }
            return true;

        }

*/






        int HashTable::hash(string s, int p, int c) const{
            long int index = (char)s[0] % p;

            for(int i = 1; i < s.length(); i++){
                index = ((index*c) + (char)s[i]) % p;
            }

            return index % p;
            /*int h = 0;

            for(int i = 0; i < s.size(); i++){
                h = h + (char)s[i]*pow(c,i);
            }
            h = h % p;
            return h;*/
        }


      
















/*

        void HashTable::store(ifstream& fileDataset){
            string line;
            int index;

            //if p is 0, then hash table doesn't exist
            if(p == 0){
                while(getline(fileDataset,line) && (line.length()>0)){
                    totalInput++;
                }
            return;
            }

            //first pass - find number of words inputted
            while(getline(fileDataset,line)){
                index = hash(line);
                table[index].numWords++;
                totalInput++;
            }
            fileDataset.clear();
            fileDataset.seekg(0);

            //second pass - initialize array at each index and add words
            while(getline(fileDataset,line)){
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
        }*/

        void HashTable::print() const{
            cout << "Size of input: " << totalInput << endl;
            cout << "Number of words in table: " << total << endl;
            cout << "Primary array size: " << p << endl;
            cout << "Maximum number of collisions in a hashbucket: " << maxCollisions << endl;
            cout << "The number of hashbuckets b with x elements:" << endl;

            for(int i = 0; i < 21; i++){
                int b = 0;
                for(int j = 0; j < p; j++){
                    if(table[j].numWords == i){
                        b++;
                    }
                }
                cout << "x=" << i << " : b=" << b << endl;
            }
            cout << "Keys in most populated bucket:";
            if(p == 0 || total == 0){
                return;
            }
            for(int i = 0; i < table[indexMax].numWords; i++){
                cout << " " <<  table[indexMax].words[i];
            }
        }

        void HashTable::query(ifstream& fileQuery, int p, int c) const{
            string line;
            int index;


            while (getline(fileQuery,line)){
                index = hash(line, p, c);
                for(int i = 0; i < table[index].numWords; i++){
                    if(table[index].words[i] == line){
                        cout << "Key \"" << line << "\" exists at (" << index << ", " << i << ")." << endl;
                    }
                }
            }
            //cout << "Key " << line << "does not exist." << endl;
        }
        

/*
        bool find(string* table, string key, int c, int p, long* sizeTable){
            int index = hash(key, p, c);
            for(int i = 0; i < sizeTable[index]; i++){
                if(key.compare(table[index][i]) == 0){
                    cout << "Key \"" << key << "\" exists at (" << index << ", " << i << ")." << endl;
                    return true;
                }
            }
            cout << "Key \"" << key << "\" does not exist " << endl;
            return false;
        }

        void HashTable::query(ifstream& fileQuery) const{
            string line;
            int index;


            while (getline(fileQuery,line) && (line.length() > 0)){
                if(p == 0){
                    cout << "Key \"" << line << "\" does not exist " << endl;
                }
                index = hash(line, p, c);
                for(int i = 0; i < table[index].numWords; i++){
                    if(table[index].word[i] == line){
                        cout << "Key \"" << line << "\" exists at (" << index << ", " << i << ")." << endl;
                    }
                }
            }
            //cout << "Key " << line << "does not exist." << endl;
        }
    */