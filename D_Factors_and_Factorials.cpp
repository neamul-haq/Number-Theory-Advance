/*
AUTHOR: Neyamul_Haq
CREATED: 23-12-2023  09:04:47
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
#define ndl '\n'
#define cyes cout << "YES" << '\n';
#define cno cout << "NO" << '\n';
#define print cout << ans << '\n';
#define f(strt, end) for (int i = strt; i <= end; i++)
#define sz(a) (int)(a).size()
int const mod = 1e9 + 7;
const ll inf = 1e18;
const ll N = 1e3;
#define fast()                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);                      \
    }
#define all(x) (x).begin(), (x).end()
void solve();
#define MAX 100
map<ll, ll> mp;
vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
vector<ll> List;

void primeFactorize(ll n)
{
    for (ll i = 0; primes[i] * primes[i] <= n; i++)
    {
        if (n % primes[i] == 0)
        {
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                List.push_back(primes[i]);
            }
        }
    }
    if (n > 1)
    {
        List.push_back(n);
    }
}
int main()
{
#ifndef LOKAL
    fast()
#endif
        ll t = 1;
        ll n, x ;
        n=2;
    while (cin>>n)
    {
        x=0;
        if (n == 0) break;
        
        for (ll i = 2; i <= n; i++)
        {
            primeFactorize(i);
            for (auto u : List)
            {
                mp[u]++;
            }
            List.clear();
        }
        printf("%3ld! =",n);
        for (int i = 0; i < primes.size(); i++)
        {
            if (primes[i] > n)
                break;
            printf("%3ld", mp[primes[i]]);
            x++;
            if (x == 15 && primes[i+1]<=n)
            {
                printf("\n%6c", ' ');
            }
        }
        printf("\n");
        mp.clear();
    }
}