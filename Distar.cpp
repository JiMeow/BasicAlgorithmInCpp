#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<pii> x[1000];
priority_queue< pii,vector<pii>,greater<pii> > pq;
int ans[1000];
main()
{
    fill(ans,ans+1000,1e9);
    int n,m,start,endd;
    cin >> n >> m >> start >> endd;
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
        int d=pq.top().first;
        if(st==endd) break;
        pq.pop();
        for(int i=0; i<x[st].size(); i++)
        {
            int go=x[st][i].first;
            int w=x[st][i].second;
            if(d+w<ans[go])
            {
                ans[go]=ans[st]+w;
                pq.emplace(d+w,go);
            }
        }
    }
    cout << ans[endd];

}
/*
5 5 1 5
1 2 1
1 3 1
1 4 1
1 5 6
4 5 2
*/
