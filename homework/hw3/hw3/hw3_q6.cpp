////////////////////////////////////////////////////////////////////////////////
// hw3_q6.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: Osman
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>


using std::cout; using std::cin; using std::endl; using std::string; using std::to_string; using std::ofstream;using std::stoi;
//std::to_string() -> converts int to a string of digits
//std::stoi -> converts strings that look like ints to ints

int main(int argc, char *argv[]) {
    if (argc < 3){
        cout << "There is an error! " << endl;
    }

    else{
        
        string name = argv[1]; // takes the name for the text files
        int num_of_files = stoi(argv[2]); // makes the input into a int
        
        for (int i = 1; i <= num_of_files; ++i) {
            string file_name = name + to_string(i) + ".txt";
            ofstream file(file_name); 
            file.close();
            //cout << file_name << endl;
        }
    }


    return 0;
}