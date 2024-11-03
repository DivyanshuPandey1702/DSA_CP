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

vector<vector<int>> dp;
vector<int> a;
int n, h, l, r;

int solve(int i, int t) {
    if(i >= n) return 0;
    if(dp[i][t] != -1) return dp[i][t];
    int x = ((l <= ((t+a[i])%h) && ((t+a[i])%h) <= r) ? 1 : 0) + solve(i+1, (t+a[i])%h);
    int y = ((l <= ((t+a[i]-1)%h) && ((t+a[i]-1)%h) <= r) ? 1 : 0) + solve(i+1, (t+a[i]-1)%h);
    return dp[i][t] = max(x, y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h >> l >> r;
    a.resize(n);
    dp.resize(n + 1, vector<int>(h + 1, -1));
    f(i, n) cin >> a[i];
    cout << solve(0, 0) << "\n";

    return 0;
}