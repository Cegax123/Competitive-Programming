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
        vi a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        sort(all(a));
        reverse(all(a));

        int ind = 0;
        bool cmp = 0;

        while(ind < n) {
            int curr = a[ind];
            int cnt = 0;
            while(ind < n and curr == a[ind]) {
                cnt++;
                ind++;
            }
            if(cnt&1) cmp = 1;
        }

        cout << (cmp ? "Marichka\n" : "Zenyk\n");
    }

	
    return 0;
}


