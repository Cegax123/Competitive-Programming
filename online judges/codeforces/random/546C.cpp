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
    int x = 1;

    for(int i = 1; i <= 10; i++) {
        x *= i;
    }

	x *= 2;

    int n; cin >> n;

    deque<int> a, b;

    int k; cin >> k;

    for(int i = 0; i < k; i++) {
        int p; cin >> p;
        a.pb(p);
    }

    cin >> k;

    for(int i = 0; i < k; i++) {
        int p; cin >> p;
        b.pb(p);
    }

    bool comp = 0;
    int ans = 0;
    int winner = 1;

    for(int i = 1; i <= x; i++) {
        int x1 = a.front(), x2 = b.front();
        a.pop_front(); b.pop_front();

        if(x1 > x2) {
            a.push_back(x2);
            a.push_back(x1);
        }
        else {
            b.push_back(x1);
            b.push_back(x2);
        }

        if(a.empty() or b.empty()) {
            comp = 1;
            ans = i;
            if(a.empty()) winner = 2;
            break;
        }
    }

    if(comp) cout << ans << " " << winner << "\n";
    else cout << -1 << "\n";
	
	return 0;
}

