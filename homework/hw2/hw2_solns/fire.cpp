////////////////////////////////////////////////////////////////////////////////
// fire.cpp
////////////////////////////////////////////////////////////////////////////////
// Name:
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <random>

using std::cout; using std::cin; using std::endl;

// Variables which are declared outside of any function are said to be GLOBAL.
// This means that they will be usable both in main(), as well as any other functions 
// that you choose to write.
//
// Global variables are frowned upon.  But the variables below don't contain
// important information that is likely to change, so making them global isn't particularly treacherous.
std::random_device ran_dev;
std::mt19937 generator( ran_dev() );
std::uniform_real_distribution<>  dist(0.0, 1.0);

const double PROB_CATCH_FIRE = 0.4;  // The const qualifier prevents these variables from being modified;
const double PROB_BURN_OUT = 0.2;    // any attempt to change them later will cause a compilation error.


/* Simulates a single afternoon in the forest.  The forest[] array gets passed by reference and is updated.
   @param forest    Array representing the state of the forest prior to the afternoon.
*/
void afternoon_update(char forest[]) {
    char morning[12];
    for (int idx = 0; idx <= 11; ++idx){
        morning[idx] = forest[idx];
    }
    for (int site = 1; site <= 10; ++site) {
        bool neighbor_on_fire = (morning[site - 1] == 'F' || morning[site + 1] == 'F');
        bool tree_at_site = morning[site] == 't';
        bool random_element = dist(generator) <= PROB_CATCH_FIRE;
        if (neighbor_on_fire && tree_at_site && random_element) {
            forest[site] = 'F';
        } 
    }
}


/* Simulates a single evening in the forest.  The forest[] array gets passed by reference and is updated.
   @param forest    Array representing the state of the forest prior to the afternoon.
*/
void evening_update(char forest[]) {
    for (int site = 1; site <= 10; ++site) {
        bool site_on_fire = forest[site] == 'F';
        bool random_element = dist(generator) <= PROB_BURN_OUT;
        if (site_on_fire && random_element){
            forest[site] = 'x';
        }
    }
}

/* Checks if at least one site is on fire. 
   @param forest    Array representing the state of the forest prior to the afternoon.
   @return          true if at least one of the 10 sites is on fire.
*/
bool one_on_fire(char forest[]) {
    for(int tree = 1; tree <= 10; ++tree){
        if(forest[tree] == 'F') {
            return true; 
        }
    }
    return false;
}



/* Simulates a single 7-day week in the forest, as described in the problem statement
   @returns   true if there is at least one tree still burning at the end of the week, false otherwise
*/
bool seven_day_sim() {
    char forest[12] = {'x', 't', 't', 't', 't', 'F', 't', 't', 't', 't', 't', 'x'};

    for(int days = 1; days <= 7; ++days) {
        afternoon_update(forest);
        evening_update(forest); 
    }
    return one_on_fire(forest);
}

int main() {
    int TRIALS = 1000000;
    int success = 0;
    for(int i = 1; i <= TRIALS; ++i){
        if (seven_day_sim()){
            ++success;
        }
    }
    cout << success*1.0/TRIALS;
    return 0;
}