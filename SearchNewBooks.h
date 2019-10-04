//
// Created by aman842 on 10/3/19.
//

#ifndef P1_PHASE_SEARCHNEWBOOKS_H
#define P1_PHASE_SEARCHNEWBOOKS_H

#include <iostream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <fstream>

class book {
private:
    int ISNB;
    std::string language ;
    std::string type ;

    // constructor, use 'new' each time a eol is reached.
public:
    book () {
        ISNB = 0 ;
        language = "" ;
        type = "" ;
    }
    book (int no, std::string& lang, std::string &condition) {
        ISNB = no;
        language = lang ;
        type = condition ;
    }

    ~book() {

    }

    void new_obj (int no, std::string& lang, std::string &condition) {
        book (no, lang, condition) ;
    }

};


void vectorize_file (std::string filename , std::vector<book>& input) ;
void linear_search(std::vector<book>& newbooks, std::vector<book>& request);
void binary_search(std::vector<book>& newbooks, std::vector<book>& request) ;
#endif //P1_PHASE_SEARCHNEWBOOKS_H
