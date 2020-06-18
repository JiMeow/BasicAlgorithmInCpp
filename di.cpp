#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
vector<pair<int,int> > vec[1000];
int bk[1000];
int dis[1000];
main(){
    int n,m,start,endd;
    cin >> n >> m >> start >> endd;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(w,v);
        vec[v].emplace_back(w,u);
    }
    fill(dis,dis+1000,1e9);
    bk[start]=-1;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.emplace(0,start);
    dis[start]=0;
    while(pq.size()!=0){
        int node=pq.top().second;
        if(node==endd) break;
        for(int i=0;i<vec[node].size();i++){
            int go=vec[node][i].second;
            int d=vec[node][i].first;
            if(dis[go]>dis[node]+d){
                dis[go]=dis[node]+d;
                pq.emplace(dis[go],go);
                bk[go]=node;
            }
        }
    }
    cout << dis[endd] << endl;
    stack<int> st;
    int e=endd;
    while(e!=-1){
        st.push(e);
        e=bk[e];
    }
    while(st.size()!=0){
        cout << st.top() << " ";
        st.pop();
    }
}
