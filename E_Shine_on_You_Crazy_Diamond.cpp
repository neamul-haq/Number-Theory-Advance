/*
Problem_Link:
AUTHOR: Neyamul_Haq
CREATED: 26-07-2024  14:54:53
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
int const mod = 1e9+7;
const ll inf = 1e18;
const ll N = 1e3 ;
#define   fast() {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define all(x) (x).begin(), (x).end()
void solve();
#define M 1000000
bool marked[M];

bool isPrime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  return marked[n] == false;
}

void sieve(int n) {
  for (int i = 3; i * i <= n; i += 2) {
    if (marked[i] == false) { // i is a prime
      for (int j = i * i; j <= n; j += i + i) {
        marked[j] = true;
      }
    }
  }
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
    ll n, m, k, sum = 0, x = 0; cin >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++)
    {
       cin >> a[i];
    }
    vector<int>primes;
    for(int i=2; i<=10000; i++){
        if(isPrime(i)) primes.push_back(i);
    }
    //debug(primes);
    int sz=primes.size();
    vector<pair<int,int>>ans;
    for(int i=0; i<sz; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            if(a[j]%primes[i]==0) cnt++;
        }
        ans.push_back({cnt,primes[i]});
    }
    // cout << primes.size() << nl;
    sort(all(ans),greater<pair<int,int>>());
    cout << ans[0].second << " " << ans[1].second << nl;
    //DON'T GET STUCK ON ONE APPROACH!
}