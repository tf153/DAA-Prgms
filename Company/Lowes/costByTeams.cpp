#include <bits/stdc++.h>
using namespace std;
bool sortFun(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return (a.second < b.second);
    return (a.first < b.first);
}
void removeUnnecessary(vector<pair<int, int>> &teams, int &start, int &end)
{
    sort(teams.begin(), teams.end(), sortFun);
    int size = teams.size();
    if (size == 1)
    {
        start = teams[0].first;
        end = teams[0].second;
    }
    if (size == 2)
    {
        if (teams[1].second <= teams[0].second)
        {
            teams.erase(teams.begin() + 1);
            start = teams[0].first;
            end = teams[0].second;
            return;
        }
        else
        {
            if (teams[0].second >= teams[1].first - 1)
            {
                start = teams[0].first;
                end = teams[1].second;
                return;
            }
            else
            {
                start = teams[0].first;
                end = teams[0].second;
                return;
            }
        }
    }
    for (int i = 1; i < teams.size() - 1; i++)
    {
        if (teams[i].second <= teams[i - 1].second)
        {
            teams.erase(teams.begin() + i);
            i--;
            continue;
        }
        if (teams[i].first == teams[i - 1].second && teams[i].first == teams[i + 1].first - 1)
        {
            teams.erase(teams.begin() + i);
            i--;
            continue;
        }
        if (teams[i].first == teams[i + 1].first && teams[i].second <= teams[i + 1].second)
        {
            teams.erase(teams.begin() + i);
            i--;
        }
    }
}
int main()
{
    int n, m, s, e;
    cin >> n >> m;
    vector<pair<int, int>> teams(m);
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        teams[i] = {s, e};
    }
    int start = 0, end = 0;
    removeUnnecessary(teams, start, end);
    int ans[n + 1];
    memset(ans, 0, sizeof ans);
    for (pair<int, int> p : teams)
    {
        for (int i = p.first; i <= p.second; i++)
        {
            ans[i]++;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!ans[i])
        {
            cout << -1;
            return 0;
        }
        else
        {
            sum += ans[i];
        }
    }
    cout << sum;
    return 0;
}