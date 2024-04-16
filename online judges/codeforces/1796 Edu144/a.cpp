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

        string fb = "FBFFBFFB";
        bool ans = 0;
        for(int i = 0; i < (int) fb.size(); i++) {
            bool cmp = 1;
            for(int j = 0; j < n; j++) {
                if(s[j] != fb[(i + j) % (int) fb.size()]) cmp = 0;
            }
            if(cmp) ans = 1;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
	
    return 0;
}


