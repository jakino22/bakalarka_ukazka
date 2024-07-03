#include "CNF.h"
#include <iostream>
#include <utility>

SignedLiteral::SignedLiteral(std::set<std::string> nS, std::string  nPropVariable): S(std::move(nS)),
propVariable(std::move(nPropVariable)) {}

SignedLiteral::SignedLiteral() = default;

void Clause::addLiteral(const SignedLiteral& s) {
    literals.push_back(s);
}

void CNF::addClause(const Clause& nClause) {
    clauses.push_back(nClause);
}

bool SignedLiteral::equals(const SignedLiteral &s) const {
    if(s.S==S && s.propVariable==propVariable){
        return true;
    }
    return false;
}

bool Clause::equals(const Clause &nClause) {
    //ak nemaju rovnaky pocet literalov niesu rovnake
    if(nClause.literals.size()!=literals.size()){
        return false;
    }
    //postupne iterujem cez literaly a hladam zhodu
    bool eq = true;
    for(const auto& nl:nClause.literals){
        bool match = false;
        for(const auto& l:literals){
            if(l.equals(nl)){
                match = true;
            }
        }
        if(!match){
            eq = false;
        }
    }
    return eq;
}

void CNF::removeClause(const Clause &nClause) {
    //postupne prejdem vsetky klauzuly a do teorie pridam len tie ktore sa nezhoduju s pozadovanou klauzulou
    auto clauses2 = std::vector<Clause>(clauses);
    clauses.clear();
    for(auto cl:clauses2){
        if(cl.equals(nClause)){
            continue;
        }
        clauses.push_back(cl);
    }
}

void CNF::vypis() {
    std::string s;
    for(const Clause& a1:clauses){
        s = " ";
        for(const SignedLiteral& a2:a1.literals){
            s.append(a2.propVariable);
            s.append(":{");
            for(auto v:a2.S){
                s.append(v);
                s.append(",");
            }
            s = s.substr(0,s.size()-1);
            s.append("} | ");
        }
        s = s.substr(0,s.size()-3);
        std::cout << s << std::endl;
    }
}


std::string Clause::vypis() {
    std::string s = " ";
    for(const SignedLiteral& a2:literals){
        s.append(a2.propVariable);
        s.append(":{");
        for(auto v:a2.S){
            s.append(v);
            s.append(",");
        }
        s = s.substr(0,s.size()-1);
        s.append("} | ");
    }
    s = s.substr(0,s.size()-3);
    std::cout << s << std::endl;
    return "";
}
