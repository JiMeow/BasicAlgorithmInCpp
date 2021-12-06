#include<bits/stdc++.h>

using namespace std;
main(){
   string x,y;
   int e=23,ans=0;
   cin >> x >> y;
   int now=0,con=1,want=0;
   for(int i=0;i<x.size();i++){
    want = want*e +x[i];
    con *= e;
   }
   for(int i=0;i<y.size();i++){
    now = now*e + y[i];
    if(i>=x.size()){
        now -= y[i-x.size()]*con;
    }
    if(now==want) ans++;

   }
   cout << ans;
}
