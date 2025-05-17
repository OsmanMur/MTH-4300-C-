////////////////////////////////////////////////////////////////////////////////
// hw4_q6.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

/* Return the number of words in the string `total`
   @param total     A string to be split
   @returns         The number of words in `total`
*/
int num_words(const string &total) {    // PASSING BY REFERENCE FOR EFFICIENCY'S SAKE
    int count_words = 0;
    for (int idx = 0; idx < total.size(); ++idx) {
        char prev_char, current_char = total[idx];
        if (idx == 0) {
            prev_char = ' ';  // If we're at the beginning, there is no previous character
        } else {
            prev_char = total[idx - 1];
        }

        bool new_word_beginning = (prev_char == ' ') && (current_char != ' ');
        if (new_word_beginning) { 
            ++count_words;
        }
    }
    return count_words;
}


/* Return a pointer to an array containing the words in the string `total`
   @param total     A string to be split
   @returns         A pointer to an array of words in `total`
*/
string* split(const string &total) {
    string *return_ptr = new string[num_words(total)];
    
    int word_idx = -1; // Which entry in the array of words are we currently writing to?
    int start_pos; // Index in total of the first character of the current word
    int word_length;  // Length of the current word

    for (int idx = 0; idx < 1 + total.size(); ++idx) {
        // To deal with the case where the last character may or may not be a space,
        // we pretend that there is an extra space character after the end of `total`
        char prev_char, current_char;
        if (idx == 0) {
            prev_char = ' ';  // If we're at the beginning, there is no previous character
            current_char = total[idx];
        } else if (idx == total.size()) {
            prev_char = total[idx - 1];
            current_char = ' '; // If we're one past the end, there is no current character
        } else {
            prev_char = total[idx - 1];
            current_char = total[idx];
        }

        bool new_word_beginning = (prev_char == ' ') && (current_char != ' ');
        bool word_ending = (prev_char != ' ') && (current_char == ' ');

        if (new_word_beginning) {
            start_pos = idx;
            word_length = 1;
            ++word_idx;
        } else if (word_ending) {
            return_ptr[word_idx] = total.substr(start_pos, word_length);
        } else {
            ++word_length;
        }
    }
    return return_ptr;
}



int main(){
    string sp = "   spaces.at    the  ,  end    ";
    cout << "Num words in sp = " << num_words(sp) << endl;

    string *arrsp = split(sp);
    for (int i = 0; i < 4; ++i) {
        cout << "arrsp[" << i << "] = " << arrsp[i] << endl;
    }

    string qmark = "is_there   a question_mark   attheendofthe lastword?";
    cout << "Num words in qmark = " << num_words(qmark) << endl;

    string *arrq = split(qmark);
    for (int i = 0; i < 5; ++i) {
        cout << "arrq[" << i << "] = " << arrq[i] << endl;
    }

    return 0;
}