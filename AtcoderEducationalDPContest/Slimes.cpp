#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int, greater<int>> si;

#define ln "\n"
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 1e9 + 7
#define f(a, c) for (int a = 0; a < c; a++)

vector<vector<ll>> dp;
vector<int> a;
vector<ll> pre;

ll sum(int l, int r) {
    ll x = pre[r];
    if(l > 0) x -= pre[l-1];
    return x;
}

ll solve(int l, int r) {
    if(l == r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    ll ans = 1e18;
    for(int i = l; i < r; i++) {
        ans = min(ans, solve(l, i) + solve(i+1, r) + sum(l, r));
    }
    return dp[l][r] = ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    a.resize(n);
    pre.resize(n);
    f(i, n) {
        cin >> a[i];
        pre[i] = a[i];
        if(i > 0) pre[i] += pre[i-1];
    }
    
    dp.resize(n+1, vector<ll>(n+1, -1));

    cout << solve(0, n-1) << ln;

    return 0;
}