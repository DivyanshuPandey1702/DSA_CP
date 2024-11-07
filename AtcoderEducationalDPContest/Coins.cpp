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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long double> p(n, 0);
    f(i, n) cin >> p[i];

    vector<vector<long double>> dp(n+1, vector<long double>(n+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = (long double)(1 - p[i-1]) * dp[i-1][j];
            if(j > 0) dp[i][j] += p[i-1] * dp[i-1][j-1];
        }
    }

    long double ans = 0;
    for(int i = (n/2)+1; i <= n; i++) {
        ans += dp[n][i];
    }
    cout << fixed << setprecision(10) << ans << ln;

    return 0;
}