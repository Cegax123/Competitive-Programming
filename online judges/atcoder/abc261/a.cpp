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
    int l, r, a, b; cin >> l >> r >> a >> b;

    int cnt = 0;
    for(int i = 0; i <= 100; i++) {
        if(l <= i and i <= r and a <= i and i <= b) {
            cnt++;
        }
    }

    if(cnt > 0) cnt -= 1;
    cout << cnt << "\n";
	
    return 0;
}


