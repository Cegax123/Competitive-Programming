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
    int h, w; cin >> h >> w;

    vector<string> vs;
    for(int i = 0; i < h; i++) {
        string s;

        for(int j = 0; j < w; j++) {
            int x; cin >> x;
            if(x == 0) s += '.';
            else s += (char) 'A' + x - 1;
        }

        cout << s << "\n";
    }

    return 0;
}


