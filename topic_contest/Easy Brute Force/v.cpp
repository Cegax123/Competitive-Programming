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
    int n, m; cin >> n >> m;
    string s; cin >> s;

    for(int i = 0; i < m; i++) {
        int l, r; char c1, c2; cin >> l >> r >> c1 >> c2;
        l--; r--;

        for(int j = l; j <= r; j++) {
            if(s[j] == c1) s[j] = c2;
        }
    }

    cout << s << "\n";
	
    return 0;
}


