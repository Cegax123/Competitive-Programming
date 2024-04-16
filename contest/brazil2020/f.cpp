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
    string s; cin >> s;

    int p[2];
    p[0] = p[1] = 0;
    int c = 0;

    int g[2];

    g[0] = g[1] = 0;

    auto func = [&](int curr) {
       p[curr]++;

        if(p[curr] == 10 or (p[curr] >= 5 and p[curr] - p[1-curr] >= 2)) {
            g[curr]++;
            p[0] = p[1] = 0;
        }
    };

    for(char z : s) {
        if(z == 'S' or z == 'R') {
            if(z == 'R') c = 1-c;
            func(c);
        }
        else {
            if(g[c] == 2 or g[1-c] == 2) {
                cout << g[0] << " " << (g[0] == 2 ? "(winner)" : "") << " - ";
                cout << g[1] << " " << (g[1] == 2 ? "(winner)" : "") << "\n";
            }
            else {
                cout << g[0] << " " << "(" << p[0] << (c == 0 ? "*" : "") << ")" << " - ";
                cout << g[1] << " " << "(" << p[1] << (c == 1 ? "*" : "") << ")" << "\n";
            }
        }
    }

	
    return 0;
}


