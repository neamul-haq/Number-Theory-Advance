/*
AUTHOR: Neyamul_Haq
CREATED: 23-12-2023  13:55:15
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
long long binpow(long long a, long long b, long long m)
{
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2, m); // b/2 = b>>1
    if (b % 2)                           // b&1 = b%2
        return (res % m * res % m * a) % m;
    else
        return (res % m * res % m) % m;
}
int main()
{
#ifndef LOKAL
    fast()
#endif
        ll i,
        n, m, k, j, b, p, s = 0, x = 0, ans = 0;
    while (cin >> b >> p >> m)
    {
        ans = binpow(b, p, m);
        print
    }
}