// Problem 7
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

class Playlist {
private:
    string files[100];
    int num_entries;
    int current;
public:
    Playlist(): num_entries{0}, current{0} {}
    void add_track(string);
    string current_track() const;
    int length() const;
    void fwd();
};

void Playlist::add_track(string t) {
    if(num_entries < 100) {
        files[num_entries] = t;
        ++num_entries;
    }
}

string Playlist::current_track() const{
    return files[current];
}

int Playlist::length() const{
    return num_entries;
}

void Playlist::fwd(){
    ++current;
    if (current == num_entries) {
        current = 0;
    }
}

int main() {
    Playlist tunes;
    tunes.add_track("mmm_bop.mp3");
    tunes.add_track("what_is_love.mp3");
    tunes.add_track("what_do_i_get.mp3");
    
    bool cake = false;
    for (int i = 0; i < tunes.length(); ++i) {
        if (tunes.current_track() == "mac_arthur_park.mp3") {
            cake = true;
        }
        tunes.fwd();
    }
    if (cake) {
        cout << "Found!";
    } else {
        cout << "Not found";
    }
}
