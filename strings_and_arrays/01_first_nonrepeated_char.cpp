//
//  main.cpp
//  tech_questions
//
//  Created by Spencer Moran on 1/27/14.
//  Copyright (c) 2014 USC. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

char firstNonrepeated(string s) {
    set<char> nonRepeated;
    for (int i = 0; i < s.length(); i++) {
        if (nonRepeated.count(s[i]) == 0) {
            nonRepeated.insert(s[i]);
        }
        else {
            nonRepeated.erase(s[i]);
        }
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (nonRepeated.count(s[i]) != 0) {
            return s[i];
        }
    }
    throw "No nonrepeated characters in the string!";
}


int main(int argc, const char * argv[])
{

    cout << firstNonrepeated("racecar") << endl;
    
    try {
        firstNonrepeated("bbuutt");
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    
    return 0;
}

