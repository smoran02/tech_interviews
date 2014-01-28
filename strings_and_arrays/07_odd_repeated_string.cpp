//
//  07_odd_repeated_string.cpp
//  tech_questions
//
//  Created by Spencer Moran on 1/28/14.
//  Copyright (c) 2014 USC. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

string oddRepeat(string strings[], int length) {
    set<string> oddStrings;
    for (int i = 0; i < length; i++) {
        if (oddStrings.count(strings[i]) == 0) {
            oddStrings.insert(strings[i]);
        }
        else {
            oddStrings.erase(strings[i]);
        }
    }
    
    for (int i = 0; i < length; i++) {
        if (oddStrings.count(strings[i]) != 0) {
            return strings[i];
        }
    }
    throw "No oddly occurring string in the array!";
}


int main() {
    string arr[9] = {"egg", "juice", "apple", "bacon", "bacon", "apple", "apple", "egg", "juice"};
    
    cout << oddRepeat(arr, 9) << endl;
    
    string arr2[10] = {"egg", "juice", "apple", "bacon", "bacon", "apple", "apple", "egg", "juice", "apple"};
    
    try {
        cout << oddRepeat(arr2, 10);
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
}