////////////////////////////////////////////////////////////////////////////////
// Private
// Introducing Private Members
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

class GameCharacter {
private:			//  Private 
	int lives; 		//  members
    int coins;		//
public:				
	string name;
	
	GameCharacter();			// Constructors should usually
	GameCharacter(string s);	// be public!
    
	bool game_over() const;	
	void die();
    void collect_coins(int); 
    void print_info() const;  
};


int main () {
	GameCharacter player("Mario");
	
	player.coins = 1500;  	// This is bad behavior -- 
							// the rules say that these coins should be converted to 15 lives.
							// But now, it is also a COMPILER ERROR!!
							// (Since main() is not a member function.)
	return 0;   
}

// References to `lives` and `coins` in all the functions below ARE allowed,
// because these are all definitions of member functions.
GameCharacter::GameCharacter() {
	name = "Computer Player";
	lives = 3;
	coins = 0;
}

GameCharacter::GameCharacter(string s) {
	name = s;
	lives = 3;
	coins = 0;
}

bool GameCharacter::game_over() const {
	return lives == 0;
}

void GameCharacter::die() {
    --lives;
}

void GameCharacter::collect_coins(int collect) {
    coins += collect;
	lives += (coins/100);
	coins %= 100;
}

void GameCharacter::print_info() const {
    cout << name << " has " << lives << " lives and " << coins << " coins." << endl;   
}