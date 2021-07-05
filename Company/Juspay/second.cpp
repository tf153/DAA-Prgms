//2
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;
vector<pair<int, int>> graph[1000001];
int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        mp[x] = INT_MAX;
    }
    int e;
    cin >> e;
    for (int i = 0; i < e; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    int start, end;
    cin >> start >> end;
    set<pair<int, int>> s;
    mp[start] = 0;
    s.insert({0, start});
    while (!s.empty())
    {
        pair<int, int> tmp = *(s.begin());
        s.erase(s.begin());
        int u = tmp.second;
        for (auto i = graph[u].begin(); i != graph[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (mp[v] > mp[u] + weight)
            {
                if (mp[v] != INT_MAX)
                    s.erase(s.find({mp[v], v}));
                mp[v] = mp[u] + weight;
                s.insert({mp[v], v});
            }
        }
    }
    if (mp[end] != INT_MAX)
        cout << mp[end];
    else
        cout << -1;
    return 0;
}