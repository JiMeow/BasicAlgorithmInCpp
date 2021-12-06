#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<pii> x[1000];
priority_queue< pii,vector<pii>,greater<pii> > pq;
int ans[1000];
int mst[1000];
main()
{
    fill(ans,ans+1000,1e9);
    int n,m,start,endd;
    cin >> n >> m >> start;;
    ans[start]=0;
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        x[u].emplace_back(v,w);
        x[v].emplace_back(u,w);
    }
    pq.emplace(0,start);
    while(pq.size()!=0)
    {
        int st=pq.top().second;
        pq.pop();
        mst[st]=1;
        for(int i=0; i<x[st].size(); i++)
        {
            int go=x[st][i].first;
            int w=x[st][i].second;
            if(w<ans[go] && mst[go]==0)
            {
                ans[go]=w;
                pq.emplace(w,go);
            }
        }
    }
    int kut=0;
    for(int i=1;i<=n;i++){
        kut += ans[i];
    }
    cout << kut;

}
/*
5 5 1
1 2 1
1 3 1
1 4 1
1 5 10
5 4 3
*/
