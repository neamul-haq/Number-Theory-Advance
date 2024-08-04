/*
AUTHOR: Neyamul_Haq
CREATED: 22-12-2023  20:48:31
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
#define M 10000000
bool marked[M];
typedef long long int ll;
vector<int> primes;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    return marked[n] == false;
}

void sieve(int n)
{
    for (int i = 3; i * i <= n; i += 2)
    {
        if (marked[i] == false) // i is a prime
        {
            for (int j = i * i; j <= n; j += i + i)
            {
                marked[j] = true;
            }
        }
    }

    primes.push_back(2);
    for (int i = 3; i <= n + 1; i += 2)
    {
        if (isPrime(i))
        {
            primes.push_back((int)i);
        }
    }
}

ll countDivisor3(ll n)
{
    if (n < 1)
        return 0;
    //ll sqrn = (ll)sqrt(n);
    
    ll divisor = 1;
    for (ll i = 0; primes[i] * primes[i] <= n; i++)
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
    if (n > 1)
        divisor *= 2;
    return divisor;
}

int main()
{
#ifndef LOKAL
    fast()
#endif
        sieve(M);
        ll t = 1;
    cin >> t;
    while (t--)
        solve();
}

void solve()
{
    ll i, n, m, k, j, s = 0, x = 0;
    cin >> n >> m;
    pair<int,int>mxDivisor(-1,-1);
    //cout << mxDivisor.first;
    for(int i=n; i<=m; i++){
        int cnt = countDivisor3(i);
        if(cnt>mxDivisor.second){
            mxDivisor = {i, cnt};
        }
    }
    cout<<"Between "<<n<<" and " <<m<<", " << mxDivisor.first<<" has a maximum of " << mxDivisor.second << " divisors."<<ndl;
}