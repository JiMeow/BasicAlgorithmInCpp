#include<bits/stdc++.h>
using namespace std;
vector<int> vec[1000];
int visit[1000];
int x[1000][1000];

void dfs(int node){
    visit[node]=1;
    cout << node << " ";
    for(int i=0;i<vec[node].size();i++){
        if(visit[vec[node][i]]==0) dfs(vec[node][i]);
    }
}

void bfs(int node){
    queue<int> q;
    q.emplace(node);
    while(q.size()!=0){
        node=q.front();
        cout << node << " ";
        visit[node]=1;
        for(int i=0;i<vec[node].size();i++){
            if(visit[vec[node][i]]==0){
                q.emplace(vec[node][i]);
                visit[vec[node][i]]=1;
            }
        }
        q.pop();
    }
}

/*void ff(int xx,int yy){
    visit[xx][yy]=1;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(abs(i+j)==1 && xx+i>=0 && xx+i<n && yy+j>=0 && yy+j<m && x[xx+i][yy+j]==1){
                if(visit[xx+i][yy+j]==0) ff(xx+i,yy+j);
            }
        }
    }
}*/

main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
        x[u][v]=1;
        x[v][u]=1;
    }
}
