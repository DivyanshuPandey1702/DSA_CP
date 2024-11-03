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
    vi h(n, 0);
    f(i, n) cin >> h[i];
    ll dp[n];
    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);
    for(int i = 2; i < n; i++) {
        dp[i] = min(dp[i-1]+ abs(h[i] - h[i-1]), dp[i-2]+ abs(h[i]-h[i-2]));
    }
    cout << dp[n-1] << ln;

    return 0;
}