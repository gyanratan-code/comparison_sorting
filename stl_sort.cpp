#include<bits/stdc++.h>
#define nl std::endl
using namespace std;
typedef long long ll;
int main(){
    freopen("IN","r",stdin);
    freopen("OUT","w",stdout);
    ll n;
    cin>>n;
    vector<ll> data(n);
    for(auto&val:data) cin>>val;
    sort(data.begin(),data.end());
    for(auto&val:data) cout<<val<<" ";
    return 0;
}