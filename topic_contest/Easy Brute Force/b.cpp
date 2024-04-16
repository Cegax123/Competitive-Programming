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
    int n, a, b, c, d; cin >> n >> a >> b >> c >> d;

    ii p = {1, n};

    auto uni = [](ii a, ii b) {
        return make_pair(max(a.first, b.first), min(a.second, b.second));
    };

    p = uni(p, {1 - (b-c), n - (b-c)});
    p = uni(p, {1 - (a-d), n - (a-d)});
    p = uni(p, {1 - (b-c+a-d), n - (b-c+a-d)});

    if(p.first <= p.second) {
        cout << (p.second-p.first+1) * 1ll * n << "\n";
    }
    else cout << 0 << "\n";
	
    return 0;
}


