#include<bits/stdc++.h>
using namespace std;
vector<int> x;

void bi(int start,int endd,int n){
    int mid=(start+endd)/2;
    if(start>=endd){
        if(start==-1 || start==10){
            cout << "NotFound";
            return;
        }
        cout << "found " << start;
        return;
    }
    if(x[mid]==n){
        cout << "found " << x[mid];
        return;
    }
    else if(x[mid]<n){
        bi(mid+1,endd,n);
    }
    else if(x[mid]>n){
        bi(start,mid-1,n);
    }
}

void bi2(int start,int endd,int n){
    while(start<endd){
         int mid=(start+endd)/2;
         if(x[mid]==n){
            cout << "found " << x[mid];
            return;
            }
         else if(x[mid]<n){
            start=mid+1;
         }
         else if(x[mid]>n){
            endd=mid-1;
         }
    }
    cout << "NotFound" ;
    return;
}

void bi3(int start,int endd,int n){
    cout << start << " "  << endd << endl;
    int mid=(start+endd)/2;
    if(start>=endd){
        cout << "found " << x[start];
        return;
    }
    if(x[mid]<n){
        bi3(mid+1,endd,n);
    }
    else if(x[mid]>=n){
        bi3(start,mid,n);
    }
}

main(){
    for(int i=0;i<10;i++){
        int k;
        cin >> k;
        x.push_back(k);
    }
    sort(x.begin(),x.end());
    int n;
    cin >> n;
    bi3(0,9,n);
}
//1 2 3 4 5 6 7 8 9 10
