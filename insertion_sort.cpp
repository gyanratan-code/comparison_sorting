#include<bits/stdc++.h>
#define nl std::endl
using namespace std;
typedef long long ll;
int main(){
    freopen("IN","r",stdin);
    freopen("OUT","w",stdout);
    ll n;
    // cout<<"Enter number of inputs: ";
    cin>>n;
    vector<ll> data(n,0);
    for(auto& val:data) cin>>val;
    for(ll i=1;i<data.size();i++){
        ll key=data[i];
        int j=i-1;
        while(j>=0 && data[j]>key){
            data[j+1] = data[j];
            j-=1;
        }
        data[j+1]= key;
    }
    // sorted array
    // cout<<"Sorted array: ";
    for(auto& val: data){
        cout<<val<<" ";
    }
    return 0;
}