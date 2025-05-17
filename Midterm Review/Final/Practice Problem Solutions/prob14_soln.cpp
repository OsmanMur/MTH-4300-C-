#include <iostream>
#include <vector>

using namespace std;

/***********************SOLUTION************************************/

class Borrowable {
protected:
    string id;
    int quantity;
public:
    Borrowable(string i, int q): id{i}, quantity{q} {}
    
    // NOTE: virtual !!!!!!!!!!!!
    virtual void display() const {
        cout << "Name: " << id << "   Quantity on hand: " << quantity << endl;
    }
    bool borrow() {
        if (quantity < 1) {
            return false;
        }
        --quantity;
        return true;
    }

    // NOTE: this is necessary for part c (or, you could make Library a friend class).
    string getid() {
        return id;
    }
};

class Media: public Borrowable {
protected:
    string medium;
    string genre;
public:
    Media(string i, int q, string m, string g): Borrowable(i, q), medium{m}, genre{g} {}
    void display() const {
        cout << "Name: " << id << "   Quantity on hand: " << quantity << "   Medium: " << medium << "   Genre: " << genre << endl;
    }
};


class Library {
private:
    vector<Borrowable*> items;
public:
    void insert_equip(string i, int q) {
        items.push_back(new Borrowable(i, q));
    }
    void insert_media(string i, int q, string m, string g) {
        items.push_back(new Media(i, q, m, g));
    }
    bool borrow(string i) {
        for(auto it = items.begin();  it != items.end(); ++it) {
            if ((*it)->getid() == i) {
                return (*it)->borrow();
            }
        }
        return false;
    }
    
    void display_all() const {
        for(auto it = items.begin();  it != items.end(); ++it) {
            (*it)->display();
        }
    }

};

/**************************************************************************/


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