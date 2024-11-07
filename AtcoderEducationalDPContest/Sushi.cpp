#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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

int n;
vector<int> a;
vector<int> c;
vector<vector<vector<ld>>> dp;

ld solve(int z, int o, int tw, int th) {
    if(z == n) return 0;
    if(dp[o][tw][th] != -1) return dp[o][tw][th];
    ld ans = n;
    if(o > 0) ans += o*solve(z+1, o-1, tw, th);
    if(tw > 0) ans += tw*solve(z, o+1, tw-1, th);
    if(th > 0) ans += th*solve(z, o, tw+1, th-1);
    ans /= (ld)(n-z);
    return dp[o][tw][th] = ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    a.resize(n, 0);
    c.resize(4, 0);
    dp.resize(n+1, vector<vector<ld>>(n+1, vector<ld>(n+1, -1)));
    dp[0][0][0] = 0;
    f(i, n) cin >> a[i], c[a[i]]++;
    cout << fixed << setprecision(10) << solve(c[0], c[1], c[2], c[3]) << ln;

    return 0;
}