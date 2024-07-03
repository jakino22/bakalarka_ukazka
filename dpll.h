#pragma once

#include <sstream>
#include <utility>
#include <vector>
#include <unordered_set>
#include "CNF.h"
#include <fstream>
#include <utility>
#include <map>
#include "CNF.h"
#include "Translator.h"

class DPLL{
public:
    CNF cnf_CNF;
    Translator translator;
    std::set<std::string>D;
    std::set<std::string>visited;
    std::map<std::string,std::set<std::string>>evaluation_of_vars;
    std::vector<std::string>bottom_vars;
    int nr = 0;
    DPLL(Translator translator) : translator(translator){
        D = translator.prefix.D;
    }
    static CNF simplify(const CNF& t,Clause u_c); //ld-book 4.1 - unit clause bude aj v povodnej teorii, pretoze
    // nejako neovplyvni dosledok rezolvencie, sama seba odstrani

    static bool contains_empty_clause(const CNF& t);//kontrola, ci v teorii mame prazdnu klauzulu

    static bool contains_unit_clause(const CNF& t);//kontrola, ci v teorii mame unit klauzulu

    std::string solve(CNF t);

    bool solve_recursively(const CNF& t);//ld-book 4.1 pre algoritmus

    std::string showEval();//do konzoly vypise ohodnotenie variables

    static Clause returnUnitClause(const CNF& t);//vrati unit clauzulu z teorie

    static std::string  setToString(const std::set<std::string>& inputSet);//pomocka pri vypise

    bool compute_eval(CNF t);

    void init_vars(CNF t);

};