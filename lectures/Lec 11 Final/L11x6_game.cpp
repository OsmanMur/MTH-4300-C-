////////////////////////////////////////////////////////////////////////////////
// Game
// Let's make a game!
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <random>

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
	std::random_device ran_dev;						// REMINDER:
	std::mt19937 gen(ran_dev());					// you generate a random number by,
	std::uniform_int_distribution<> rando(1, 6);	// for example, `x = rando(gen);`
	
		cout << "Enter player's name: ";
	string name;
	cin >> name;
	
	// Create a named character.
	GameCharacter player(name);
	
	// Game loop: random number, update state, print info.
	int num_turns = 0;
	while (!player.game_over()) {
		++num_turns;
		int roll = rando(gen);
		if (roll <= 3) {
			player.die();
		} else if (roll <= 5) {
			player.collect_coins(20);
		} else {
			player.collect_coins(50);
		}
		player.print_info();
	}

	cout << num_turns << " turns.  GAME OVER" << endl;
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
