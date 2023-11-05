#include "Pa.h"
#include <fstream>

using namespace std;

Pa::Pa(string a){
    fstream inFS;
    inFS.open(a.c_str());
    if(!inFS.is_open()) {
        cout << "couldnt open document" << endl;
        return;
    }
    string temp;
    while(inFS >> temp){
        int c=0, d=1;
        string b;
        if(temp[temp.size()-1]=='.'||temp[temp.size()-1]==','||temp[temp.size()-1]=='?'||temp[temp.size()-1]==':'||temp[temp.size()-1]==';'||temp[temp.size()-1]=='!'||temp[temp.size()-1]=='\''){
            b=temp[temp.size()-1];
            temp.pop_back();
            d=0;
            for(int i=0; i < frequencies.size();i++){
                if(frequencies.at(i).word==b){
                frequencies.at(i).frequency++;
                d=1;
                break;
                }
            }
        }
        for(int i=0; i < frequencies.size();i++){
            if(frequencies.at(i).word==temp){
                frequencies.at(i).frequency++;
                c=1;
                break;
            }
        }
        if(c==0){
            Word a;
            a.word=temp;
            frequencies.push_back(a);
        }
        if(d==0){
            Word a;
            a.word=b;
            frequencies.push_back(a);
        }
    }
    std::sort(frequencies.begin(), frequencies.end(), [](Word a, Word b){
        return a.frequency > b.frequency;
    });

    for(int i=0; i<frequencies.size(); i++){
        frequencies.at(i).count=i+1;
    }
    insertforencoder();
    insertfordecoder();
    inFS.close();
}

void Pa::aPa(string a, string b){
    fstream inFS;
    ofstream oFS;
    
    inFS.open(a.c_str());
    oFS.open(b.c_str());
    
    string temp;
    string ba;
    
    if(!inFS.is_open()) {
        cout << "couldnt open document" << endl;
        return;
    }
    
    if(!oFS.is_open()) {
        cout << "couldnt open document O" << endl;
        return;
    }

    while(inFS >> temp){

        int number=0;
        
        if(temp[temp.size()-1]=='.'||temp[temp.size()-1]==','||temp[temp.size()-1]=='?'||temp[temp.size()-1]==':'
        ||temp[temp.size()-1]==';'||temp[temp.size()-1]=='!'||temp[temp.size()-1]=='\''){
        
            ba=temp[temp.size()-1];
            temp.pop_back();
            number = encoder[hashFunction(temp)];
            oFS << number << " ";
            number = encoder[hashFunction(ba)];
            oFS << number << " ";
        }
        else{
            number = encoder[hashFunction(temp)];
            oFS << number << " ";
        }
    } 
    oFS.close();
}

void Pa::bPa(string b){
    ifstream inFS;
    inFS.open(b.c_str());
    if(!inFS.is_open()) {
        cout << "couldnt open document O" << endl;
        return;
    }

    string a="";
    int temp;
    while(inFS >> temp){
        a = a + decoder[hashFunction(temp)] + " ";
    }
    inFS.clear();
    inFS.close();
    ofstream oFS;
    oFS.open(b.c_str());
    if(!oFS.is_open()) {
        cout << "couldnt open document O" << endl;
        return;
    }
    oFS << a;
    oFS.close();
}

int Pa::hashFunction(string b) {
    int a = 0;

    for(unsigned i = 0; i < b.size(); i++){
        a = a + b[i];
    }
    return a % 20000;
}

int Pa::hashFunction(int a){
    return a%20000;
}

void Pa::insertforencoder(){
    for(int i=0; i<frequencies.size();i++){
        encoder[hashFunction(frequencies.at(i).word)]=frequencies.at(i).count;
    }

}

void Pa::insertfordecoder(){
    for(int i=0; i<frequencies.size(); i++){
        decoder[hashFunction(frequencies.at(i).count)] = frequencies.at(i).word;
    }
}
