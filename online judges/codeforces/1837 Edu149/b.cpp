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
        string s; cin >> s;

        int cnt = 0;

        int ind = 0;

        while(ind < n) {
            char curr = s[ind];
            int x = 0;
            while(ind < n and s[ind] == curr) {
                ind++;
                x++;
            }
            
            cnt = max(x, cnt);
        }

        cout << cnt+1 << "\n";
    }

    // SUBMISSION 2
	
    return 0;
}


