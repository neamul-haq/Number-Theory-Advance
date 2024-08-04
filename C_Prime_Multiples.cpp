/*
Problem_Link:
AUTHOR: Neyamul_Haq
CREATED: 26-07-2024  12:03:27
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef unsigned long long int ll;
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
int const mod = 1e9+7;
const ll inf = 1e18;
const ll N = 1e3 ;
#define   fast() {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define all(x) (x).begin(), (x).end()
void solve();

int main()
{
#ifndef LOKAL
    fast()
#endif
    ll t=1; 
    while(t--) solve();
}

void solve(){
    ll n, m, k, sum = 0, x = 0, ans=0; cin >> n>>k;
    vector<ll>a(k);
    for(int i=0; i<k; i++)
    {
       cin >> a[i];
    }
    vector<vector<ll>> subsets;
    for (int i = 0; i < (1 << k); i++)
    {

        vector<ll> subset;
        for (int j = 0; j < k; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                subset.push_back(a[j]);
            }
        }
        subsets.push_back(subset);
    }
    debug(subsets);
    for (int i = 0; i < subsets.size(); i++)
    {
        if(subsets[i].empty()) continue;
        x=1;
        bool overflow=false;
        for (auto val : subsets[i])
        {
            if(x>LLONG_MAX/val){
                overflow=true;
                break;
            } 
            x*=val;
        }
        if(overflow or x>n) continue;
        if(subsets[i].size()%2) ans+= n/x;
        else ans-= n/x;
        debug(x,ans);
    }

    cout << ans << nl;

    //DON'T GET STUCK ON ONE APPROACH!
}