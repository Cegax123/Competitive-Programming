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
        int l = 1, r = 1;
        string s; cin >> s;

        for(int i = 0; i < n-1; i++) {
            r++;
            if(s[i] == '0') {
                l = 1; r--;
            }
            else {
                l++; r = i+2;
            }
            cout << r-l+1 << " ";
        }

        cout << "\n";
    }

	
    return 0;
}


