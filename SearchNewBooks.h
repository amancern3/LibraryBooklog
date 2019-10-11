//
// Created by aman842 on 10/3/19.
//

#ifndef P1_PHASE_SEARCHNEWBOOKS_H
#define P1_PHASE_SEARCHNEWBOOKS_H

#include <iostream>
#include <chrono>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <string.h>

using namespace std ;

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

    bool operator < (const book& obj) const {
      if (ISNB < obj.ISNB) {
        return (ISNB < obj.ISNB);
      } else if (ISNB == obj.ISNB) {
        return (language.compare(obj.language));
      } else
        return type.compare(obj.type);

    }


    int isnb_no () {
        return  ISNB ;
    }

    std::string lang () {
        return language;
    }

    std::string type_def () {
        return type ;
    }

    book (int no, std::string& lang, std::string &condition) {
        ISNB = no;
        language = lang ;
        type = condition ;
    }

    ~book() {

    }

    void  new_obj (int& no, std::string& lang, std::string &condition) {
        ISNB = no;
        language = lang ;
        type = condition ;
    }

};

class ct {

    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end ;
public:
    void Reset () {
        start = std::chrono::high_resolution_clock::now() ;
    }

    double CurrentTime() {
         end = std::chrono::high_resolution_clock::now() ;
         double elapsed_us = std::chrono::duration<double , std::micro>(end - start).count() ;
        return  elapsed_us ;
    }

};
std::vector<std::string> split(std::string str,std::string sep) ;

int bsearch(vector<book> vector, int i, int size, book basicString) ;
void vectorize_file (std::string const filename , std::vector<book>& input) ;
int linear_search(std::vector<book>& newbooks, std::vector<book>& request);
void writetofile(int count, std::string file) ;
int binary_search(std::vector<book>& newbooks, std::vector<book>& request) ;
#endif //P1_PHASE_SEARCHNEWBOOKS_H
