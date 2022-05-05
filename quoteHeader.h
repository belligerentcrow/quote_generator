#include <iostream>
using std::string; 

class Quote{
private:   
    string text; 
    string author;
   
public: 
    Quote(string _t, string _a){
        this->text = _t; 
        this->author = _a; 
        
    }
    Quote(){}; 
    string getText(){
        return this->text; 
    }
    string getAuthor(){
        return this->author; 
    }
    

};