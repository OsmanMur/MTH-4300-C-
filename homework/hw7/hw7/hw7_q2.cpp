////////////////////////////////////////////////////////////////////////////////
// hw7_q2.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: osman
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string; using std::vector;

int main() {
	vector <string> guest_list = {"Alice", "Bob", "ADD3", "Carol", "David", "ADD3", "Evan"}; // CONTENTS MAY 
                                                                                                      // CHANGE
	vector <string> vips = {"Jane", "Kevin", "Larry", "Marcus", "Nancy"}; // CONTENTS MAY CHANGE
    //
    // Your code here
    //
    

    int vip_idx = 0;

    for (int i=0; i< guest_list.size(); ++i){
        if (guest_list[i] == "ADD3"){
            guest_list.erase(guest_list.begin() + i);
        

            int count = 0;
            while (count < 3 && vip_idx < vips.size()) {
                guest_list.insert(guest_list.begin() + i + count, vips[vip_idx]);
                vip_idx += 1;
                count += 1;
            }

            i += count - 1; 
        }
    }

    for(int i = 0; i < guest_list.size(); ++i){
        cout << guest_list[i] << " ";
    }
    
}

    





