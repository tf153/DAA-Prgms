/*
6 9
1 0 1
3 0 5
2 1 5
4 1 2
5 1 4
6 5 4
7 2 4
9 4 3
8 2 3*/
//w s d
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<pair<int, pair<int, int>>> vpp;
int find(int v, int parent[])
{
    if (parent[v] < 0)
    {
        return v;
    }
    return find(parent[v], parent);
}
void union_by_weight(int s, int d, int parent[])
{
    int ps = find(s, parent), pd = find(d, parent);
    if (ps != pd)
    {
        if (parent[ps] < parent[pd])
        {
            parent[ps] += parent[pd];
            parent[pd] = ps;
        }
        else
        {
            parent[pd] += parent[ps];
            parent[ps] = pd;
        }
    }
}
vpp min_spaning(vpp &graph, int v, int e)
{
    vpp ans;
    int s, d, w;
    int parent[v + 1];
    for (int i = 0; i <= v; i++)
        parent[i] = -1;
    sort(graph.begin(), graph.end());
    for (int i = 0; i < e; i++)
    {
        w = graph[i].first;
        s = graph[i].second.first;
        d = graph[i].second.second;
        if (find(s, parent) != find(d, parent))
        {
            ans.push_back(graph[i]);
            union_by_weight(s, d, parent);
        }
    }
    return ans;
}
int main()
{
    int v, e, s, d, w;
    vpp graph, ans;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> s >> d >> w;
        graph.push_back(make_pair(w, make_pair(s, d)));
    }
    ans = min_spaning(graph, v, e);
    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].second.first << "->" << ans[i].second.second << "(" << ans[i].first << ")\n";
        sum += ans[i].first;
    }
    cout << sum;
    return 0;
}