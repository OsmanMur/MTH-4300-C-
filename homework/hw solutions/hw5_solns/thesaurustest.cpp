////////////////////////////////////////////////////////////////////////////////
// thesaurustest.cpp
////////////////////////////////////////////////////////////////////////////////
// Name:
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <random>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::string;

std::random_device ran_dev;          
std::mt19937 gen(ran_dev());      

class SynGroup {
    int length;
    string words[20];
public:
    SynGroup(): length{0} {}
    SynGroup(string);

    bool has_word(string);
    string replacement(string); 
    void display();
};

SynGroup::SynGroup(string filename) {
    std::ifstream wordfile(filename); 
    // OR, ALTERNATIVE IF THE GROUPFILES ARE IN THE `groupfiles/` FOLDER:
    /*  std::ifstream wordfile("groupfiles/" + filename);  */

    if (!wordfile) {
        cout << "Error:" << filename << endl;
    }
    int i = 0;
    while (i < 20 && std::getline(wordfile, words[i]) ) {
        ++i;
    }
    length = i;
    wordfile.close();
}

bool SynGroup::has_word(string w) {
    for (int i = 0; i < length; ++i) {
        if (words[i] == w) return true;
    }
    return false;
}

string SynGroup::replacement(string w) {
    if (!has_word(w)) {
        return w;
    }
    std::uniform_int_distribution<> distr(0, length-1);
    string choice;
    do {
        choice = words[distr(gen)];
    } while(choice == w);
    return choice;
}

void SynGroup::display() {
    for (int i = 0; i < length; ++i) {
        cout << words[i] << endl;
    }
}


class Thesaurus {
    int length;
    SynGroup group_list[50];

public:
    Thesaurus(string []);
    string produce_syn(string);
    void display();
};

Thesaurus::Thesaurus(string filename_list[]) {
    for (int i = 0; i < 50; ++i) {
        group_list[i] = SynGroup(filename_list[i]);
    }
    length = 50;
}

string Thesaurus::produce_syn(string word) {
    for(int i = 0; i < length; ++i) {
        if (group_list[i].has_word(word)) {
            return group_list[i].replacement(word);
        }
    }
    return word;
}

void Thesaurus::display() {
    for (int i = 0; i < length; ++i) {
        group_list[i].display();
    }
}

int main() {
    string list_of_group_files[] = {"approximately.txt", "beloved.txt", "erstwhile.txt", "probable.txt", "night.txt", "proverb.txt", "painting.txt", "publish.txt", "season.txt", "coin.txt", "make.txt", "viable.txt", "bus.txt", "head.txt", "hazard.txt", "attempt.txt", "dirty.txt", "close.txt", "end.txt", "disease.txt", "especial.txt", "produce.txt", "transportation.txt", "bill.txt", "incorporate.txt", "real.txt", "television_receiver.txt", "park.txt", "skin.txt", "quickly.txt", "city.txt", "heed.txt", "center.txt", "excellent.txt", "false.txt", "management.txt", "consequence.txt", "pause.txt", "kernel.txt", "contend.txt", "elementary.txt", "consume.txt", "floor.txt", "talk.txt", "classify.txt", "dwelling.txt", "acme.txt", "bit.txt", "minor.txt", "package.txt"};
    Thesaurus whole_thes(list_of_group_files);

    cout << "The following print out should display lots of words, from \"approximately\" to \"parcel\"\n";
    whole_thes.display();

    cout << "The following should print either \"bill\" or \"invoice\":\n" << whole_thes.produce_syn("account") << endl;
    cout << "The following should print either \"pause\", \"break\", \"interruption\", or \"suspension\":\n" << whole_thes.produce_syn("intermission") << endl;
    cout << "The following should print either \"nochange\":\n" << whole_thes.produce_syn("nochange");

    return 0;
}

