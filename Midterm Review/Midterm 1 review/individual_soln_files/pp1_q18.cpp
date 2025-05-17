// Problem 18 
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

/*  Returns a pointer to an array which contains the contents of x twice back-to-back
*/
int* repeat(int x[], int length) {
    int *ret_value = new int[length * 2];
    for (int i = 0; i <= length - 1; ++i) {
        ret_value[i] = x[i];
        ret_value[length + i] = x[i];
    }
    return ret_value;
}

int main() {
    int x[] = {1, 4, 9};
    int *y = repeat(x,3);
    for (int i = 0; i < 6; ++i) {
        cout << y[i] << endl;
    }
}
