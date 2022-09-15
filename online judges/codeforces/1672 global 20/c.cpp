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

        vi b;
        int ind = 0;
        
        while(ind < n) {
            int curr = a[ind];
            int cnt = 0;

            while(ind < n and curr == a[ind]) {
                cnt++;
                ind++;
            }

            b.pb(cnt);
        }

        bool cmp = 1;
        int cnt2 = 0;

        for(int x : b) {
            if(x == 2) cnt2++;
            if(x > 2) cmp = 0;
        }

        if(cnt2 > 1) cmp = 0;

        if(cmp) {
            cout << 0 << "\n";
            continue;
        }

        int l = -1, r = -1;

        for(int i = 0; i < (int) b.size(); i++) {
            if(b[i] > 1) {
                if(l == -1) l = i;
                r = i;
            }
        }

        if(l == r and b[l] == 3) {
            cout << "1\n";
            continue;
        }

        int sum = 0;

        for(int i = l; i <= r; i++)
            sum += b[i];

        cout << sum - 3 << "\n";
    }

	
    return 0;
}


