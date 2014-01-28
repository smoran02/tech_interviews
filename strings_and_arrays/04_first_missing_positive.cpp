#include <iostream>
#include <vector>
using namespace std;
int firstMissingPositive(vector<int> A)
{
    //we want to make all the A[i] = i + 1 (0 <= i < n)
    int n = A.size(), x = n;
    for (int i = 0; i < n; i++) {
        if (A[i] < 1 || A[i] > n) // if these numbers appear, the answer must between 1 and n
            continue;
        int j = A[i];
        while (j != i + 1 && 1 <= j && j <= n) {// we put j into A[j - 1], but A[j - 1] may be another number k(k != j)
            // so we again need to put k into A[k - 1]
            // we store k in A[i] temporarily, and hope that k would be i + 1 finally
            // this will result a chain, that happens recursively
            if (A[j - 1] == j) //A[j - 1] already equals j, we don't need to replace it, otherwise we enter an infinite loop
                break;
            int k = A[j - 1];
            A[j - 1] = j;
            j = A[i] = k;
        }
    }
    //we will only put j into A[j - 1] once, so the time complexity is O(n)
    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) // first positive i + 1 that doesn't appear, otherwise, i + 1 would be in A[i] according to the previous procesure
            return i + 1;
    }
    return n + 1; // all the numbers between 1 and n have appeared, so the answer is n + 1
}
int main()
{
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        a.push_back(j);
    }
    cout << firstMissingPositive(a) << endl;
    return 0;
}
