////////////////////////////////////////////////////////////////////////////////
// hw1_q6.cpp
////////////////////////////////////////////////////////////////////////////////
// Name:Osman
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string; 

int main() {

    int count = 0;
   
    int first;
    int second;
    int third;
    
    cout << "Number?: ";
	cin >> first;
    count++;

    while (count != 3) {
		cout << "Number?: ";
		cin >> second;
        if(first==second){
            count++;
            cout << "Number?: ";
		    cin >> third;
            if(first == second && second == third){
                count++;
            }
        }
        else{
            first = second;
            count = 1;
        }
	}
    cout << "Threepeat!";
	return 0;
}