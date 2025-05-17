#include <iostream>
#include <vector>

using namespace std;

int main() {   
    Library x;
    x.insert_equip("Hammer", 5);
    x.insert_media("The Room", 1000, "Film", "Masterpiece");
    x.insert_media("A Love Supreme", 1, "Record", "Jazz");
    cout << "Next line should print 1010: " << endl;
    cout << x.borrow("Hammer");
    cout << x.borrow("Ham");
    cout << x.borrow("A Love Supreme");
    cout << x.borrow("A Love Supreme");
    cout << "\nWatch for the media type and genre in lines two and three" << endl;
    x.display_all();
    
}