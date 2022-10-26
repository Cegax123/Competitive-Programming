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
        string u, v; cin >> u >> v;
        int cntu = 0, cntv = 0;

        auto f = [](const string& s, int& cnt) {
            string res;
            for(char c : s) {
                if(c == 'B') cnt++;
                else res += c;
            }
            return res;
        };

        u = f(u, cntu); v = f(v, cntv);

        if(cntu % 2 != cntv % 2) {
            cout << "NO\n";
            continue;
        }

        auto redux = [](const string& s) {
            vector<char> A;

            for(char c : s) {
                if(!A.empty() and A.back() == c) {
                    A.pop_back();
                }
                else A.pb(c);
            }

            return A;
        };

        vector<char> A = redux(u), B = redux(v);

        if(A.size() != B.size()) {
            cout << "NO\n";
            continue;
        }

        bool cmp = 1;
        
        for(int i = 0; i < (int) A.size(); i++)
            if(A[i] != B[i]) cmp = 0;

        cout << (cmp ? "YES\n" : "NO\n");
    }

	
    return 0;
}


