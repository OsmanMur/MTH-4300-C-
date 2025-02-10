////////////////////////////////////////////////////////////////////////////////
// hw1_q8.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: Osman
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using std::cout; using std::cin; using std::endl; using std::string;  

int main()
{
    string in1,in2;
    string str;

    cout << "Enter an input: ";
    cin >> in1; 

    cout << "Enter an another input: ";
    cin >> in2; 

    for (int i = 0; i < in1.size(); ++i){
            if (in1[i] != in2[i]){ 
                if(str.size() == 0){ 
                    str += in1[i]; // ll 
                }
                else{
                    if(in1[i] != str[0]){ // checks for repeats in the input 
                        str += in1[i];
                    }
                }
        }
    }

    for (int i = 0; i < in2.size(); ++i){
        if(str.size() > 1){ // str[0] cause we only need to compare it one letter 
            cout << "NOT SPIN";
            break; 
        }
        else if( in2[i] == str[0]){
            cout << "NOT SPIN";
            break;
        }
        else{
            cout << "SPIN";
            break;
        }
    }

	
    return 0;
}
