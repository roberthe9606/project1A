#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
using namespace std;

struct HashBucket{
    int numWords = 0;
    string listWords;
};

class HashTable{
    public:
        HashTable(ifstream& fileConstants){
            string line;
            getline(fileConstants,line);
            p = stoi(line);
            getline(fileConstants,line);
            c = stoi(line);
            if(p!=0){
                table = new HashBucket(p);
            }
        };

        ~HashTable(){
            for(int i = 0;i < p: i++){
                delete[] table[i].listWords;
            }
            delete[] table;
        }

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

        bool isEmpty() const{
            int sum = 0;
            for(int i = 0; i < hashgroups; i++){
                sum += arr[i].size();
            }
            if(!sum){
                return true;
            }
            return false;
        }

        /*int getInt(string s){
            return arr[s];
        }

        string getKey(){
            return key;
        }*/

        double hash(string s) const{
            int h = 0;
            string a(s);
            vector<char> v(s.begin(),s.end());

            for (int i : v){
                h = (copy(i)*pow(c, x));
            }
            h = h % hashgroups;
            return h;
        }


        /*int hashFunction(int key){
            return key % hashgroups;
        }*/


        void store(ifstream& fileDataset){
            string line;
            int index;

            if(p == 0){
                while(getline(fileDataset,line) && (line.length()>0)){
                    totalNumWordsInput++;
                }
            return;
            }
            while(getline(fileDataset,line) && (line.length() > 0)){
                index = hash(line);
                table[index].numWords++;
                totalNumWordsInput++;
            }
            fileDataset.clear();
            fileDataset.seekg(0);

            while(getline(fileDataset,line) && (line.length() > 0)){
                index = hash(line);
                if(table[index].listWords == nullptr){
                    table[index].listWords = new string(table[index].numWords);
                    table[index].listWords[0] = line;
                    totalNumWordsTable++;
                }
                else{
                    for(int i = 0; i < table[index].numWords; i++){
                        if(table[index].listWords[i] == line){
                            table[index].numWords--;
                            break;
                        }
                        if(table[index].listWords[i] == ""){
                            table[index].listWords[i] == line;
                            totalNumWordsTable++;
                            break;
                        }
                    }
                }
            }
                for(index = 0; index < p; index++){
                    if((table[index].numWords) > maxCollisions){
                        maxCollisions = table[index].numWords;
                        indexMax = index;
                    }
                }
                if(maxCollisions != 0){
                    maxCollisions--;
                }
        
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
        }

/*        void linprob(int i, map<string,int> data){
            if(isEmpty(arr[(i+1)%hashgroups])){
                arr[(i+1)%hashgroups] = data;
            }
            else{
                linprob(i+1,data);
            }
        }
*/
        void print() const{
            cout << "Size of input: " <<  totalNumWordsInput << endl;
            cout << "Number of words in table: " << totalNumWordsTable << endl;
            cout << "Primary array size: "<< p << endl;
            cout << "Maximum number of collisions in a hashbucket: " << maxCollisions << endl;

        }

        void query(ifstream& fileQuery) const{
            string line;
            int index;

            cout << "Queries" << endl;

            while (getline(fileQuery,line) && (line.length() > 0)){
                if(p == 0){
                    cout << "Key" << line << "does not exist " 
                }
                index = hash(line);
                for(int i = 0; i < table[index].numWords; i++){
                    if(table[index].listWords[i] == line){
                        cout << "Key " << line << "exists at (" << index << ", " << i << ")." << endl;
                    }
                }
            }
            cout << "Key " << line << "does not exist." << endl;
        }

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
        
};
#endif