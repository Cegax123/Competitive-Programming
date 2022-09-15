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

const int L = 30;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, c; cin >> n >> c;

    vector<pair<char, int> > op[L];

    for(int i = 0; i < n; i++) {
        int tp; cin >> tp;
        int a; cin >> a;
        int x = 0;

        for(int j = 0; j < 30; j++) {
            int b = (a >> j)&1;
            
            if(tp == 1 and b == 0) {
                op[j].clear();
                op[j].pb({'A', 0});
            }
            if(tp == 2 and b == 1) {
                op[j].clear();
                op[j].pb({'O', 1});
            }
            if(tp == 3) {
                if(op[j].empty() or op[j].back().first != 'X')
                    op[j].pb({'X', b});
                else 
                    op[j].back().second ^= b;
            }

            b = (c >> j)&1;
            for(auto e : op[j]) {
                if(e.first == 'A')
                    b = 0;
                if(e.first == 'O')
                    b = 1;
                if(e.first == 'X')
                    b ^= e.second;
            }
            if(b) x |= (1 << j);
        }

        cout << x << "\n";
        c = x;
    }
	
    return 0;
}


