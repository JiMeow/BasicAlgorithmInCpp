#include<bits/sdtc++.h>
#define pii pair<int,int>
using namespace std;
vector<pii> x[1000];
int dis[1000]
main(){
    int n,m,start,endd;
    cin >> n >> m >> start >> endd;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        x[u].emplae_back(v,m);
        x[v].emplae_back(u,m);
    }
    fill(dis,dis+1000,)
}
