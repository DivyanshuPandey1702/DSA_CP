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
    
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
        }
    }

    string ans = "";

    while(n > 0 && m > 0) {
        if(s[n-1] == t[m-1]) {
            ans += s[n-1];
            n--;
            m--;
        }else {
            if(dp[n-1][m] >= dp[n][m-1]) n--;
            else m--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << ln;

    return 0;
}