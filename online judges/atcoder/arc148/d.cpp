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
    int n, M; cin >> n >> M;
    map<int, int> parity;

    for(int i = 0; i < 2 * n; i++) {
        int a; cin >> a;
        parity[a] ^= 1;
    }

    set<int> a;
    for(auto e : parity) {
        if(e.second) a.insert(e.first);
    }

    if(a.empty()) {
        cout << "Bob\n";
        return 0;
    }

    if(M&1) {
        cout << "Alice\n";
        return 0;
    }

    int edges = 0;
    for(int x : a) {
        int y = (x + M / 2) % M;
        if(!a.count(y)) {
            cout << "Alice\n";
            return 0;
        }
        edges ++;
    }

    if(edges%4 == 0) cout << "Bob\n";
    else cout << "Alice\n";

    return 0;
}


