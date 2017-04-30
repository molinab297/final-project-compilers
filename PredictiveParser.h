#ifndef FINAL_PROJECT_COMPILERS_PREDICTIVEPARSER_H
#define FINAL_PROJECT_COMPILERS_PREDICTIVEPARSER_H
#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <unordered_map>
using namespace std;


class PredictiveParser {
public:
    PredictiveParser(int rows, int columns, string terminalsFileName, string nonterminalsFileName, string parsingTableName);
    ~PredictiveParser();
    bool validateCode(string codeFileName);

private:
    void loadGrammarDict(string charFileName);
    void loadTable(string parsingTableFileName);
    bool trace(string inputString);
    int getState(char c){
        if(grammarDict.find(c) == grammarDict.end()){
            cout << c;
        }
        else{
            return grammarDict.at(c);
        }
    }

    string **table;
    int rows;
    int columns;
    std::unordered_map<char,int> grammarDict;
};


#endif //FINAL_PROJECT_COMPILERS_PREDICTIVEPARSER_H
