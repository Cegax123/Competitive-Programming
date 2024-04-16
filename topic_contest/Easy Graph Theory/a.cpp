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
    int n; cin >> n;
    vi cnt(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            cnt[i] += x;
            cnt[j] += x;
        }
    }

    for(int i = 0; i < n; i++)
        cout << cnt[i]/2 << " ";

	
    return 0;
}


