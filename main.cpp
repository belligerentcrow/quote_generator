#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include "quoteHeader.h"
using namespace std; 

#define N 5

void splitQuoteInfo(string str, string content[]){
    char delim = '-'; 
    string token; 
    stringstream ss(str); 
     
    short i = 0; 
    while(getline(ss, token, delim)){
        content[i] = token; 
        i++; 
        if(i == 3) break; 
    }
}

int loadQuotes(const string filename, Quote quotelist[]){
    ifstream file; 
    string line; 
    string buff[2]; 

    file.open(filename);
    short num = 0; 
    if(file.is_open()){
        while(getline(file, line)){
           
            splitQuoteInfo(line, buff); 
            Quote q; 
            q = Quote(buff[0], buff[1]); 
            quotelist[num] = q; 
            num++; 
        }
        file.close(); 
    }else{
        cout << "can't open file"<<endl; 
    }
    return num; 
}

void printQuote(Quote thisQuote){
    cout <<endl<< "Today's quote:"<<endl<<endl; 
    cout <<"\t"<< thisQuote.getText() <<endl<<endl;
    cout <<" \t\t\t--"<< thisQuote.getAuthor()<<endl<<endl; 
}



int main(){
    
    int n; 
    srand(time(0)); 
    Quote lista[N];  

    n = loadQuotes("quotesFile.txt", lista); 
   
    int randoNum = rand()%N; 
    printQuote(lista[randoNum]); 
}