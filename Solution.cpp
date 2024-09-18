#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x)
#else
#define debug(x);
#endif
#define all(a) a.begin(), a.end()
#define FORi(k,n) for (int i = k; i < n; ++i)
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define vi vector<int>
typedef long long ll;
void _print(auto x) { cerr << x << "\n";}
template<class T> void _print(vector<T> x) { cerr << " [ "; FORi(0, x.size()) { cerr << x[i] << " ";} cerr << "] \n";}
vector<vi> arr;

void solve() {
    int n;
    cin >> n;
    arr = vector<vi>(n, vi(n, 1));

    vi x = {0, 1, 0, -1};
    vi y = {1, 0, -1, 0};

    int r = 0, c = 0, fr = n, fc = n;
    int dir = 0;
    int orr = 0, occ = 0;
    r = orr, c = occ;
    int cnt = 3;
    int num = 0;
    while (1)
    {
        if (r == n / 2 and c == n / 2) break;
        num = n - cnt; cnt++;
        dir = (dir + 1) % 4;
        while (c < fc) {
            arr[r][c] = num;
            r = r + x[dir];
            c = c + y[dir];
        }
        // dir = (dir + 1) % 4;
        // while (r < fr) {
        //     arr[r][c] = num;
        //     r = r + x[dir];
        //     c = c + y[dir];
        // }
        // dir = (dir + 1) % 4;
        // while (c >= occ) {
        //     arr[r][c] = num;
        //     r = r + x[dir];
        //     c = c + y[dir];
        // }
        // dir = (dir + 1) % 4;
        // while (r > orr) {
        //     arr[r][c] = num;
        //     r = r + x[dir];
        //     c = c + y[dir];
        // }
        orr++; r = orr; c = occ;
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("Err.txt", "w", stderr);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}