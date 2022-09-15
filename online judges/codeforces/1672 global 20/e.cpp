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
 
    int l = 1, r = 4e6 + 2000;
    
    while(l < r) {
        int m = (l+r) >> 1;
 
        cout << "? " << m << endl;
        
        int ans; cin >> ans;
 
        if(ans == 1) r = m;
        else l = m+1;
    }
 
    int L = l;
        
    for(int i = 2; i <= n; i++) {
        int target = (L % i == 0 ? L - i : (L/i)  * i);
        int w = target / i;
 
        if(w > 0) {
            cout << "? " << w << endl;
            int ans; cin >> ans;
 
            if(ans) L = min(L, ans * w);
        }
    }
 
    cout << "! " << L << endl;
	
    return 0;
}
 
