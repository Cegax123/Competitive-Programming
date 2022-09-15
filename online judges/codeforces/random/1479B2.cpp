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
    int b[n];

    for(int i = 0; i < n; i++)
        cin >> b[i];
	
    vi a;
    int ind = 0;

    while(ind < n) {
        int r = ind;
        a.pb(b[ind]);

        while(r < n and b[r] == b[ind]) {
            r++;
        }

        ind = r;
    }

    n = a.size();

    
	
	return 0;
}

