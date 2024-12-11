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
    vector<int> a(n);
    f(i, n) cin >> a[i];

    vector<int> dp(k + 1, 0);
    dp[0] = 0;
    for(int i = 1; i <= k; i++) 
        for(int j = 0; j < n; j++) 
            if(i - a[j] >= 0) dp[i] |= !dp[i - a[j]];

    if(dp[k]) cout << "First" << ln;
    else cout << "Second" << ln;

    return 0;
}