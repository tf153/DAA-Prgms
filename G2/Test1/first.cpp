#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        map<int, int> mp;
        int n;
        cin >> n;
        int count = n;
        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            mp[temp]++;
        }
        while (mp.find(count) != mp.end())
        {
            temp = mp[count];
            mp.erase(count);
            count -= temp;
        }
        if (mp.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}