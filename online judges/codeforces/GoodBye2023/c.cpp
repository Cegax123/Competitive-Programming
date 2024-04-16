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
        ll p[n];

        int other = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            p[i] = a[i];
            if(i) p[i] += p[i-1];
            a[i] %= 2;

            if(a[i]) cnt++;
            else other++;

            if(cnt == 0) cout << p[i] << " ";
            else if(cnt == 1) {
                if(other) cout << p[i]-1 << " ";
                else cout << p[i] << " ";
            }
            else if(cnt == 2) cout << p[i] << " ";
            else {
                int x = (cnt-1)/3+1;
                if(cnt % 3 == 2) x--;
                cout << p[i]-x << " ";
            }
        }

        cout << "\n";
    }

	
    return 0;
}


