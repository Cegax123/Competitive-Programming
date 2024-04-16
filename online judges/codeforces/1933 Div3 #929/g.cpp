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

const int E = 8;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    auto cmp1 = [&](int st, int nw, int x, int y) {
        y /= 2;
        if((x+y) % 2 == 0) {
            if(nw != st) return false;
        }
        else {
            if(nw == st) return false;
        }
        return true;
    };

    auto cmp2 = [&](int st, int nw, int x, int y) {
        x /= 2;
        if((x+y) % 2 == 0) {
            if(nw != st) return false;
        }
        else {
            if(nw == st) return false;
        }
        return true;
    };

    auto cmp3 = [&](int st, int nw, int x, int y) {
        if(x == 0) {
            if(y % 2 == 0) {
                if(nw != st) return false;
            }
            else {
                if(nw == st) return false;
            }
            return true;
        }
        else {
            return cmp2((st^1), nw, x-1, y);
        }
    };

    auto cmp4 = [&](int st, int nw, int x, int y) {
        if(y == 0) {
            if(x % 2 == 0) {
                if(nw != st) return false;
            }
            else {
                if(nw == st) return false;
            }
            return true;
        }
        else {
            return cmp1((st^1), nw, x, y-1);
        }
    };

    int t; cin >> t;
    while(t--) {
        int n, m, q; cin >> n >> m >> q;

        vector<bool> poss(E, 1);
        cout << accumulate(all(poss), 0) << "\n";

        while(q--) {
            int r, c; cin >> r >> c;
            r--; c--;
            string shape; cin >> shape;
            int x = (shape == "circle" ? 0 : 1);

            if(!cmp1(0, x, r, c)) poss[0] = 0;
            if(!cmp2(0, x, r, c)) poss[1] = 0;
            if(!cmp3(0, x, r, c)) poss[2] = 0;
            if(!cmp4(0, x, r, c)) poss[3] = 0;
            if(!cmp1(1, x, r, c)) poss[4] = 0;
            if(!cmp2(1, x, r, c)) poss[5] = 0;
            if(!cmp3(1, x, r, c)) poss[6] = 0;
            if(!cmp4(1, x, r, c)) poss[7] = 0;
            
            cout << accumulate(all(poss), 0) << "\n";
        }
    }

	
    return 0;
}


