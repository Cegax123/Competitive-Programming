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
        int lastb = -1;
        int pos = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'A' and pos == -1) pos = i;
            if(s[i] == 'B') lastb = i;
        }

        if(lastb == -1 or pos == -1 or pos > lastb) {
            cout << 0 << "\n";
        }
        else {
            cout << lastb-pos << "\n";
        }
    }

	
    return 0;
}


