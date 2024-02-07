#include<bits/stdc++.h>
#define nl std::endl
using namespace std;
typedef long long ll;
void mergesort(ll,ll,vector<ll>&);
int main(){
    freopen("IN","r",stdin);
    freopen("OUT","w",stdout);
    ll n;
    // cout<<"Enter number of input: ";
    cin>>n;
    vector<ll> data(n);
    for(auto& val:data) cin>>val;
    mergesort(0,n-1,data);
    for(auto& val:data) cout<<val<<" ";
    return 0;
}
void mergesort(ll s,ll e,vector<ll>& data){
    ll mid= (s+e)/2;
    if(e-s==0) return;
    else if(e-s==1){
        if(data[s]>data[e]) swap(data[s],data[e]);
        return;
    }
    else{
        mergesort(s,mid,data);
        mergesort(mid+1,e,data);
    }
    // now sort in linear time complexity with linear space
    int i=s,j=mid+1;
    vector<ll> temp(e-s+1);
    int ti=0;
    while(i<=mid && j<=e){
        if(data[i]<data[j]) temp[ti++]= data[i++];
        else temp[ti++]= data[j++];
    }
    while(i<=mid){
        temp[ti++]= data[i++];
    }
    while(j<=e){
        temp[ti++]=data[j++];
    }
    // copy sorted array back to the original list
    for(int i=s,j=0;i<=e;i++,j++){
        data[i] =temp[j];
    }
    // for(int i=0;i<temp.size();i++) cout<<temp[i]<<" ";
    // cout<<nl;
}