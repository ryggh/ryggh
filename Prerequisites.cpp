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
using namespace std;

/*
 * Function: listLegalOrderingsOf
 * -------------------------------
 * Write a function that takes as input a Map representing the
 * prerequisite structure, then lists all possible orders in which
 * you could complete those tasks without violating the
 * prerequisites. The prereqs map is structured so that each key
 * is a task and each value is the set of that task’s immediate prerequisites.
 * See section handout for more details
 */
int amount = 0;
void listLegalOrderingsOfhelper(const Map<string, Set<string>>& prereqs, Set<string>& storeTask){
    if(prereqs.size() == storeTask.size()){
        cout<<endl<<storeTask;
        amount++;
    }
    for(string task: prereqs.keys()){
        if(prereqs[task].isSubsetOf(storeTask) && !storeTask.contains(task)){
                Set<string> temp = storeTask;
                temp.add(task);
                listLegalOrderingsOfhelper(prereqs, temp);
            }
    }
}
void listLegalOrderingsOf(const Map<string, Set<string>>& prereqs) {
    Set<string> storeTask;
    listLegalOrderingsOfhelper(prereqs, storeTask);
    cout<<endl<<"total = "<<amount;
}
/*void listLegalOrderingsRec(const Map<string, Set<string>>& prereqs,
                              const Vector<string>& tasksPerformed,
                              const Set<string>& tasksRemaining) {
       /* Base case: If there are no remaining tasks, output this as one possible
       * option.
       */
/*      if (tasksRemaining.isEmpty()) {
           cout << tasksPerformed << endl;
           return;
       }

       /* Otherwise, try adding in as a possible next task all tasks that have had
       * all their prerequisites satisfied.
       */

       /* For convenience, convert the vector of tasks into a set. */
 /*      Set<string> tasksDone;
       for (string task: tasksPerformed) {
           tasksDone += task;
       }

       for (string task: tasksRemaining) {
           if (prereqs[task].isSubsetOf(tasksDone)) {
               Vector<string> newTasks = tasksPerformed;
               newTasks += task;
               listLegalOrderingsRec(prereqs, newTasks, tasksRemaining - task);
           }
       }
   }

   void listLegalOrderingsOf(const Map<string, Set<string>>& prereqs) {
       Set<string> tasks;
       for (string task: prereqs) {
           tasks.add(task);
       }
       listLegalOrderingsRec(prereqs, {}, tasks);
   }


/* * * * * Provided Tests Below This Point * * * * */

/*
 * Since this is a void function, we don't have a return value to verify with.
 * We will instead just run your code to make sure there is no obvious error.
 */
PROVIDED_TEST("Provided Test: Run the provided example. There should be 16 entries.") {
    Map<string, Set<string>> prereqs = {
        {"CS103", { "CS106A" }},
        {"CS106A", { }},
        {"CS106B", { "CS106A" }},
        {"CS107", { "CS106B" }},
        {"CS109", { "CS103", "CS106B" }},
        {"CS110", { "CS107" }},
        {"CS161", { "CS109" }}
    };
    listLegalOrderingsOf(prereqs);
}
