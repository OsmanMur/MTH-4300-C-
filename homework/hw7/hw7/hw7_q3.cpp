////////////////////////////////////////////////////////////////////////////////
// hw7_q3.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: osman
////////////////////////////////////////////////////////////////////////////////

/* 
Write your answers in this comment.

a) The output should be:

        Giraffe
        Okapi
        Camel


b) There would be an error since first it would print "Giraffe", then move two nodes forward (Giraffe -> Okapi -> Camel). 
After Camel, when trying 'current->next->next', it would crash, because Camel's next is nullptr, so 'nullptr->next' is invalid.


*/