#include<bits/stdc++.h>
using namespace std;
 
int ceil(int t[],int l,int r,int key) {
    int m;
    while(r-l>1) {
        m=l+(r-l)/2;
        (t[m]>=key?r:l)=m;
    }
    return r;
}
int ans(int ar[],int n) {
    int temp[n];
    int max_l=1;
    for(int j=0;j<n;j++) {
        for(int i=0;i<n;i++) {
            temp[i]=0;
        }
        temp[0]=ar[j];
        int len=1;
        for(int i=(j+1);i<(j+n);i++) {
            if(ar[i]<temp[0]) {
                temp[0]=ar[i];
            }
            else if(ar[i]>temp[len-1]) {
                temp[len++]=ar[i];
            }
            else {
                temp[ceil(temp,-1,len-1,ar[i])]=ar[i];
            }
        }
        if(len>max_l) {
            max_l=len;
        }
    }
    return max_l;
}
 
int main() {
    int n,t;
    cin>>t;
    while(t--) {
            cin>>n;
            int ar[2*n];
            for(int i=0;i<n;i++) {
                cin>>ar[i];
                ar[i+n]=ar[i];
            }
            cout<<ans(ar,n);
            cout<<endl;
    }
    return 0;
}
 
