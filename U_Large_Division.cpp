/*
AUTHOR: Neyamul_Haq
CREATED: 18-12-2023  19:43:48
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
ll cs = 0;
int main()
{
#ifndef LOKAL
    fast()
#endif
        ll t = 1;
    cin >> t;
    while (t--)
        solve();
}

void solve()
{
    string a;
    int b;
    cin >> a >> b;
    int j = 0;
    if (a[0] == '-')
        j = 1;
    if (b < 0)
        b = abs(b);
    long rim = 0;
    for (; j < a.size(); j++)
    {
        rim = rim * 10 + (a[j] - '0');
        rim %= b;
    }
    if (rim == 0)
        cout << "Case " << ++cs << ": divisible" << '\n';
    else
        cout << "Case " << ++cs << ": not divisible" << '\n';
}