#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
bool solve(vector<int> graph[], int n, int s, int d)
{
    if (d == s)
        return true;
    bool visited[n] = {false};
    queue<int> bfs;
    visited[s] = true;
    bfs.push(s);
    vector<int>::iterator itr;
    while (!bfs.empty())
    {
        s = bfs.front();
        bfs.pop();
        for (itr = graph[s].begin(); itr != graph[s].end(); itr++)
        {
            if (*itr == d)
                return true;
            if (!visited[*itr])
            {
                visited[*itr] = true;
                bfs.push(*itr);
            }
        }
    }
    return false;
}
int main()
{
    map<int, int> mp;
    int n, node;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> node;
        mp[node] = i;
    }
    vector<int> graph[n];
    int e;
    cin >> e;
    int u, v;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        graph[mp[u]].push_back(mp[v]);
    }
    int start, end;
    cin >> start >> end;
    if (solve(graph, n, mp[start], mp[end]))
        cout << 1;
    else
        cout << 0;
    return 0;
}