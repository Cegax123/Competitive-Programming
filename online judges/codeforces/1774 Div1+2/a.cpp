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

        for(int i = 1; i < n; i++) {
            if(s[i] == '1') cnt++;
        }

        int lmt;

        if(cnt&1) {
            if(s[0] == '1') {
                lmt = cnt/2;
            }
            else lmt = ((cnt+1)/2);
        }
        else lmt = cnt/2;

        int curr = 0;

        for(int i = 1; i < n; i++) {
            if(s[i] == '0') cout << "+";
            else {
                if(curr < lmt) {
                    cout << "+";
                    curr++;
                }
                else cout << "-";
            }
        }
        cout << "\n";
    }

	
    return 0;
}


