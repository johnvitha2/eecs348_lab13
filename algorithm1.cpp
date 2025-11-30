#include <iostream>
#include <vector>
using namespace std;

bool fail_lecture(const std::vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 1; i < attendance_records.size(); ++i) {
        absent_count += (attendance_records[i] == 0);
    }
    return absent_count >= 3;
}

string tf(bool output) {
    return output ? "True" : "False";
}

void run_test(const vector<int>& attendance_records, bool expected, const string& question) {
    bool actual = fail_lecture(attendance_records);
    cout << question << endl;
    cout << "Test case: ";
    for (int attendance : attendance_records) cout << attendance << " ";
    cout << endl;
    cout << "Expected Output: " << tf(expected) << endl;
    cout << "Actual Output:   " << tf(actual) << endl << endl;
}

int main(){
    /*
    * 1. Is there a fault in the program? If so, locate it and explain. 
    * Yes, there is a fault at line 3 with the for-loop’s indexing. In C++, vector indices begin at 0, so the for loop starts 
    * at the second element of the vector (i=1), when it should start at the first element (i=0) to execute as intended. 
    */
    run_test({1, 1, 0, 1, 1, 0, 1, 1, 1, 1}, false, "2. Define a test case that does not execute the fault. ");
    /*
    * 3. Define a test case that executes the fault but does not result in an error state.
    * There is no test case that executes the fault but does not result in an error state. If the fault is executed 
    * (the student is absent on the first day), the absent count will always be one less than expected. Even if the program's 
    * output is correct, an error state occurs because the software has entered an incorrect internal state.  
    */
    run_test({0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, false, "4. Define a test case that results in an error state but not a failure. ");
    run_test({0, 0, 0, 1, 1, 1, 1, 1, 1, 1}, true, "5. Define a test case that results in failure. ");
}
