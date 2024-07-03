#pragma once

#include <sstream>
#include <map>
#include <list>
#include <tuple>
#include <unordered_set>
#include <set>

class PrefixHandler{
public:
    //handler priraduje pozadovanu vyslednu hodnotu (c) k vsetkym parom hodnot (a,b) ktorych vysledok spojenim pozadovanou
    //spojkou (d) bude adb = c
    std::map<std::string,std::list<std::tuple<std::string, std::string>>>dict;
    //priadnie noveho paru
    void add(std::string a, std::string b, std::string c);
    //ziskanie setu hodnot (b,c) pre pozadovanu hodnotu a
    std::list<std::tuple<std::string, std::string>>evalsTo(std::string a);
};

///graficke zadanie logiky
///priority spojok

class Prefix{
public:
    Prefix() {};
    //namapovanie spojok k handlerom ktore maju informacie o ich spravani
    std::map<std::tuple<char>,PrefixHandler>handler_map;
    std::string logic_name;//meno logiky
    std::set<std::string> D;//set pravidovstnych hodnot nasej logiky
    std::vector<char> unary_ops;
    std::vector<char> binary_ops;
    static std::string trim(std::string);//odstranenie nepotrebnych symbolov z riadku ako napr /n
    //vrati set hodnot (d,e), ktore ked budu spojene spojokou c v tvare dce nadobudnu hodnotu a
    std::list<std::tuple<std::string, std::string>>evalsTo(char c, std::string a);
    Prefix(const std::string& path);
};




