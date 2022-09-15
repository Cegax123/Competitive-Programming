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

const int maxn = 5e4 + 5;
const int B = 275;
const ll INF = (ll) 1e18;

int a[maxn];
int id[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        id[i] = i / B;
    }

    ll maxel[B];

    for(int i = 0; i < B; i++) {
        int lb = i * B;
        if(lb > n) continue;
        int rb = min(n-1, lb+B-1);

        maxel[B] = 
    }

    int m; cin >> m;
    while(m--) {
        int op; cin >> op;
        if(op == 0) {
        }
    }
	
    return 0;
}


