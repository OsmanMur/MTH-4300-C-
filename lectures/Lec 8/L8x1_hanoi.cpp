////////////////////////////////////////////////////////////////////////////////
// Hanoi
// Instructions for solving the Towers of Hanoi, using recursion
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

/* Prints a single instruction for the Towers of Hanoi
   @param d   Number of disk to be moved
   @param f   The character representing the pole being moved from
   @param t   The character representing the pole being moved to
*/
void print(int d, char f, char t) {
	cout << "Move disk " << d << " from pole " << f << " to pole " << t << endl;
}

/* Prints all instructions for the Towers of Hanoi
   @param num_d   Number of disks
   @param f       Character representing the pole disks start on
   @param t  	  Character representing the pole where all disks will end
   @param aux     Character representing the remaining pole
*/
void towers(int num_d, char f, char t, char aux) {
   if (num_d == 1){
      print(1,f,t);
      return; // stops the function
   }

   towers(num_d - 1, f, aux, t); //the bottom  disks moved from starting to aux, with target as the aux.

   print(num_d, f, t); // 

   towers(num_d - 1, aux, t, f);


}

int main() {	
   towers(2,'B', 'C', 'A');
	//towers(4, 'A', 'C', 'B');
	return 0;
}
