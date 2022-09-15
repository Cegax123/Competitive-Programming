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
    int n, k, q; cin >> n >> k >> q;
    int a[k+2];
    
    for(int i = 1; i <= k; i++)
        cin >> a[i];

    a[k+1] = n+1;

    while(q--) {
        int l; cin >> l;
        
        a[l]++;
        a[l] = min(a[l], a[l+1]-1);
    }

    for(int i = 1; i <= k; i++)
        cout << a[i] << " ";

    cout << "\n";
	
    return 0;
}


