#include "rational.h"

int main(){
    // Alternating harmonic series
    Rational ahs(1);
    for(int i = 2; i <= 7; ++i){
        if (i % 2 == 0) {
            ahs -= Rational(1, i);
        } else {
            ahs += Rational(1, i);
        }
    }
    cout << ahs << endl;

    // Approximation of zeta(3)
    Rational term1(1), term2(1,2*2*2), term3(1,3*3*3), term4(1,4*4*4), term5(1,5*5*5);
    term1 += (term2 + term3 + term4 + term5);
    cout << term1 << endl;

    
    // Continued fraction
    Rational cont_frac(1, 8);
    for(int i = 7; i >= 1; --i) {
        cont_frac += i; // A miracle: the int i is getting automatically converted to Rational, by a constructor call!
        cont_frac = 1 / cont_frac;
    }
    cout << cont_frac << endl; 
}
