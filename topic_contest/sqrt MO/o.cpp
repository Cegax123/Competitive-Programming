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

const int maxn = 3e5 + 5;
const int B = 700;

int n, q;
ll a[maxn];



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r; cin >> l >> r;
            l--; r--;

            
        }
        else {
            int l, r; cin >> l >> r;
            l--; r--;

            
        }
    }
	
    return 0;
}


