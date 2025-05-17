////////////////////////////////////////////////////////////////////////////////
// Mario
// I've written a class definition for a GameCharacter class.  In this example, 
// we get used to this class's interface. 
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;


////////////////////// PLEASE (MOSTLY) IGNORE ALL THIS FOR NOW /////////////////
class GameCharacter {														////
public:																		////
	string name;                       										////
	int lives;                         										////
    int coins;																////
	GameCharacter(): name("Computer Opponent"), lives(3), coins(0) {}		////
	GameCharacter(string s): name(s), lives(3), coins(0) {}					////
    bool game_over() const;													////
	void die(); 															////
    void collect_coins(int);            									////
    void print_info() const;         										////
};																			////
////////////////////// PLEASE (MOSTLY) IGNORE ALL THIS FOR NOW /////////////////

int main () {
	GameCharacter p("Mario");		// This is how you declare a GameCharacter instance that is initialized 
									// with a name.  You should think of it like "int x = 10;"
													
	GameCharacter anon_char;        // This is how you declare a GameCharacter with default initialization (no parentheses).
									// You should think of it like "int x;"
	
	// Each GameCharacter has three member (attribute) variables: .name, .lives, and .coins.
	cout << "p's character name is: " << p.name << endl;
	cout << "anon_char's character name is: " << anon_char.name << endl;
	cout << "p's lives: " << p.lives << endl;
	cout << "p's coins: " << p.coins << endl;
	
	// MEMBER FUNCTIONS (or METHODS) make the code to perform common operations less tedious (and more comprehensible)
	p.print_info();		// You can tell this is a function because of the parentheses at the end!  
	p.die();  			// Oh no!
	p.print_info();		// Let's check in with our player again.

	// NOW, CREATE YOUR OWN GameCharacter; Have your character collect 120 coins; and then print out the character's info.
	
	GameCharacter x("Evan");
	x.collect_coins(120);
	x.print_info();

    return 0;   
}





//////////////// PLEASE (MOSTLY) IGNORE ALL BELOW THIS FOR NOW /////////////////
bool GameCharacter::game_over() const {
	return lives == 0;
}

void GameCharacter::die() {
    --lives;
}

void GameCharacter::collect_coins(int collect) {
    coins += collect;
	lives += (coins/100);
	coins %= 100;   // Fun fact: just like there is += and -=, there is %=.
}

void GameCharacter::print_info() const {
    cout << name << " has " << lives << " lives and " << coins << " coins." << endl;   
}



