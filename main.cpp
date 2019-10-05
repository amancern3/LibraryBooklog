
#include "SearchNewBooks.h"

// phase 1 -- reading in the dataSet

int linear_search(std::vector<book>& newbooks, std::vector<book>& request){
    int count = 0 ;

    for (book i : request) {
       // cout << i.isnb_no() << endl ;
        for (book x : newbooks) {
            if (i.isnb_no() == x.isnb_no())
                count++ ;
        }
    }

    cout << count << endl ;
}
int binary_search(std::vector<book>& newbooks, std::vector<book>& request) {
    std::sort()
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


    while (std::getline(fileIn, line) ) {
        //std::cout << line << std::endl;

        std::vector<std::string> result_v ;
        result_v = split(line, ",") ;

        book* newObj = new book (result_v[0], result_v[1], result_v[2]) ;
        input.push_back(*newObj) ;

    }

    fileIn.close();
}

std::vector<std::string> split(std::string str,std::string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    std::vector<std::string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

int main(int argc, char* argv[]) {

    std::vector<book> newbooks ;
    std::vector<book> request ;
    int loop = 1 ;

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


while (loop ) {

    char choice ;

    std::cout << "Choice of search method ([l]inear, [b]inary)?" << std::endl;
    std::cin >> (choice );

    if ( choice == 'l' || choice == 'L') {
        linear_search(newbooks, request);
    }
    else if ( choice == 'B' || choice == 'b') {
        binary_search(newbooks,  request);
    }
    else {
        std::cerr << "Invalid choice, try again ! \n" ;
    }

} }



