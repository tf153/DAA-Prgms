#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void dfs(vector<int> vertex[], int i, stack<int> &st, bool visited[])
{
    int size = vertex[i].size();
    visited[i] = true;
    for (int j = 0; j < size; j++)
    {
        if (!visited[vertex[i][j]])
            dfs(vertex, vertex[i][j], st, visited);
    }
    st.push(i);
}
void topological_sort(vector<int> vertex[], int v)
{
    bool visited[v];
    stack<int> st;
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            dfs(vertex, i, st, visited);
    }
    while (!st.empty())
    {
        cout << st.top() << "->";
        st.pop();
    }
}
int main()
{
    int v, e, x, y;
    cin >> v >> e;
    vector<int> vertex[v];
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        vertex[x].push_back(y);
    }
    topological_sort(vertex, v);
    return 0;
}