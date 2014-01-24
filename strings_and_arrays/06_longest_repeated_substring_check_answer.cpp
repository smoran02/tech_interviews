#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
using namespace std;
#define ll long long
#define PII pair<int, int>
#define PB push_back
#define MP(i, j) make_pair(i, j)
#define inf 1<<30
const int MAX = 1005;
char str[MAX];
int check(int x, int len)
{
    if (x == 0)
        return true;
    string s;
    set<string> SET;
    for (int i = 0; i + x <= len; i++) {
        s = "";
        for (int j = 0; j < x; j++) {
            s += str[i + j];
        }
        if (SET.find(s) != SET.end())
            return i;
        SET.insert(s);
    }
    return -1;
}
int main()
{
    scanf("%s", str);
    int len = strlen(str);
    int l = 0, r = len, mid, start_position = -1;
    while (l < r - 1) {
        mid = (l + r) >> 1;
        int t = check(mid, len);
        if (t != -1) {
            l = mid;
            start_position = t;
        }
        else
            r = mid;
    }
    cout << "lenth = " << l << endl << "start position = " << start_position << endl;
    return 0;
}
