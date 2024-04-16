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

        auto cmp = [](const string& x) {
            int sum = 0;

            for(char c : x) {
                sum += (c == '(' ? 1 : -1);
                if(sum < 0) return false;
            }
            return sum == 0;
        };

        if(cmp(s)) {
            cout << 1 << "\n";
            for(int i = 1; i <= n; i++)
                cout << 1 << " ";
            cout << "\n";
            continue;
        }

        reverse(all(s));

        if(cmp(s)) {
            cout << 1 << "\n";
            for(int i = 1; i <= n; i++)
                cout << 1 << " ";
            cout << "\n";
            continue;
        }

        reverse(all(s));
        
        set<int> open;
        set<int> closed;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') open.insert(i);
            else closed.insert(i);
        }

        int col[n];
        int ans = -1;
        while(true) {
            if(open.empty() and closed.empty()) {
                ans = 0;
                break;
            }
            if(open.empty() and !closed.empty()) break;
            if(!open.empty() and closed.empty()) break;

            int o = *open.begin(), c = *closed.begin();

            if(o < c) {
                int y = *closed.rbegin();
                col[o] = col[y] = 1;

                open.erase(o);
                closed.erase(y);
            }
            else {
                int y = *open.rbegin();
                col[y] = col[c] = 2;

                open.erase(y);
                closed.erase(c);
            }
        }

        if(ans == -1) cout << -1 << "\n";
        else {
            cout << 2 << "\n";

            for(int i = 0; i < n; i++)
                cout << col[i] << " ";
            cout << "\n";
        }
    }
	
    return 0;
}


