
#ifndef UNTITLED_HASHR_H
#define UNTITLED_HASHR_H
#include <iostream>
#include <stdexcept>
using namespace std;
template <class T>
class hashT {
private :
    T* Htable;
    int * indexStatusList;
    int count;
    int maxSize;
    int HTsize;
public:
    hashT(int size){
        Htable = new T[size];
        indexStatusList = new int[size];
        for(int i = 0 ; i < size ;i++){
            indexStatusList[i] = 0 ;
        }
        count = 0 ;
        maxSize = size;
        HTsize = size;
    }
    ~hashT(){
        delete[] Htable;
        delete[] indexStatusList;
    }
    int hash(int key){
        return key%HTsize;
    }
    int quadraticProbing(int hkey, int index){
        return(hkey + index*index) %HTsize;
    }
    void insert(int key,T value){
        int hindex ;
        hindex = hash(key);
        int i = 0;
        while(indexStatusList[hindex] ==1 && Htable[hindex] != value && count  < maxSize){
            hindex = quadraticProbing(hindex,i);
            i++;
        }
        if(indexStatusList[hindex] != 1 ){
            Htable[hindex] = value;
            indexStatusList[hindex] = 1;
            count++;
        }else if(Htable[hindex] == value){
            cout<<"Already exist"<<endl;
        }else if(maxSize== count){
            cout<<"Table is full"<<endl;
        }
    }
    bool isFound(int key){
        int hindex = hash(key);
        int i = 0;
        while(indexStatusList[hindex] != 0){
            if(indexStatusList[hindex]==1 && Htable[hindex]==key) {
                return true;
            }
            hindex = quadraticProbing(hindex,i);
            i++;

        }
        return false;
    }
    void remove(int key){
        int hindex = hash(key);
        int i = 0;
        while(indexStatusList[hindex] != 0){
            if(indexStatusList[hindex]==1 && Htable[hindex]==key) {
                indexStatusList[hindex] = -1;
                count--;
                return ;
            }
            hindex = quadraticProbing(hindex, i);
            i++;
        }
        throw invalid_argument("Element doesn't exist !");

    }
    void print(){
        for (int i = 0; i < HTsize; i++) {
            if (indexStatusList[i] == 1) {
                cout << "[" << i << "]" << Htable[i] << endl;
            }
        }
    }

};


#endif //UNTITLED_HASHR_H
