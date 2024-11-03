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
    
    int n, m;
    cin >> n >> m;
    vi d(n, 0), a(n, 0);
    vector<vi> g(n, vi(0));
    vector<bool> vis(n, 0);
    f(i, m) {
        int x, y;
        cin >> x >> y;
        d[y-1]++;
        g[x-1].push_back(y-1);
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(d[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int i = q.front();
        q.pop();
        for(int j = 0; j < g[i].size(); j++) {
            d[g[i][j]]--;
            a[g[i][j]] = max(a[g[i][j]], 1 + a[i]);
            if(d[g[i][j]] == 0) q.push(g[i][j]);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, a[i]);
    }
    cout << ans << ln;

    return 0;
}