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
    
    int n, k;
    cin >> n >> k;
    vector<ll> dp(n, INT_MAX), h(n, 0);
    f(i, n) cin >> h[i];
    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        for(int j = i-1; j >= max(i-k, 0); j--) {
            dp[i] = min(dp[i], dp[j] + abs(h[i]-h[j]));
        }
    }
    cout << dp[n-1] << ln;


    return 0;
}