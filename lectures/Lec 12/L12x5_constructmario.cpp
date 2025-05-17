////////////////////////////////////////////////////////////////////////////////
// Constructmario
// The GameCharacter class, revisited, with two constructors
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

class GameCharacter {														
public:																		
	string name;
	int lives; 
    int coins;	
	
	////////////////////// ADD IN TWO CONSTRUCTORS DECLARATIONS
	////////////////////// ONE DEFAULT, ONE WITH ONE STRING PARAMETER
    
	bool game_over() const;	
	void die();
    void collect_coins(int); 
    void print_info() const;  
};


int main () {
	GameCharacter player("Mario");
	GameCharacter anon;

	player.die();
	player.print_info();
	anon.print_info();	
    return 0;   
}

///////////////////// IMPLEMENT TWO CONSTRUCTOR DEFINITIONS


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
