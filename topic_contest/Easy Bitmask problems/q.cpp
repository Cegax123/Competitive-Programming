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
    const int E = 26;

    int mask = (1 << E) - 1;

    auto unique = [&]() {
        return (mask&(mask-1)) == 0;
    };

    int ans = 0;
    int q; cin >> q;
    while(q--) {
        char op; cin >> op;

        if(op == '!') {
            if(unique()) ans++;
            string w; cin >> w;


            int sub = 0;

            for(char c : w)
                sub |= (1 << (c-'a'));

            mask &= sub;
        }
        else if(op == '.') {
            string w; cin >> w;

            int sub = 0;
            for(char c : w)
                sub |= (1 << (c-'a'));

            sub = ~sub;

            mask &= (sub);
        }
        else {
            char c; cin >> c;
            if(unique() and mask != (1 << (c-'a'))) ans++;

            mask &= ~(1 << (c-'a'));
        }
    }

    cout << ans << "\n";
	
    return 0;
}


