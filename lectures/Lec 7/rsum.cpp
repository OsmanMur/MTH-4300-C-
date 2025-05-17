#include <iostream>

using std::cout; using std::cin; using std::endl; 


int rsum(int n){
    if (n==1){
        return n;
    }

    return (n + rsum(n-1));

}

int main() {
    cout << rsum(5);

}
