#include "WordLadder.h"
#include <stack>
#include <ostream>
#include <fstream>

WordLadder::WordLadder(const string& data){
    fstream infs;
    string word;
    infs.open(data.c_str());
    if(!infs.is_open()){
        cout << "The file has not been able to open" << endl;
        return;
    }
    while(infs >> word){
        if(word.length()==5){
            dict.push_back(word);
        }
        else{
            cout << "A word is less than or greater than 5 letters" << endl;
            return;
        }
    }
    infs.close();
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile){
    ofstream outFS;
    outFS.open(outputFile);
    
    stack<string> _start;

    _start.push(start);

    queue<stack<string>> first;

    first.push(_start);

    while(!first.empty()){

        string top=first.front().top();
        string tops=top;

        for(list <string>::iterator i=dict.begin(); i!=dict.end();i++){
            for(int a=0; a<=5; a++){

                for(char b='a'; b<='z'; b++){

                    tops[a]=b;

                    if(i->c_str()==tops){
                        stack<string> temp=first.front();
                        temp.push(top);
                        if(end==top){
                            break;
                        }
                        first.push(temp);
                        dict.remove(tops);
                        cout<< tops << endl;
                    }

                }

                tops=top;

            }
        }
        first.pop();

    }
    outFS << first.front().top();
    outFS.close();
    return;
}
