#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "WalkSat.h"


std::string WalkSat::select_random_element() {
    return D.at((rand()%(D.size()-1)));
}

void WalkSat::generate_random_valuation(const std::vector<std::string>&vars) {
    for(const auto& var:vars){
        valuation[var] = select_random_element();
    }
}

std::vector<SignedLiteral> WalkSat::check_if_SAT(const CNF& t) {
    std::vector<SignedLiteral>unsat_literals;//zaznamenavam si unsat literale
    std::vector<SignedLiteral>temp;
    bool wasSat = false;
    for(const Clause& c:t.clauses){
        for(SignedLiteral s:c.literals){
            if(s.S.find(valuation[s.propVariable])==s.S.end()){
                temp.push_back(s);
            } else{
                wasSat = true;
                temp.clear();
                break;
            }
        }
        if(!wasSat){
            for(const auto& literal:temp){
                unsat_literals.push_back(literal);
            }
        }
        wasSat = false;
    }
    return unsat_literals;
}

std::string WalkSat::Walk(int MaxTries, int MaxChanges, const CNF& t,Translator translator) {
    //zapamatanie si vsetkych nie novo vygenerovanych premennych
    bottom_vars = std::set<std::string>();
    for (const auto& c : t.clauses) {
        for (const auto& l : c.literals) {
            if (translator.newly_generated_vars.find(l.propVariable) == translator.newly_generated_vars.end()) {
               bottom_vars.insert(l.propVariable);
            }
        }
    }
    //zapamatanie si pravdivostnych hodnot teorie
    for (auto value : translator.prefix.D) {
        D.push_back(value);
    }
    //zapamatanie si vsetkych premennych
    std::vector<std::string>vars  = std::vector<std::string>();
    for(const auto& c:t.clauses){
        for(const auto& l:c.literals){
            if(std::find(vars.begin(), vars.end(),l.propVariable)==vars.end()){
                vars.push_back(l.propVariable);
            }
        }
    }
    //samotny walksat
    for(int i = 0;i<MaxTries;i++){
        generate_random_valuation(vars);
        for(int j = 0;j<MaxChanges;j++){
            std::vector<SignedLiteral>unsat_literals = check_if_SAT(t);
            if(unsat_literals.empty()){
                return "SAT";
            }
            int index = 0;
            if (unsat_literals.size() > 1) {
                index = (rand() % (unsat_literals.size() - 1));
            }
            SignedLiteral l = unsat_literals.at(index);
            valuation[l.propVariable] = *l.S.begin();
        }
    }
    return "UNSAT";
}