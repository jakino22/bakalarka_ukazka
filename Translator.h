#pragma once

#include <sstream>
#include "Prefix.h"
#include "CNF.h"
#include <unordered_set>

class Translator{
public:
    Prefix prefix;
    int id = -1;
    std::map<std::string ,std::string> orignal_formulas;//aby som vedel priradit podformuly/variables k formulam
    std::map<std::string ,std::string> main_formulas;//priradujem variables k formulam len an urovni riadku
    std::set<std::string>newly_generated_vars;//pamatam si nove premenne
    CNF translate(const std::string& pathToCNF, const std::string& pathToDV);
    //truthValues sa pouzivaju ked sa uz neda vnorit hlbsie do formule
    //np je premenna ktora vznikla/sme pouzili pred hlbsim vnorenim
    //line je aktualna formula/podformula
    CNF regular_translate(const std::string& pathToCNF, const std::string& pathToDV);
    void processLine(std::string line, CNF *cnf, std::set<std::string> truthValues, std::string np);
    Translator(const std::string& pathToPrefix);
    static int findMainConnective(const std::string& formula, std::vector<char> binary_ops);
};
