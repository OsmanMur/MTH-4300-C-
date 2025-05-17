////////////////////////////////////////////////////////////////////////////////
// Try
// Actually handling our exceptions.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    std::ifstream file;
    while (true) {
        try {
            cout << "Enter file name: ";
            string name;
            cin >> name;

            if (name[0] == '?'){
                throw std::runtime_error("File name cannot start with '?'");
            }
            
            file.open(name);

            // If the file read has failed, we report an invalid name, and ask again.
            if (!file) {
                throw std::runtime_error("Invalid file name");
            }
            break;
        }
        catch(std::invalid_argument x){
            cout << x.what() << endl;
        }

        catch(std::length_error x){
            cout << x.what() << endl;
            cout << "Try again." << endl;
        }
        catch (std::runtime_error x) {
            cout << x.what() << endl;
            cout << "Try again." << endl;
        }
    }
    string first_line;
    std::getline(file, first_line);
    cout << first_line << endl;
    file.close();
}