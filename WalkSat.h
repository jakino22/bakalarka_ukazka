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


class WalkSat{
public:
    std::map<std::string,std::string>valuation;
    std::vector<std::string> D;
    std::set<std::string>bottom_vars;

    explicit WalkSat(){}

    std::string select_random_element();
    void generate_random_valuation(const std::vector<std::string>&vars);
    std::vector<SignedLiteral>check_if_SAT(const CNF& t);
    std::string Walk(int MaxTries, int MaxChanges, const CNF& t,Translator translator);
};