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
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "set.h"
#include "map.h"
#include "error.h"
using namespace std;

/*
 * Function: listPossiblePayments
 * -------------------------------
 * Write a function that takes as input a total amount of money
 * to pay (in dollars) and a set of all the people who ordered
 * something, then lists off every possible way you could split
 * the bill, assuming everyone pays a whole number of dollars.
 */

Set<Map<string,int>> circustance;
int totalNum= 0;
void listPossiblePaymentshelper(int total, Map<string,int>& peopleBill);
void listPossiblePayments(int total, const Set<string>& people) {
    /*creat map to store person and corresponding bill
        basic recursive:total==0
            return map
        recursive:
                map[key] add one
                translate map to recursive function
                */
    Map<string,int> peopleBill;
    for(auto i = people.begin(); i!=people.end(); i++){
        peopleBill[*i] = 0;
    }
    listPossiblePaymentshelper(total, peopleBill);
    cout<<endl<<"total count = "<<totalNum;
}

void listPossiblePaymentshelper(int total, Map<string,int>& peopleBill) {
    if(total < 0 && peopleBill.isEmpty()){
        error("you got a error!please input other numbers");
    } else {
        if(total == 0){
            if(!circustance.contains(peopleBill)){

                cout<<endl;
                for(string n: peopleBill.keys()){
                    cout<<n<<":$"<<peopleBill[n]<<"  ";
                }
                circustance.add(peopleBill);
                totalNum += 1;
            }
        } else {
            for(string n: peopleBill.keys()){
                Map<string,int> peopleBillcopy = peopleBill;
                peopleBillcopy[n] += 1;
                listPossiblePaymentshelper(total-1, peopleBillcopy);
            }
        }

    }

}

/* * * * * Provided Tests Below This Point * * * * */

/*
 * Since this is a void function, we don't have a return value to verify with.
 * We will instead just run your code to make sure there is no obvious error.
 */
PROVIDED_TEST("Provided Test: Run the provided example. There should be 15 entries.") {
    Set<string> s = {"A", "B", "C"};
    listPossiblePayments(4, s);
}
STUDENT_TEST("my test"){
    Set<string> t = {"dongyuhang", "dongchangchun", "chenqun"};
    listPossiblePayments(15, t);
}


