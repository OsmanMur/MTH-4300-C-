#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

int main(){
    string str;
    string even;
    string odd;
    
    cout << "enter a word:";
    
    cin >> str;
    
    for(int i= 0;i<str.size();i+=2){
        odd += str[i] ;
    }
    
    cout << "Odd Letters: " << odd << endl;
    
    for (int i=1;i<str.size();i+=2){
        even += str[i] ;
    }
    
    cout << "Even Letters: " << even << endl;
}