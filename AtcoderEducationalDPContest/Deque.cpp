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

vector<vector<vector<ll>>> dp;

ll solve(bool x, int i, int j, vector<int> &a) {
    if(i > j) return 0;
    if(dp[x][i][j] != -1) return dp[x][i][j];

    ll l = (x ? -1 : 1) * a[i] + solve(!x, i+1, j, a);
    ll r = (x ? -1 : 1) * a[j] + solve(!x, i, j-1, a);
    return dp[x][i][j] = x ? min(l, r) : max(l, r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    dp.resize(2, vector<vector<ll>>(n+1, vector<ll>(n+1, -1)));
    vector<int> a(n);
    f(i, n) cin >> a[i];

    solve(0, 0, n-1, a);
    cout << dp[0][0][n-1] << ln;

    return 0;
}