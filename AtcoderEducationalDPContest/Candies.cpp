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

ll solve(int k, int i, vector<int> &a) {
    if(k == 0) return 1;
    if(k < 0) return 0;
    if(i >= a.size()) return 0;

    if(dp[k][i] != -1) return dp[k][i];
    ll ans = 0;
    for(int j = 0; j <= a[i]; j++) 
        if(k - j >= 0) ans += solve(k - j, i + 1, a);
    
    return dp[k][i] = ans % ((ll)mod);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    // dp.resize(k+1, vector<ll>(n+1, -1));
    dp.resize(k+1, vector<ll>(n+1, 0));
    vector<int> a(n);
    f(i, n) cin >> a[i];

    // cout << solve(k, 0, a) << ln;

    dp[0][0] = 1;

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 0; j <= k; j++) {
    //         for(int kk = 0; kk <= min(a[i-1], j); kk++) {
    //             dp[j][i] += dp[j-kk][i-1];
    //             dp[j][i] %= (ll)mod;
    //         }
    //     }
    // }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[j][i-1] += dp[j-1][i-1];
        }
        for(int j = 0; j <= k; j++) {
            dp[j][i] += dp[j][i-1];
            if(j-a[i-1] > 0) dp[j][i] -= dp[j-a[i-1]-1][i-1];
            dp[j][i] %= (ll)mod;
        }
    }

    cout << dp[k][n] << ln;

    return 0;
}