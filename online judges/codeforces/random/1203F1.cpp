#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, r; cin >> n >> r;
    vii good, bad;

    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if(b >= 0) good.push_back(make_pair(a, b));
        else bad.push_back(make_pair(a, b));
    }

    sort(all(good));

    auto cmp = [] (ii& a, ii &b) {
        return a.first+a.second > b.first+b.second;
    };

    sort(all(bad), cmp);

    vii tasks;

    for(auto x : good) tasks.pb(x);
    for(auto x : bad) tasks.pb(x);

    bool flag = 1;

    for(int i = 0; i < n; i++) {
        if(r >= tasks[i].first) {
            r += tasks[i].second;
            if(r < 0) flag = 0;
        }
        else flag = 0;
    }

    cout << (flag ? "YES\n" : "NO\n");

    return 0;
}



