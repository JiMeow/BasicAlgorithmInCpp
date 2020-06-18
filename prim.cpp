#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
vector<pair<int,int> > vec[1000];
int in[1000];
int dis[1000];
main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(w,v);
        vec[v].emplace_back(w,u);
    }
    fill(dis,dis+n+1,1e9);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.emplace(0,1);
    dis[1]=0;
    while(pq.size()!=0){
        int node=pq.top().second;
        pq.pop();
        in[node]=1;
        for(int i=0;i<vec[node].size();i++){
            if(dis[vec[node][i].second]>vec[node][i].first && in[vec[node][i].second]==0){
                dis[vec[node][i].second]=vec[node][i].first;
                pq.emplace(vec[node][i].first,vec[node][i].second);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans += dis[i];
    }
    cout << ans;
}
