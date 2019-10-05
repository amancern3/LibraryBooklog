
#include "SearchNewBooks.h"

// phase 1 -- reading in the dataSet

void linear_search(std::vector<book>& newbooks, std::vector<book>& request){

}
void binary_search(std::vector<book>& newbooks, std::vector<book>& request) {

}

// Generic function to read and vectorize each obj created line by line.

// https://stackoverflow.com/questions/3910326/c-read-file-line-by-line-then-split-each-line-using-the-delimiter

void vectorize_file (std::string const filename , std::vector<book> &input) {

    // variables to handle dat files.
    std::ifstream fileIn ( filename );


    if (!fileIn.is_open()) {
        std::cerr << "File type error, cannot be opened\n" ;
        exit (0)  ;
    }

    std::string line ;

    while (fileIn.good()) {
        std::string lang ;
        std:: string cond ;
        std::string isnb = 0  ;

        
    }
 /*   while (std::getline(fileIn, line) ) {
        std::string lang ;
        std:: string cond ;
        int isnb = 0  ;

        std::stringstream linestream(line);

        //std::getline(linestream, isnb, " ")



        std::getline(linestream,lang, ',') ;
        book newObj ;
        newObj.new_obj(isnb, lang, cond) ;
        input.push_back(newObj);
    }*/

    fileIn.close();

}

int main(int argc, char* argv[]) {

    std::vector<book> newbooks ;
    std::vector<book> request ;
    int loop = 1 ;

    char choice ;
    if ( argc < 2 ) {
        std::cerr << "Invalid arguments" << std::endl;
        std::cerr << "Usage: newbooks.dat request.dat ./SearchNewBooks" << std::endl ;
        exit (0) ;
    }

    // ------------
// reading files goes here
// ----------

    vectorize_file (argv[1], newbooks) ;
    vectorize_file (argv[2], request) ;

    //-----------
    //Searching algo
    //------------
std::cout << "Choice of search method ([l]inear, [b]inary)?" << std::endl;
    std::cin >> (choice );

while (loop ) {
    if ( choice == 'l' || choice == 'L') {
        linear_search(newbooks, request);
    }
    else if ( choice == 'B' || choice == 'b') {
        binary_search(newbooks,  request);
    }
    else {
        std::cerr << "Invalid choice, try again ! \n" ;
        loop = 0 ;
    }

} }



