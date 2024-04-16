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
    int n; cin >> n;
    bool poss = 1;

    int p1 = 1, p2 = 2;

    for(int i = 1; i <= n; i++) {
        int winner; cin >> winner;
        if(winner != p1 and winner != p2) {
            poss = 0;
        }
        else {
            if(winner == p1) p2 = 6-p1-p2;
            else p1 = 6-p1-p2;
        }
    }

    cout << (poss ? "YES\n" : "NO\n");
	
    return 0;
}


