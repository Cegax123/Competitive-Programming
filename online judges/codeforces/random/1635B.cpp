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
        int a[n];

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int cnt = 0;

        bool marked[n];
        memset(marked, 0, sizeof(marked));

        for(int i = 1; i < n-1; i++) {
            if(a[i] > a[i-1] and a[i] > a[i+1]) {
                marked[i] = 1;
            }
        }

        for(int i = 1; i < n-1; i++) {
            if(marked[i-1] and marked[i+1]) {
                cnt++;
                a[i] = max(a[i-1], a[i+1]);
                marked[i-1] = marked[i+1] = 0;
            }
        }

        for(int i = 1; i < n-1; i++) {
            if(marked[i]) {
                cnt++;
                a[i] = max(a[i-1], a[i+1]);
            }
        }

        cout << cnt << "\n";

        for(int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
	
	
	return 0;
}

