#include<bits/stdc++.h>
using namespace std;
int sum[1000000];
int n;

void update(int node,int val){
    while(node <= 1000000){
        sum[node] += val;
        node += (node&-node);
    }
}

int use(int node){
    int ans=0;
    while(node>0){
        ans += sum[node];
        node -= (node&-node);
    }
    return ans;
}

int get(int x,int y){
    if(x>y) swap(x,y);
    return use(y)-use(x);
}

main(){

}
