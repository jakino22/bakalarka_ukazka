#include "Translator.h"
#include "Prefix.h"
#include <fstream>
#include <utility>

Translator::Translator(const std::string& pathToPrefix): prefix(pathToPrefix) {}

CNF Translator::translate(const std::string& pathToCNF, const std::string& pathToDV) {
    std::ifstream infile(pathToCNF);
    std::string line;
    auto *cnf = new CNF();

    std::ifstream inf(pathToDV);
    line;
    std::getline(inf, line);
    std::string num = "";
    for (char c : line) {
        if (c == ',') {
            cnf->designated_values.push_back(num);
            num = "";
        }
        else { num += c; }
    }
    cnf->designated_values.push_back(num);

    while (std::getline(infile, line)){
        //hlavna formula je taka, ktora je napisana priamo na riadku ako celok
        line = Prefix::trim(line); //pripravenie riadku na spracovanie

        std::set<std::string>t; //pravdivostna hodnota kazdej formule musi byt designated value
        for (auto val : cnf->designated_values) {
            t.insert(val);
        }
        if(line.find('(')==std::string::npos && (std::find(prefix.unary_ops.begin(),prefix.unary_ops.end(),line[0]) == prefix.unary_ops.end())){
            main_formulas[line]=line; //zapamatame si hlavnu formulu a kam sa odkazuje v ramci premennej
            continue;
        }
        id++;//pridam index vzdy pred vytvorenim novej premennej
        main_formulas["a"+std::to_string(id)] = line;//zapamatame si hlavnu formulu a kam sa odkazuje v ramci premennej
        newly_generated_vars.insert("a"+std::to_string(id));//v pripade ze musim generovat novu variable si ju zapamatam
        processLine(line,cnf,t,"a"+std::to_string(id));
    }

  

    //povodne formuly musia vsetky platit
    for (auto& main_formula : main_formulas) {
        Clause cl;
        SignedLiteral sl;
        sl.propVariable = main_formula.first;
        for (auto val : cnf->designated_values) {
            sl.S.insert(val);
        }
        cl.addLiteral(sl);
        cnf->addClause(cl);
    }

    return *cnf;
}

