#include<bits/stdc++.h>
using namespace std;
int tmp[1000000];
vector<int> vec;
int n;

void _merge(int l,int mid,int r){
    int a=l,b=mid+1;
    for(int i=l;i<=r;i++){
        if(a > mid){ tmp[i] = vec[b]; b++; continue; }
        if(b > r){ tmp[i] = vec[a]; a++; continue; }
        if(vec[a]>vec[b]){
            tmp[i] = vec[b]; b++; continue;
        }
        else {
            tmp[i] = vec[a]; a++; continue;
        }
    }
    for(int i=l;i<=r;i++){
        vec[i]=tmp[i];
    }
}

void _sort(int l,int r){
    if(r-l<=0) return;
    int mid=(l+r)/2;
    _sort(l,mid);
    _sort(mid+1,r);
    _merge(l,mid,r);
}

main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        vec.emplace_back(k);
    }
    _sort(0,vec.size()-1);
    for(int i=0;i<n;i++){
        cout << vec[i] << " ";
    }
}
