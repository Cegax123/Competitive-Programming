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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n], b[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        bool cmp = 1;
        for(int i = 0; i < n-1; i++) {
            bool curr = 0;
            if(a[i] <= a[n-1] and b[i] <= b[n-1]) curr = 1;
            if(a[i] <= b[n-1] and b[i] <= a[n-1]) curr = 1;
            if(!curr) cmp = 0;
        }

        cout << (cmp ? "Yes\n" : "No\n");
    }

	
    return 0;
}


