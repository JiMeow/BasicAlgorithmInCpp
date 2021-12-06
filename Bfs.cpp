#include<bits/stdc++.h>
using namespace std;
vector<int> vec[1000];
int visit[1000];

void bfs(int node){
    visit[node]=1;
    queue<int> q;
    q.push(node);
    while(q.size()!=0){
        int st=q.front();
        q.pop();
        for(int i=0;i<vec[st].size();i++){
            if(visit[vec[st][i]]==0){
                q.push(vec[st][i]);
                visit[vec[st][i]]=1;
            }
        }
    }
}

void dfs(int node){
    visit[node]=1;
    for(int i=0;i<vec[node].size();i++){
        if(visit[vec[node][i]]==0){
            dfs(vec[node][i]);
        }
    }
}

void ff(int xx,int yy){
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(abs(i+j)==1){

            }
        }
    }
}

main(){
    int n;
    cin >> n;
    while(n--){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    int start;
    cin >> start;
    bfs(start);
}
