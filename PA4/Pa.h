#ifndef Pa_H
#define Pa_H

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

struct Word
{
    string word;
    int frequency=1;
    int count=0;
};


class Pa{
    private:
        vector<Word> frequencies={};
        vector<Word> sorted={};
        int encoder[20000]={};
        string decoder[20000]={};

    public:
        Pa(string a);
        void aPa(string a, string b);
        void bPa(string b);
        int hashFunction(string b);
        int hashFunction(int a);
        void insertforencoder();
        void insertfordecoder();
};


#endif