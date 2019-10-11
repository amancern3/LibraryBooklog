#include "SearchNewBooks.h"

// phase 1 -- reading in the dataSet




// function to write output to resulting file

int linear_search(const std::vector<book> newbooks,
    std::vector<book>& request) {
    int count = 0;
    ct clock;
    clock.Reset();

    for (book i : request) {
       // cout << i.isnb_no() << endl ;
        for (book x : newbooks) {
            if (i.isnb_no() == x.isnb_no() &&
            i.lang() == x.lang() && i.type_def() == x.type_def())
                count++;
        }
    }

    cout << count << endl;
    cout << "CPU time: " << clock.CurrentTime() << " ticks"<< endl;
  return count;
}

// helper function to setup the actual binary search algo
int binary_search(std::vector<book> &newbooks, std::vector<book>& request) {
    std::sort(newbooks.begin(), newbooks.end());
    // std::sort(request.begin(), request.end()) ;

    ct clock;
    clock.Reset();
    int count = 0;
  int size = newbooks.size();
    auto pointer = newbooks;
    for (book i : request) {
        count +=countOccurences(pointer, size, i);
        }
cout << count << endl;
    cout << "CPU time: " << clock.CurrentTime() << " ticks" << endl;
  return count;
}
// purpose of this function is to check left and
// right for the same objs and count no of occurences
// assuming if we find one first.
int countOccurences(vector<book> &vector, int size, book obj) {
    auto ind = bsearch(vector, 0, size - 1, obj);
    if (ind == -1)
        return 0;
    int count = 1;
    int left = ind - 1;
    while (left >= 0 && vector[left].isnb_no() == obj.isnb_no()
                        && vector[left].lang() == obj.lang() &&
                        vector[left].type_def() == obj.type_def())
        count++, left--;
    int right = ind + 1;
    while (right <  size && vector[right].isnb_no() == obj.isnb_no()
    && vector[right].lang() == obj.lang() &&
    vector[right].type_def() == obj.type_def())
        count++, right++;
    return count;
}
// Actual function that performs binary search
int bsearch(vector<book> vector, int i, int size, book obj) {
auto result = -1;
    while (size - i >= 0) {
        auto mid = (size - i) / 2 + i;

        if (vector[mid].isnb_no() == obj.isnb_no() &&
        vector[mid].type_def() == obj.type_def() &&
        vector[mid].lang() == obj.lang()) {
            return mid;
        } else if (vector[mid].isnb_no() > obj.isnb_no()) {
            size = mid - 1;
        } else {
            i = mid + 1; } }
    return result;
}
// Generic function to read and vectorize each obj created line by line.

// https://stackoverflow.com/questions/3910326/c-read-file-line-by-line-then-split-each-line-using-the-delimiter
// home/aman842
void vectorize_file(std::string const filename , std::vector<book> &input) {
    // variables to handle dat files.
    std::ifstream fileIn(filename);
    if (!fileIn.is_open()) {
        std::cerr << "Error: cannot open file " << filename <<endl;
        exit(0);
    }
    std::string line;
    while (std::getline(fileIn, line)) {
        // std::cout << line << std::endl;

        std::vector<std::string> result_v;
        result_v = split(line, ",");
        auto  x = stoi(result_v[0]);
        book* newObj = new book (x, result_v[1], result_v[2]);
        input.push_back(*newObj); }
    fileIn.close();
}
// function to parse a lines
std::vector<std::string> split(std::string str, std::string sep) {
    char* cstr = const_cast<char*>(str.c_str());
    char* current;
    std::vector<std::string> arr;
    current = strtok(cstr, sep.c_str());

    while (current != NULL) {
        arr.push_back(current);
        current = strtok(NULL, ","); }
    return arr; }

    int main(int argc, char* argv[]) {
    std::vector<book> newbooks;
    std::vector<book> request;
    int loop = 1;

    if (argc < 3) {
        std::cerr << "Invalid arguments" << std::endl;
        std::cerr << "Usage: .SearchNewBooks <newBooks.dat> "
                     "<request.dat> <result_file.dat>" << std::endl;
        exit(0); }
    vectorize_file(argv[1], newbooks);
    vectorize_file(argv[2], request);
    while (loop) {
    char choice;
    auto count = 0;
    std::cout << "Choice of search method ([l]inear, [b]inary)?" << std::endl;
    std::cin >> (choice);

    if (choice == 'l' || choice == 'L') {
       count = linear_search(newbooks, request);
       writetofile(count, argv[3]);
        exit(0);
    } else if (choice == 'B' || choice == 'b') {
       count = binary_search(newbooks, request);
       writetofile(count, argv[3]);
        exit(0);
    } else {
        std::cerr << "Invalid choice \n";
    }
} }

void writetofile(int count, std::string file) {
    std::ofstream fileOut(file);

    if (!fileOut.is_open())
        std::cerr << "Error: cannot open file " << file << endl;

    fileOut << count;
    fileOut.close(); }