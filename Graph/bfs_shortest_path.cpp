/* Input  Shortest Path
7 9
1 2
1 3
1 6
2 4
3 4
3 5
5 4
5 6
6 7
Output
1 6 7
*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> bfs(vector<int> edge[],int n,int m,int start,int end,bool status[]){
    int parent[n];
    memset(parent,-1,sizeof(parent));
    parent[0]=0;
    queue<int>q;
    q.push(0);
    status[0]=true;
    while(!q.empty()){
        status[q.front()]=2;
        for(int a: edge[q.front()]){
            if(!status[a]){
                status[a]=true;
                q.push(a);
                parent[a]=q.front();
            }
        }
        q.pop();
    }
    vector<int> ans;
    for(int i=end;i!=start;i=parent[i]){
        ans.push_back(i+1);
    }
    ans.push_back(start+1);
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n,m,u,v;
    cin>>n>>m;
    vector<int> edge[n];
    bool status[n];
    memset(status,false,sizeof(status));
    for(int i=0;i<m;i++){
        cin>>u>>v;
        edge[u-1].push_back(v-1);
    }
    vector<int> ans;
    ans=bfs(edge,n,m,0,n-1,status);
    for(int a:ans)cout<<a<<' ';
    return 0;
}