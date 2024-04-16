#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

bool isP(int x) {
    if(x <= 1) return false;

    for(int i = 2; i * i <= x; i++)
        if(x % i == 0) return false;
    return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vi powers;

    for(int i = 2; i < 70; i++)
        if(!isP(i)) powers.pb(i);
	
    vector<ull> ans;

    for(ull i = 2; i < 1e5; i++) {
        ull num = 1;
        int curr = 0;
        for(int x : powers) {
            while(curr < x) {
                ull nxt = num * i;
                if(nxt / i != num) break;
                num = nxt;
                curr++;
            }

            if(curr < x) break;
            ans.pb(num);
        }
    }

    ans.pb(1);
    sort(all(ans));

    ans.erase(unique(all(ans)), ans.end());

    for(ull x : ans) cout << x << "\n";

    return 0;
}


