/*
AUTHOR: Neyamul_Haq
CREATED: 13-09-2023  11:59:42
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
#define f(i, n) for (int i = 0; i < n; i++)
#define ump unordered_map<int, int> um;
#define mp map<int, int> m;
#define sz(a) (int)(a).size()
int const mod = 1e9 + 7;
const ll inf = 1e18;
const ll N = 1e3;
const double eps = 1e-9;
#define fast()                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);                      \
    }
#define all(x) (x).begin(), (x).end()
void solve();
double memoizedArray[1000001];
//memoizedArray[0]=0;
ll cs = 1;

void factorialDigitSave()
{
    
    for (int i = 1; i <= 1000000; i++)
    {
        memoizedArray[i] = memoizedArray[i - 1] + log(i);
    }
}

int main()
{
#ifndef LOKAL
    fast()
#endif
        ll t = 1;
    cin >> t;
    factorialDigitSave();
    while (t--)
        solve();
}

void solve()
{
    int n, b, ans = 0;
    cin >> n >> b;
    ans = (memoizedArray[n]/log(b)) +1;
    cout << "Case " << cs << ": " << ans << ndl;
    cs++;
}