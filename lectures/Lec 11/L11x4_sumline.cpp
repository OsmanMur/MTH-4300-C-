////////////////////////////////////////////////////////////////////////////////
// Sumline
// Sum each line
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cout; using std::cin; using std::endl; using std::string;

int main () {
    std::ifstream file("numbers.txt"); 

    string line;
    while(std::getline(file, line)){
        std::stringstream nums; //why? because we want to treat the line as a stream
        nums << line; //load the line into the stringstream

        int runsum = 0;  
        int x;       //variable to store the number   
        while(nums >> x){       //why '>>'? because we want to extract the number from the stringstream
                                //when does this loop stop? when the stringstream is empty
            runsum += x; //add the number to the sum
        }

        cout << runsum <<endl;   //print the sum of the line     
    }

    file.close();
    return 0;
}
