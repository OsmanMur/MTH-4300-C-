////////////////////////////////////////////////////////////////////////////////
// Helper
// Refactoring num_configs(), to make the function have the single parameter
// it deserves.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

// Forward declarations will be helpful here.  We'll put the helper functions below main().
int num_configs(int);
int nc_helper(int, int);
int next_lower_coin_value(int);

/* The number of ways to make change for `price`
   ONE PARAMETER!
   @param price              A price to make change for
   @returns                  Number of ways to make change for `price`
*/
int num_configs(int price){
    // The number of ways to make change for a particular price
    // = the number of ways to make change for that price, with coins <= 100
    return nc_helper(price, 100);
}

int main() {
    // ONE PARAMETER!
	cout << num_configs(100) << endl;
}





/* The number of ways to make change for `price` using coins of no more than `top_coin_value`
   @param price              A price to make change for
   @param top_coin_value     The highest coin to be used in the configurations
   @precondition             `top_coin_value` is one of 1, 5, 10, 25, 50, 100
   @returns                  Number of ways to make change for `price` using coins of no more than `top_coin_value`
*/
int nc_helper(int price, int top_coin_value){
    if (price < 0) {
        return 0;
    }
    if (top_coin_value == 1) {
        return 1;
    }
    int at_least_one_top = nc_helper(price - top_coin_value, top_coin_value);
    int no_top =  nc_helper(price, next_lower_coin_value(top_coin_value));
    return at_least_one_top + no_top;
}




// Look up switch()!  It's kind of nice for this particular type of problem:
// checking which value a variable has.
int next_lower_coin_value (int coin_value) {
    switch(coin_value) {
        case 100: return 50;
        case 50: return 25;
        case 25: return 10;
        case 10: return 5;
        case 5: return 1;
        default: return -1;
    }
}
