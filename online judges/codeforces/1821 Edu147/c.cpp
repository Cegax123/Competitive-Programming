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
        string s; cin >> s;
        int n = s.size();
        int global = n;
        for(char c = 'a'; c <= 'z'; c++) {
            vi pos(1, -1);
            for(int i = 0; i < n; i++) 
                if(s[i] == c) pos.pb(i);
            pos.pb(n);

            int mx_diff = 0;

            for(int i = 1; i < (int) pos.size(); i++)
                mx_diff = max(mx_diff, pos[i]-pos[i-1]-1);

            int ans = 0;
            while(mx_diff) {
                mx_diff /= 2;
                ans++;
            }

            global = min(global, ans);
        }

        cout << global << "\n";
    }

	
    return 0;
}


