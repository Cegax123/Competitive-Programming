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
    int n, k; cin >> n >> k;
    int x[k];

    for(int i = 0; i < k; i++) cin >> x[i];

    for(int i = 0; i < (1 << k); i++) {
        int num = 0;

        for(int j = 0; j < n; j++)
            if((i >> j)&1) num |= (1 << x[j]);

        cout << num << ": ";

        for(int j = 0; j < n; j++) {
            if((i >> j)&1) cout << x[j] << " ";
        }
        cout << "\n";
    }
	
    return 0;
}


