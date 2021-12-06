#include<bits/stdc++.h>
using namespace std;
int x[1000][1000];
main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;i++){
            x[i][j]=1e9;
        }
    }
    for(int i=0;i<n;i++){
        x[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        x[u][v]=w;
        x[v][u]=w;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                x[j][k]=min(x[j][k],x[j][i]+x[i][k]);
            }
        }
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int st,en;
        cin >> st >> en;
        cout << x[st][en] << endl;
    }
}
