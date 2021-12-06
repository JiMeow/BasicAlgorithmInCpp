#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
vector<pii> vec[1010];
int dis[1010];

main(){
    int n,m,st;
    fill(dis,dis+1010,1e9);
    cin >> n >> m >> st;
    priority_queue<pii,vector<pii>, greater<pii> > pq;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v,w);
        vec[v].emplace_back(u,w);
    }
    pq.emplace(0,st);
    dis[st]=0;
    while(pq.size()!=0){
        int node=pq.top().second;
        pq.pop();
        for(int i=0;i<vec[node].size();i++){
            int v=vec[node][i].first;
            int w=vec[node][i].second;
            if(dis[v]>dis[node]+w){
               dis[v]=dis[node]+w;
               pq.emplace(dis[v],v);
            }
        }
    }
}
