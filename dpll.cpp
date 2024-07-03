#include <algorithm>
#include <iostream>
#include "dpll.h"

//u_c = unit  clause, t = theory
CNF DPLL::simplify(const CNF& t,Clause u_c) {
    CNF nt;
    std::string curr_var = u_c.literals.front().propVariable;//nazov premennej v literali v u_c, ktora musi spravidla byt unit clauzula
    std::set<std::string> curr_S = u_c.literals.front().S;//pravdivostne hodnoty uz spomenuteho literalu z u_c

    for(const Clause& c:t.clauses){//postupne prejdem vsetky klauzule v teorii
        bool will_add_clause = true;
        Clause nc;
        for(const SignedLiteral& l:c.literals){// a postupne prejdem vsetky litrale z klauzul
            //v pripade ze sa premenna v literali l zhoduje s premennou v literale v u_c
            if(l.propVariable==curr_var){
                //postupne prejdem vsetky pravidla simplify ako boli spomenute v THE SAT PROBLEM OF SIGNED CNF FORMULAS 4.1
                ///rule 1
                if(std::includes(l.S.begin(),l.S.end(),curr_S.begin(),curr_S.end())){
                    will_add_clause = false;
                    break;
                }
                ///rule 2
                bool will_add_literal = true;
                std::set<std::string>in_S = std::set<std::string>();
                std::set_intersection(l.S.begin(),l.S.end(),curr_S.begin(),curr_S.end(),
                                      std::inserter(in_S,in_S.begin()));//detekcia prieniku
                if(in_S.empty()){
                    will_add_literal = false;
                }
                ///rule 3
                SignedLiteral nl;
                nl.propVariable = l.propVariable;
                nl.S = in_S;
                if (will_add_literal) {
                    nc.addLiteral(nl);
                }

            }else{
                //v pripade ze sa nezhoduju len skontrolujeme ci sa tento literal uz nahodou v klauzule na ktorej podla loopu
                //sme nenachadza, a ak tam este nieje pridame ho tam
                bool match = false;
                for (auto& literal : nc.literals) {
                    if (literal.propVariable == l.propVariable) {
                        match = true;
                        for (const auto& val : l.S) {
                            literal.S.insert(val);
                        }
                    }
                }
                if (!match) {
                    nc.addLiteral(l);
                }
            }
        }
        //ak sa klauzula uz v teorii nachadza (napr z dovodu, ze bola dosledkom rezolvencie uz vytvorena taka klauzula)
        //tak sa do teorie neprida
        if(will_add_clause){
            for(auto cl:nt.clauses){
                if(cl.equals(nc)){
                    continue;
                }
            }
            nt.addClause(nc);
        }
    }
    return nt;
}

bool DPLL::contains_empty_clause(const CNF& t) {
    for(const Clause& c2:t.clauses){
        if(c2.literals.empty()){
            return true;
        }
    }
    return false;
}

bool DPLL::contains_unit_clause(const CNF& t) {
    for(const Clause& c2:t.clauses){
        if(c2.literals.size()==1){
            return true;
        }
    }
    return false;
}

Clause DPLL::returnUnitClause(const CNF& t) {
    //snazim sa vratit prioritne taku unit klauzulu, ktora ma len jednu moznu pravdivostnu hodnotu, ktora
    //teda urcuje aku hodnotu musi premenna s istotou nadobudnut
    Clause ret;
    for(const Clause& c2:t.clauses){
        if(c2.literals.size()==1){
            if(c2.literals.front().S.size()==1){
                return c2;
            }
            ret =  c2;
        }
    }
    return ret;
}

void DPLL::init_vars(CNF t) {
    //inicializujem mapu pre zaznamenavanie ohodnotenia a aj vector bottom_vars, ktory obsahuje len
    //propozicne premenne ktore neboli novo pridane nami v preklade
    evaluation_of_vars = std::map<std::string, std::set<std::string>>();
    bottom_vars = std::vector<std::string>();
    for (const auto& c : t.clauses) {
        for (const auto& l : c.literals) {
            if (evaluation_of_vars.find(l.propVariable) == evaluation_of_vars.end()) {
                evaluation_of_vars[l.propVariable] = D;
                if (translator.newly_generated_vars.find(l.propVariable) == translator.newly_generated_vars.end()) {
                    bottom_vars.push_back(l.propVariable);
                }
            }
        }
    }
}

