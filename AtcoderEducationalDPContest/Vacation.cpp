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
    vector<vector<ll>> v(n, vector<ll>(3, 0));
    for(int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1] >> v[i][2];

    for(int i = 1; i < n; i++) {
        v[i][0] += max(v[i-1][1], v[i-1][2]);
        v[i][1] += max(v[i-1][0], v[i-1][2]);
        v[i][2] += max(v[i-1][0], v[i-1][1]);
    }

    cout << max(v[n-1][0], max(v[n-1][1], v[n-1][2])) << ln;

    return 0;
}