void Translator::processLine(std::string line, CNF *cnf, std::set<std::string> truthValues, std::string np) {

    //specialny pripad pre unarnu spojku - negaciu
    if(std::find(prefix.unary_ops.begin(), prefix.unary_ops.end(), line[0])!=prefix.unary_ops.end()){
        char unary = line[0];
        std::string np1;
        line = line.substr(1, line.size() - 1);

        //zistim, ci negujem len var alebo cely vyraz
        if(line.find('(')==std::string::npos){
            np1 = line;
        } else{
            id++;
            np1 = "a"+std::to_string(id);
            newly_generated_vars.insert("a"+std::to_string(id));//v pripade ze musim generovat novu variable si ju zapamatam
        }

        std::set<std::string> values; //budem si znacit hodnoty, ktore bude musiet podformula nadobudnut
        for (std::string truthValue : prefix.D){
            std::list<std::tuple<std::string, std::string>>vals = prefix.evalsTo(unary,truthValue);
            //zapisem implikacie v tvare -a|b, ktore popisuju vztahy medzi danymi premennymi
            for(auto a : vals){

                if (truthValues.find(truthValue)!=truthValues.end()) {
                    values.insert(std::get<0>(a));
                }
                
                std::set<std::string>D1 = prefix.D;
                D1.erase(std::get<0>(a));

                std::set<std::string>t;
                t.insert(truthValue);


                Clause c;
                c.addLiteral(SignedLiteral(D1,np1));
                c.addLiteral(SignedLiteral(t,np));

                cnf->addClause(c);
            }
        }
        //zaznamenam variables/formuly a formuly/podformuly ku ktorym originalne patria
        orignal_formulas[np] = "-"+line;
        orignal_formulas[np1] = line;
        processLine(line,cnf,values,np1);
        return;
    }

    //pre binarnu spojku
    int p = findMainConnective(line.substr(1, line.size() - 2),prefix.binary_ops);
    //v pripade, ze sa vrati nula sa spojka nenasla, a kedze unarnu sme overovali vyssie, musime byt na urovni variable
    //do ktorej sa neda vnorit
    if(p!=0){
        line = line.substr(1, line.size() - 2);//odstranim zatvorky
        std::string np1;
        std::string np2;
        //zistujem ci vytvorim novu variable
        auto b = line.substr(0, p);
        if((line.substr(0,p).find('(')==std::string::npos)&&(std::find(prefix.unary_ops.begin(), prefix.unary_ops.end(), line.substr(0, p)[0]) == prefix.unary_ops.end())){
            np1 = line.substr(0,p);
        } else{
            id++;
            np1 = "a"+std::to_string(id);
            newly_generated_vars.insert("a"+std::to_string(id));//v pripade ze musim generovat novu variable si ju zapamatam
        }
        //zistujem ci vytvorim novu variable
        auto a = line.substr(p + 1, line.length() - p);
        if((line.substr(p+1,line.length()-p).find('(')==std::string::npos) && (std::find(prefix.unary_ops.begin(), prefix.unary_ops.end(), line.substr(p + 1, line.length() - p)[0]) == prefix.unary_ops.end())) {
            np2 = line.substr(p+1,line.length()-p);
        } else{
            id++;
            np2 = "a"+std::to_string(id);
            newly_generated_vars.insert("a"+std::to_string(id));//v pripade ze musim generovat novu variable si ju zapamatam
        }

        std::set<std::string> leftVal;//hodnoty, ktore musi nadobudat lava cast formuly aby platila
        std::set<std::string> rightVal;//hodnoty, ktore musi nadobudat prava cast formuly aby platila
        for (std::string truthValue : prefix.D){
            std::list<std::tuple<std::string, std::string>>vals = prefix.evalsTo(line[p],truthValue);
            //zapisem implikacie v tvare -a|b, ktore popisuju vztahy medzi danymi premennymi
            for(auto a : vals){
                if (truthValues.find(truthValue) != truthValues.end()) {
                    leftVal.insert(std::get<0>(a));
                    rightVal.insert(std::get<1>(a));
                }
                

                std::set<std::string> t;
                t.insert(truthValue);

                // D/a
                std::set<std::string> D1 = prefix.D;
                D1.erase(std::get<0>(a));
                std::set<std::string> D2 = prefix.D;
                D2.erase(std::get<1>(a));

                Clause c;
                c.addLiteral(SignedLiteral(D2,np2));
                c.addLiteral(SignedLiteral(D1,np1));

                c.addLiteral(SignedLiteral(t,np));

                cnf->addClause(c);
            }
        }
        //zaznamenam variables/formuly a formuly/podformuly ku ktorym originalne patria
        orignal_formulas[np1] = line.substr(0,p);
        orignal_formulas[np2] = line.substr(p+1,line.length()-p);
        processLine(line.substr(0,p),cnf,leftVal,np1);
        processLine(line.substr(p+1,line.length()-p),cnf,rightVal,np2);//-1
        return;
    }
    //pre propostitional variable, teda ked som sa dostal na level samotnej premennej a nemozem sa hlbsie vnorit
    Clause c;
    c.addLiteral(SignedLiteral(std::move(truthValues),line));
    cnf->addClause(c);

}




int Translator::findMainConnective(const std::string& formula, std::vector<char> binary_ops) {
    int l = 0;
    int p = 0;
    int index = 0;
 
    //hladam stred medzi zatvorkami teda akoby (())x(), kde x je spojka
    for (char a:formula){
        if(a==')'){p++;}
        if(a=='('){l++;}
        if((p==l)&&(std::find(binary_ops.begin(), binary_ops.end(), a) != binary_ops.end())){return index;}
        index++;
    }
    return 0;
}

CNF Translator::regular_translate(const std::string& pathToCNF, const std::string& pathToDV) {
    //rozdelenie klauzul p:{a,b,c} na p:{a} or p:{b} or p:{c}
    CNF non_regular_cnf = translate(pathToCNF, pathToDV);
    CNF regular_cnf;
    for (const Clause& c : non_regular_cnf.clauses) {
        Clause nC;
        for (const SignedLiteral& l : c.literals) {
            if (l.S.size() > 1) {
                for (const auto& val : l.S) {
                    SignedLiteral nL;
                    nL.propVariable = l.propVariable;
                    nL.S.insert(val);
                    nC.addLiteral(nL);
                }
            }
            else {
                nC.addLiteral(l);
            }
        }
        regular_cnf.addClause(nC);
    }
    return regular_cnf;
}

