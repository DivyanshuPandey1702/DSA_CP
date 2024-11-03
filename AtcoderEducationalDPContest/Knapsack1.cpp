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

int l = 100001;
vector<vector<bool>> dp;
vector<vector<ll>> mw;
int n, W;
vector<int> w, v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> W;
    w.resize(n, 0);
    v.resize(n, 0);
    f(i, n) cin>> w[i] >> v[i];
    dp.resize(n+1, vector<bool>(l, 0));
    mw.resize(n+1, vector<ll>(l, LLONG_MAX));
    f(i, n+1) dp[i][0] = 1, mw[i][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < l; j++) {
            int y = max(0, j-v[i-1]);
            dp[i][j] = dp[i-1][j] || dp[i-1][y];
            mw[i][j] = mw[i-1][j];
            if(dp[i-1][y]) mw[i][j] = min(mw[i][j], w[i-1] + mw[i-1][y]);
        }
    }

    ll ans = 0;
    for(int i = 0; i < l; i++) {
        if(dp[n][i] && mw[n][i] <= W) ans = i;
    }
    cout << ln;

    cout << ans << ln;

    return 0;
}