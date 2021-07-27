#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    int arr1[n];
    map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
        mp1[arr1[i]]++;
        mp2[arr1[i]] = 0;
    }
    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
        mp2[arr2[i]]++;
    }
    vector<int> ans;
    for (pair<int, int> p : mp1)
    {
        if (mp1.find(p.first) != mp1.end())
        {
            if (p.second != mp2[p.first])
            {
                ans.push_back(p.first);
            }
        }
        else
        {
            ans.push_back(p.first);
        }
    }
    sort(ans.begin(), ans.end(), greater<>());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}