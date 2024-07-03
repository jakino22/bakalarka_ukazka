#include <iostream>
#include "Prefix.h"
#include <fstream>
#include <algorithm>

std::string Prefix::trim(std::string line) {
    std::string newString;
    for (char ch : line)
    {
        if (ch == '\n' || ch == '\r'){
            continue;
        }
        newString += ch;
    }
    return newString;
}

Prefix::Prefix(const std::string& path) {
    std::ifstream infile(path);
    std::string line;
    //meno logiky
    std::getline(infile, line);
    line = trim(line);
    logic_name = line;
    //N
    std::getline(infile, line);
    line = trim(line);
    std::string s;
    std::istringstream prud {line};
    while (prud >> s){
        D.insert(s);
    }
    //unárne operátory
    std::getline(infile, line);
    line = trim(line);
    std::istringstream prud2{ line };
    while (prud2 >> s) {
        unary_ops.push_back(s[0]);
    }
    //binárne operátory
    std::getline(infile, line);
    line = trim(line);
    std::istringstream prud3{ line };
    while (prud3 >> s) {
        binary_ops.push_back(s[0]);
    }
    //prázdny riadok
    std::getline(infile, line);
    line = trim(line);
    //nastavim prefix
    while (std::getline(infile, line)){
        //zadavanie do dictu
        line = trim(line);
        std::istringstream prud {line};
        //n1,n2
        std::string n1;
        std::string n2;
        prud >> s;
        n1 = s;
        prud >> s;
        n2 = s;
        //vysledky operacii
        std::string n3;
        for (auto unary : unary_ops) {
            prud >> s;
            n3 = s;
            handler_map[unary].add(n1, "", n3);
        }
        for (auto binary : binary_ops) {
            prud >> s;
            n3 = s;
            handler_map[binary].add(n1, n2, n3);
        }
       
    }
}

std::list<std::tuple<std::string, std::string>> PrefixHandler::evalsTo(std::string a) {
    return dict[a];
}

std::list<std::tuple<std::string, std::string>> Prefix::evalsTo(char c, std::string a) {
    return handler_map[c].evalsTo(a);
}

void PrefixHandler::add(std::string a, std::string b, std::string c) {
    //kontrola duplikatov
    bool found = (std::find(dict[c].begin(), dict[c].end(), std::tuple<std::string, std::string>(a,b)) != dict[c].end());
    if(found){
        return;
    }
    dict[c].push_back(std::tuple<std::string, std::string>(a,b));
}

