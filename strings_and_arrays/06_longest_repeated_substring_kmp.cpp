#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define N 1005
char str[N];
int next[N], cnt[N];
//use kmp here
void get_next(char *s, int len)
{
    next[0] = -1;
    int j = -1;
    for (int i = 1; i < len; i++) {
        while (j >= 0 && s[i] != s[j + 1])
            j = next[j];
        if (s[i] == s[j + 1])
            j++;
        next[i] = j;
    }
}
int longestRepeatedString(char *s)
{
    int len = strlen(s);
    int res = 0, x = -1;
    for (int i = 0; i < len; i++) {// enumerate the suffixes starting from i
        // try to find the longest substring with lenth j so that s[i..i + j-1]  = s[x...x + j - 1]
        get_next(s + i, len - i);
        //cout<<endl;
        //for (int k = i; k < len; k++)
            //printf("next[k-i]=%d\n", next[k-i]);
        memset(cnt, 0, sizeof(cnt)); //cnt[t] calculates how many substrings of s  with lenth t, that is also the substring of s[i...len - 1]
        int j = -1;
        for (int k = 0; k < len; k++) {
            while (j >= 0 && s[k] != s[i + j + 1])
                j = next[j];
            if (s[k] == s[i + j + 1])
                j++;
            if (j != -1) {
                cnt[j]++;
            }
            if (j == len - i - 1)
                j = next[j];
        }
        for (j = len - i; j >= 0; j--) {
            if (cnt[j] > 1 && j + 1 > res) {
                res = j + 1;
                x = i;
            }
            if (next[j] != -1)
                cnt[next[j]] += cnt[j];
        }
    }
    cout << "start position = " << x << endl;
    return res;
}
int main()
{
    scanf("%s", str);
    cout << longestRepeatedString(str) << endl;
    return 0;
}
