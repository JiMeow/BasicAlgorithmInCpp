#include<bits/stdc++.h>
#define tiii tuple<int,int,int>
using namespace std;
int pr[1000];
int topp(int node){
    if(pr[node]==node) return node;
    return pr[node]=topp(pr[node]);
}

main(){
    int n,m;
    for(int i=0;i<1000;i++){
        pr[i]=i;
    }
    cin >> n >> m;
    priority_queue< tiii,vector<tiii>,greater<tiii> > pq;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        pq.emplace(w,u,v);
        pq.emplace(w,v,u);
    }
    int ans=0;
    while(pq.size()!=0){
        int u,v,w;
        tie(w,u,v)=pq.top();
        int a=topp(u);
        int b=topp(v);
        if(a!=b){
            ans += w;
            pr[a]=b;
        }
        pq.pop();
    }
    cout << ans;
}
