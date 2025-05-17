////////////////////////////////////////////////////////////////////////////////
// hw3_q3.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: Osman
////////////////////////////////////////////////////////////////////////////////

/* 
Write your answers in this comment.

First, y = ++x increments x from 20 to 21 and assigns this new value to y, so y becomes 21. This prints 21.
Next, z = y += 2 increases y by 2, making y equal to 23, and assigns this new value to z, so z also becomes 23. This prints 23.
The if (z = 50) statement contains an assignment, not a comparison. This means z is set to 50, and since 50 is a nonzero value, the condition evaluates to true, so the if block executes.
Inside the if block, it prints the values of x, y, and z. The value of x is 21, which remains unchanged. The expression y++ prints 23, even though y increments to 24 because of post-increment behavior. The value of z is set 50, not checking a condition. Therefore, it prints 21 23 50.

The final output of the program should be:
21
23
21 23 50

*/
