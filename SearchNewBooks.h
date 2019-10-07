//
// Created by aman842 on 10/3/19.
//

#ifndef P1_PHASE_SEARCHNEWBOOKS_H
#define P1_PHASE_SEARCHNEWBOOKS_H

#include <iostream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <string.h>

using namespace std ;

class book {
private:
    std::string ISNB;
    std::string language ;
    std::string type ;


    // constructor, use 'new' each time a eol is reached.
public:
    book () {
        ISNB = "" ;
        language = "" ;
        type = "" ;
    }

    bool operator < (const book& obj) const {
      if (ISNB < obj.ISNB) {
        return (ISNB < obj.ISNB);
      } else if (ISNB == obj.ISNB) {
        return (language.compare(obj.language));
      } else
        return type.compare(obj.type);

    }


    std::string isnb_no () {
        return  ISNB ;
    }

    std::string lang () {
        return language;
    }

    std::string type_def () {
        return type ;
    }

    book (std::string& no, std::string& lang, std::string &condition) {
        ISNB = no;
        language = lang ;
        type = condition ;
    }

    ~book() {

    }

    void  new_obj (std::string& no, std::string& lang, std::string &condition) {
        ISNB = no;
        language = lang ;
        type = condition ;
    }

};
std::vector<std::string> split(std::string str,std::string sep) ;

bool bsearch(vector<book> vector, int i, int size, string basicString) ;
void vectorize_file (std::string const filename , std::vector<book>& input) ;
int linear_search(std::vector<book>& newbooks, std::vector<book>& request);
int binary_search(std::vector<book>& newbooks, std::vector<book>& request) ;
#endif //P1_PHASE_SEARCHNEWBOOKS_H
