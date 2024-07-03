#pragma once

#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>

//reprezentacia literalu
class SignedLiteral{
public:
    std::set<std::string>S;//set pravdivostnych hodnot ktore musi literal nadobudnut aby platil
    std::string propVariable;//nazov premennej
    SignedLiteral();
    SignedLiteral(std::set<std::string>  nS, std::string  nPropVariable);
    bool equals(const SignedLiteral& s) const; //funkcia na zistenie zhodnosti s inym literalom
};

//reprezentacia klauzuly
class Clause{
public:
    std::vector<SignedLiteral>literals;//vector literalov
    void addLiteral(const SignedLiteral& s);//pridanie literalu do klauzuly
    bool equals(const Clause& nClause);//funkcia na zistenie zhodnosti s inou klauzulov
    std::string vypis();
};

//reprezentacia teorie
class CNF{
public:
    std::vector<std::string>designated_values;//designated values
    std::vector<Clause>clauses;//vector klauzul v teorii
    void vypis();
    void addClause(const Clause& nClause);//pridanie klauzuly do teorie
    void removeClause(const Clause& nClause);//odstranenie klauzuly z teorie
    CNF()= default;
    CNF(CNF const &nt){//kopirovaci konstruktor
        clauses = std::vector<Clause>(nt.clauses);
    }
};
