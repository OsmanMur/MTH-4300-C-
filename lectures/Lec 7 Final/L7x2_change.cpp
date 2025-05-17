////////////////////////////////////////////////////////////////////////////////
// Change
// How many ways are there to make (coin) change for a dollar?
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

/* Get the next lower coin value
   @param coin_value     The value of a coin
   @precondition         `coin_value` is 1, 5, 10, 25, 50, 100
   @returns              The value of the highest coin from the above list that is less than `coin_value`
*/
int next_lower_coin_value (int coin_value) {
    if (coin_value == 100) return 50;   //
    if (coin_value == 50) return 25;    // BTW: look up the switch() statement, if you like.
    if (coin_value == 25) return 10;    //
    if (coin_value == 10) return 5;
    if (coin_value == 5) return 1;
    return -1; // Could be helpful for bug detection.
}

/* The number of ways to make change for `price` using coins of no more than `top_coin_value`
   @param price              A price to make change for
   @param top_coin_value     The highest coin to be used in the configurations
   @precondition             `top_coin_value` is one of 1, 5, 10, 25, 50, 100
   @returns                  Number of ways to make change for `price` using coins of no more than `top_coin_value`
*/
int num_configs(int price, int top_coin_value){
    if (price < 0) {
        return 0;
    }
    if (top_coin_value == 1) {
        return 1;
    }
    
    int at_least_one_top = num_configs(price - top_coin_value, top_coin_value);
    int no_top =  num_configs(price, next_lower_coin_value(top_coin_value));
    return at_least_one_top + no_top;
}

int main() {
	cout << num_configs(100, 100) << endl;
}