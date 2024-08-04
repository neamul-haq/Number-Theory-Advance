/*
AUTHOR: Neyamul_Haq
CREATED: 11-09-2023  14:21:10
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
#define f(i,n) for(int i=0; i<n; i++)
#define ump unordered_map<int,int>um;
#define mp map<int,int>m;
#define sz(a) (int)(a).size()
int const mod = 1e9+7;
const ll inf = 1e18;
const ll N = 1e3 ;
#define   fast() {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define all(x) (x).begin(), (x).end()
void solve();
int cs=1;
#define M 1000005
bool marked[M];
vector<ll> primes;

bool isPrime(ll n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    return marked[n] == false;
}

void sieve(ll n)
{
    for (ll i = 3; i * i <= n; i += 2)
    {
        if (marked[i] == false)   // i is a prime
        {
            for (ll j = i * i; j <= n; j += i + i)
            {
                marked[j] = true;
            }
        }
    }

    primes.push_back(2);
    for(ll i = 3; i <= n + 1; i += 2)
    {
        if(isPrime(i))
        {
            primes.push_back((ll) i);
        }
    }

}


ll countDivisor2(ll n)// O(log n)
{
    //if (n < 1) return 0;
    //ll sqrn = (ll) sqrt(n);
    //sieve(n+1);
    ll divisor = 1;
    for (ll i = 0; primes[i]*primes[i] <= n; i++)
    {
        if (n % primes[i] == 0)
        {
            ll cnt = 1;
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                cnt++;
            }
            divisor *= cnt;
        }
    }
    if (n > 1) divisor *= 2;
    return divisor;
}

int main()
{
#ifndef LOKAL
    fast()
#endif
    ll t=1; cin >> t;
    sieve(M);
    while(t--) solve();
}

void solve(){
    ll n,ans=0; cin >> n;
    ans = countDivisor2(n);
    cout << "Case " << cs << ": "<< ans-1<<ndl; 
    cs++;
}