//
//  main.cpp
//  tech_questions
//
//  Created by Spencer Moran on 1/27/14.
//  Copyright (c) 2014 USC. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

char firstNonrepeated(string s) {
    map<char, int> nonRepeated;
    for (int i = 0; i < s.length(); i++) {
        if (nonRepeated[s[i]] == 0) {
            nonRepeated[s[i]] = 1;
        }
        else {
            nonRepeated[s[i]] += 1;
        }
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (nonRepeated[s[i]] == 1) {
            return s[i];
        }
    }
    throw "No nonrepeated characters in the string!";
}


int main(int argc, const char * argv[])
{

    cout << firstNonrepeated("racecarr") << endl;
    
    try {
        firstNonrepeated("bbuutt");
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    
    return 0;
}

