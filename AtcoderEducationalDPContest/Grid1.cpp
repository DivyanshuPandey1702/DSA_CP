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
    
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> s(h, vector<bool>(w, 0));
    vector<vector<ll>> dp(h, vector<ll>(w, 0));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            char x;
            cin >> x;
            if(x == '.') s[i][j] = 1;
        }
    }

    dp[0][0] = 1;

    for(int i = 1; i < h; i++) {
        if(s[i][0]) {
            dp[i][0] = (dp[i][0] + dp[i-1][0]) % ((ll)mod);
        }
    }
    for(int i = 1; i < w; i++) {
        if(s[0][i]) {
            dp[0][i] = (dp[0][i] + dp[0][i-1]) % ((ll)mod);
        }
    }
    for(int i = 1; i < h; i++) {
        for(int j = 1; j < w; j++) {
            if(s[i][j]) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % ((ll)mod);
            }
        }
    }

    cout << dp[h-1][w-1] << ln;

    return 0;
}