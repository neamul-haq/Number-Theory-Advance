/*
AUTHOR: Neyamul_Haq
CREATED: 23-12-2023  12:41:32
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
#define M 2006
bool marked[M];

bool isprime(int n)
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
        if (marked[i] == false)
        { // i is a prime
            for (int j = i * i; j <= n; j += i + i)
            {
                marked[j] = true;
            }
        }
    }
}
ll cs = 0;
int main()
{
#ifndef LOKAL
    fast()
#endif
        ll t = 1;
    sieve(M);
    cin >> t;
    while (t--)
        solve();
}

void solve()
{
    string s;
    cin >> s;
    map<int, int> mp;

    for (int i = 0; i < sz(s); i++)
    {
        mp[s[i]]++;
    }
    bool ok = false;
    cout << "Case " << ++cs << ": ";
    for (auto [u, cnt] : mp)
    {
        if (cnt > 0 && isprime(cnt))
        {
            char a = char(u);
            cout << a;
            ok = true;
        }
    }
    if (!ok)
        cout << "empty";
    cout << ndl;
}