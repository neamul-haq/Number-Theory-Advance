/*
AUTHOR: Neyamul_Haq
CREATED: 13-09-2023  10:29:13
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
#define ndl '\n';
#define cyes cout << "YES" << '\n';
#define cno cout << "NO" << '\n';
#define print cout << ans << '\n';
#define f(start,end) for(int i=start; i<end; i++)
#define ump unordered_map<int,int>um;
#define mp map<int,int>m;
#define sz(a) (int)(a).size()
int const mod = 1e9+7;
const ll inf = 1e18;
const ll N = 1e6 ;
#define   fast() {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define all(x) (x).begin(), (x).end()
void solve();
int cs=1;
vector<int> phi(N+9);
void phi_1_to_n(int n) {
    
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
int main()
{
#ifndef LOKAL
    fast()
#endif
    phi_1_to_n(N+7);
    ll t=1; cin >> t;
    while(t--) solve();
}

void solve(){
    ll n,ans=0; cin >> n;
    vector<int>a(n);
    f(0,n){
        cin >> a[i];
    }

    f(0,n){
        for(int j=a[i]+1; j<N+5; j++){
            if(phi[j]>=a[i]){
                ans+=j;
                //cout << phi[j] << ndl;
                break;
            }
        }
    }
    cout << "Case " << cs << ": "<< ans<< " Xukha" <<ndl; 
    cs++;
}