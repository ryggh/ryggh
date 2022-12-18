/*
 * CS106B Section Handout Test Harness: Section 3
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified for Qt and Ed by Neel
 * Kishnani for Winter 2022.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include <string>
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "set.h"
using namespace std;

/*
 * Function: fewestCoinsFor
 * -------------------------
 * Write a function that takes as input a number of cents and a Set<int>
 * indicating the different denominations of coins used in a country,
 * then returns the minimum number of coins required to make change
 * for that total. In the case of US coins, this should always return
 * the same number as the greedy approach, but in general it might return
 * a lot fewer!
 */
/*
 * solution
 * Given a collection of denominations and an amount to give in change, returns
 * the minimum number of coins required to make change for it.
 *
 * @param cents How many cents we need to give back.
 * @param coins The set of coins we can use.
 * @return The minimum number of coins needed to make change.
 */
int fewestCoinsFor(int cents, const Set<int>& coins){
    if(cents == 0){
        return 0;
    } else {
        int bestSofar = cents + 1;
        for(int coin: coins){
            if(cents - coin >= 0){
                bestSofar = min(bestSofar,fewestCoinsFor(cents - coin, coins));
            }
        }
        return bestSofar + 1;
    }
}

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Verify that the solution works on a simple example and the provided example") {
    Set<int> coins = {50, 25, 10, 5, 1};
    EXPECT_EQUAL(fewestCoinsFor(12, coins), 3);
    // You might want to uncomment this after implementing memoization.
    // EXPECT_EQUAL(fewestCoinsFor(97, coins), 6);
}

STUDENT_TEST("dongyuhang's test"){
    Set<int> coins = {14, 12, 1};
    EXPECT_EQUAL(fewestCoinsFor(24, coins), 2);
}

