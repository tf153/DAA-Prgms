#include <iostream>
#include <string>

using namespace std;

int longest_subsequence(string &str1, string &str2, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (str1[n - 1] == str2[m - 1])
        return 1 + longest_subsequence(str1, str2, n - 1, m - 1);
    else
        return max(longest_subsequence(str1, str2, n - 1, m), longest_subsequence(str1, str2, n, m - 1));
}

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int n = str1.length(), m = str2.length();
    cout << longest_subsequence(str1, str2, n, m);
    return 0;
}