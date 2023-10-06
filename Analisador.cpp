#include <iostream>
#include <string>
#include <regex>
#include <vector>
using namespace std;

class filter{
public:
    filter(string text,regex expression,int type):text(text),expression(expression),type(type){  }
    regex expression;
    string text;
    int type;
};
int main(int argc, char **argv){

    //texto test
    string text = "= a1 1a if ifelse else ifalivel - + * / +1 12 2 2. 3.4";
    
    //criando os padrões
    vector<filter> filters;
    filters.push_back(filter("Reserveda: ",regex("if|else|for|do|while|switch|case|continue|break|int|float"),1));
    filters.push_back(filter("Operador: ",regex("=|\\+|\\-|\\*|\\/"),2));
    filters.push_back(filter("Variavel: ",regex("[a-zA-Z][1-9a-zA-Z]*"),3));
    filters.push_back(filter("Constante Numerica: ",regex("(\\+|-)?[0-9]+[/.]?[0-9]*"),4));
    filters.push_back(filter("Outro: ",regex(".*?"),0));
   

    istringstream ss(text);
    string token;  
    //necessario pre processamento pois separa por espaço
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