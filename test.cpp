#include <iostream>
#include <string>
#include <regex>
#include <vector>
using namespace std;

class filter{
public:
    filter(regex expression,string text,int type):expression(expression),text(text),type(type){
        
    }
    
    regex expression;
    string text;
    int type;
};
int main(int argc, char **argv){

    string text = "a1 1a if ifelse else ifalivel - + * / +1 12 2 2. 3.4";
    
    vector<filter> filters;
    filters.push_back(filter(regex("if|else|for|do|while|switch|case|continue|break|int|float"),"Reserveda: ",1));
    filters.push_back(filter(regex("\\+|\\-|\\*|\\/"),"Operador: ",2));
    filters.push_back(filter(regex("[a-zA-Z][1-9a-zA-Z]*"),"Variavel: ",3));
    filters.push_back(filter(regex("(\\+|-)?[0-9]+[/.]?[0-9]*"),"Constante Numerica: ",4));
    filters.push_back(filter(regex(".*?"),"Outro: ",0));
   

    istringstream ss(text);
    string token;
    while (getline(ss, token, ' ')) {
       
        for(auto i:filters){
            smatch match;
            if (regex_match (token,match,i.expression)){
                cout << i.text << match.str() << endl;
                break;
            }
        }       
    }
}