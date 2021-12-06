#include<bits/stdc++.h>
#define tiii tuple<int,int,int>
using namespace std;
int d[1000];
main(){
    int n,m;
    fill(d,d+1000,1e9);
    cin >> n >> m;
    vector<tiii> vec;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec.emplace_back(u,v,w);
    }
    d[0]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<vec.size();j++){
            int u,v,w;
            tie(u,v,w)=vec[j];
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
            }
        }
    }
    int countt=0;
    for(int i=0;i<vec.size();i++){
        int u,v,w;
        tie(u,v,w)=vec[i];
        if(d[v]>d[u]+w) {
            countt++;
            break;
        }
    }
    if(countt==0) cout << "no neg" << endl;
    else cout << "have neg" << endl;
    for(int i=0;i<n;i++){
        cout << i << "::" << d[i] << endl;
    }
}
