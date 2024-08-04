/*
AUTHOR: Neyamul_Haq
CREATED: 10-09-2023  15:00:42
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
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
#define f(i,n) for(int i=0; i<n; i++)
#define ump unordered_map<int,int>um;
#define mp map<int,int>m;
#define sz(a) (int)(a).size()
int const mod = 1e9+7;
const ll inf = 1e18;
const ll N = 5000000;
#define   fast() {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define all(x) (x).begin(), (x).end()
void solve();
int cs=1;

unsigned long long sum[N+2];
int phi[N+2];

void calculatePhi(){
    for(int i=2; i<=N; i++)
        phi[i] = i;
    for(int i =2; i<=N; i++)
        if(phi[i]==i)
            for(int j=i; j<=N; j+=i)
                phi[j]-=phi[j]/i;
}

void calc(){
    calculatePhi();
    sum[1]=0;
    for(int i=2; i<=N; i++){
        sum[i]=((unsigned long long)phi[i]*(unsigned long long)phi[i]+sum[i-1]);
    }
}


int main()
{
#ifndef LOKAL
    fast()
#endif
    calc();
    int t=1; cin >> t;
    while(t--) solve();
}

void solve(){
    int a,b; cin >> a >> b;
    unsigned long long ans;
    ans=sum[b] - sum[a-1];
    cout << "Case " << cs << ": "<< ans<<ndl; 
    cs++;
}