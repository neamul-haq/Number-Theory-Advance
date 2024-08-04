/*
Problem_Link:
AUTHOR: Neyamul_Haq
CREATED: 25-07-2024  12:03:01
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long int ll;
typedef long double ld;
#ifdef LOKAL
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
#define nl '\n'
#define cyes cout << "YES" << '\n';
#define cno cout << "NO" << '\n';
#define print cout << ans << '\n';
#define   Pi     2*acos(0.0)
#define   mem(a,v)   memset(a,v,sizeof(a))
#define sz(a) (int)(a).size()
int const MOD = 1e9+7;
const ll inf = 1e18;
#define   fast() {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define all(x) (x).begin(), (x).end()
void solve();
ll csum(ll x){
    return ((x%MOD)*((x+1)%MOD)/2)%MOD;
}
int main()
{
#ifndef LOKAL
    fast()
#endif
    ll t=1; 
    while(t--) solve();
}

void solve(){
    ll N;
    cin>>N;
    ll sum=0;
    for(ll l = 1; l <= N; l++){
        ll r = N/(N/l);
        sum += (N/l)%MOD*(csum(r)-csum(l-1)+MOD)%MOD;
        sum = (sum+MOD)%MOD;
        debug(l,r,sum, N/l ,csum(r),csum(l-1));
        l = r;
    }
    cout << sum << nl;
}