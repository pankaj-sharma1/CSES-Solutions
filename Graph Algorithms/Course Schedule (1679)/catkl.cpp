#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi topo_sort(const vector<vi>& gr) {
    vi indeg(sz(gr)), ret;
    trav(li, gr) trav(x, li) indeg[x]++;
    queue<int> q; // use priority queue for lexic. smallest ans.
    rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(-i);
    while (!q.empty()) {
        int i = -q.front(); // top() for priority queue
        ret.push_back(i);
        q.pop();
        trav(x, gr[i])
        if (--indeg[x] == 0) q.push(-x);
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    vector<vi> g(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
    }
    vi r=topo_sort(g);
    if (sz(r)<n)
        cout << "IMPOSSIBLE\n";
    else
        rep(i, 0, n) cout << r[i]+1 << " \n"[i==n-1];
    return 0;
}