std::string DPLL::solve(CNF t) {
    if(contains_empty_clause(t)){
        return "UNSAT";
    }
    if(t.clauses.empty()){
        return "SAT";
    }
    init_vars(t);//inicializujem bottom vars a ohodnotenie premennych


    //kazda premenna musi nadobudnut nejaku hodnotu
    for ( const auto &p : bottom_vars )
    {
        Clause c;
        SignedLiteral l;
        l.S=D;
        l.propVariable=p;
        c.addLiteral(l);
        t.addClause(c);
    }
    for ( const auto &p : translator.newly_generated_vars )
    {
        Clause c;
        SignedLiteral l;
        l.S=D;
        l.propVariable=p;
        c.addLiteral(l);
        t.addClause(c);
    }

    //samotny solving
    if(solve_recursively(t)){
        compute_eval(t);
        return "SAT";
    }
    return "UNSAT";
}




/////////////////////////////////////////////////////////

////preddefinviane teorie
////manya hard instances - pidgeon hole 4 - 5
////hustorical examples kapitola

////anton kravec praca - skalovatelnost 
////phase transition








bool DPLL::solve_recursively(const CNF& t) {
    CNF curr_t = CNF(t);

    //aplikujem simplify dokym mozem
    while (contains_unit_clause(curr_t)){
        auto uc = returnUnitClause(curr_t);
        //pozeram ci nenastane konflikt s uz existujucim ohodnotenim a ohodnotenim ktore kaze unit clause
        for(auto val:uc.literals.front().S){
            if(evaluation_of_vars[uc.literals.front().propVariable].find(val)==evaluation_of_vars[uc.literals.front().propVariable].end()){
                return false;
            }
        }

        //volanie simplify
        curr_t = simplify(curr_t,uc);

        if(curr_t.clauses.empty()){
            return true;
        }
        if(contains_empty_clause(curr_t)){
            return false;
        }
    }

    //pri ohodnocovani bude preferovat pouzitie bottom_vars
    std::vector<std::string>variables;
    for(const auto& v:bottom_vars){
        variables.push_back(v);
    }
    for(const auto& v:translator.newly_generated_vars){
        variables.push_back(v);
    }

    //postupne prechadzam variables a postupne im priradzujem hodnoty ktore povoluje evluation_of_vars podla
    //signed branching rule z ld_book 4.1
    for(const auto& v:variables){
            //v pripade, ze uz som danej premennej priradil hodnotu, preskocim ju
            if(visited.find(v)!=visited.end()){
                continue;
            }
            visited.insert(v);
            //priradovanie hodnot pomocou monosigned unit clause
            for(auto i:D){
                SignedLiteral nl;
                nl.S.insert(i);
                Clause nc;
                nl.propVariable = v;
                nc.addLiteral(nl);
                curr_t.addClause(nc);
                std::set<std::string>rec_S;
                rec_S.insert(i);
                //rekurzivne vnorenie
                if(solve_recursively(curr_t)){
                    return true;
                }
                curr_t.removeClause(nc);
            }
            visited.erase(v);
    }
    // v pripade, ze ziadne priradenie nebolo uspokojive, vratime false
    return false;
}

std::string DPLL::setToString(const std::set<std::string>& inputSet) {
    std::ostringstream oss;
    for (const auto& element : inputSet) {
        std::cout << element << " ";
    }
    return oss.str();
}


std::string DPLL::showEval() {
    for(const auto& v:bottom_vars){
        std::cout << v <<" = " << std::endl;
        setToString(evaluation_of_vars[v]);
        std::cout << std::endl;
    }
    return "";
}



bool DPLL::compute_eval(CNF t) {

    int count = 0;//pocitam si kolko premennych uz ma ohodnotenie

    for(const auto& a:bottom_vars){
        //ak ma dana premenna ohodnotenie, preskocim ju a priratam do count
        if(evaluation_of_vars[a].size()==1){
            count++;
            continue;
        }
        for(auto b:D){
            CNF nt(t);
            auto evaluation_of_vars_save = evaluation_of_vars;
            SignedLiteral s;
            s.propVariable = a;
            s.S.insert(b);
            Clause c;
            c.addLiteral(s);
            nt.addClause(c);
            if(solve_recursively(nt)){
                evaluation_of_vars[a].clear();
                evaluation_of_vars[a].insert(b);
                if(compute_eval(nt)){
                    return true;
                }
            }
            evaluation_of_vars = evaluation_of_vars_save;

        }
    }
    //ak maju vsetky ohodnotenie, teda nasiel sa ohodnotenie splnajuce teoriu, vratim true
    if(count==bottom_vars.size()){
        return true;
    }
    return false;

}







