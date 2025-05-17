////////////////////////////////////////////////////////////////////////////////
// Riddle
// Why does "Calling fn" print out twice (maybe) when the x.fn() is called 
// four times?
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

class GarbageArray{
public:
    int *arr;
    GarbageArray() {arr = new int[10];}
    ~GarbageArray() {delete[] arr;}
    GarbageArray fn();
};

GarbageArray GarbageArray::fn(){
    cout << "Calling fn" << endl;
    return *this;   
}

int main() {
    GarbageArray x;
    x.fn(); 
    x.fn();
    x.fn(); 
    x.fn();
    return 0;  
}













































// Answer: the first call to `x.fn()` returns a COPY of *this.  
// Since we have the default copy constructor, this copy will have its `.arr` array shared with `x`
// Since the line `x.fn();` does nothing with the return value, the return value goes out of scope immediately
//   -- that means the destructor gets called, and so the shared array gets deleted! 
//
// Then, `x.fn();` gets called again, and the process repeats -- except that this time, when delete[] gets called,
// there IS NO ARRAY LEFT TO BE DEALLOCATED.  Hence, error.
