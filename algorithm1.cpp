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
    cout << question;
    cout << "Test case: ";
    for (int attendance : attendance_records) cout << attendance << " ";
    cout << "Expected Output: " << tf(expected) << endl;
    cout << "Actual Output:   " << tf(actual) << endl << endl;
}