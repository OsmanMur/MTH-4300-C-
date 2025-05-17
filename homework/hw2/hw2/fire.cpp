////////////////////////////////////////////////////////////////////////////////
// fire.cpp
////////////////////////////////////////////////////////////////////////////////
// Name:Osman
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <random>

using std::cout; using std::cin; using std::endl;

// Global variables: these variables don't contain
// information that is likely to change, so making them global isn't particularly treacherous.
std::random_device ran_dev;
std::mt19937 generator( ran_dev() );
std::uniform_real_distribution<double> dist(0.0, 1.0);

const double PROB_CATCH_FIRE = 0.4;  // The const qualifier prevents these variables from being modified;
const double PROB_BURN_OUT = 0.2;    // any attempt to change them later will cause a compilation error.

int main() {
    int count = 0;
    char forest50[12]; 

    //50 simulations
    for (int sim = 0; sim < 50; ++sim){
        char forest[12] = {'x', 't', 't', 't', 't', 'F', 't', 't', 't', 't', 't', 'x'};
        //7-day loop
        for (int day = 0; day < 7; ++day) {

            //morning
            char morning[12];  
            for(int i = 0; i < 12; ++i) {
                morning[i] = forest[i];
            }

            //afternoon
            for (int i = 1; i < 11; ++i) { 
                int right = i + 1;
                int left  = i - 1;

                if (morning[i] == 't' && (morning[right] == 'F' || morning[left] == 'F')) {
                    if (dist(generator) <= PROB_CATCH_FIRE) {
                        forest[i] = 'F'; 
                    }
                }
            }

            //evening
            for (int i = 1; i < 11; ++i) { 
                if (forest[i] == 'F') {
                    if (dist(generator) <= PROB_BURN_OUT){
                        forest[i] = 'x';
                    }
                }
            }
        }
         //checks if still on fire.
         for (int i = 1; i < 11; ++i) {
            if (forest[i] == 'F') {
                count +=1; 
                break;
            }
        }
        // if (sim == 49) {  
        //     for (int i = 0; i < 12; ++i) {
        //         forest50[i] = forest[i];
        //     }
        // }
    }
    // cout << "Forest after 7 days (last simulation): "; 
    // for (int i = 0; i < 12; ++i) { 
    //     cout << forest50[i] << " ";  
    // }  
    
    double prob = (count/50.0);
    cout << endl << "The probability is :"  << prob; //I estimate the probability estimate is about 40%  --> (50* 0.8)
    return 0;
}