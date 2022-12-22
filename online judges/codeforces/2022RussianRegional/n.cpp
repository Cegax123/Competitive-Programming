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
        string s; cin >> s;
        int n = s.size();
        int k; cin >> k;

        vi pos[10];

        for(int i = 0; i < n; i++) 
            pos[s[i]-'0'].pb(i);

        for(int i = 0; i < 10; i++)
            reverse(all(pos[i]));

        int target = 0;
        string ans = "";

        int cif = n-k;
        
        for(int i = 0; i < cif; i++) {
            int x;
            for(int j = (i == 0 ? 1 : 0); j < 10; j++) {
                if(pos[j].empty()) continue;
                int p = pos[j].back();
                if(p-target <= k) {
                    k -= p-target;
                    x = j;
                    break;
                }
            }

            int posx = pos[x].back();
            cout << x;

            for(int j = 0; j < 10; j++) {
                while(!pos[j].empty() and pos[j].back() <= posx)
                    pos[j].pop_back();
            }
            
            target = posx+1;
        }

        cout << "\n";
    }

	
    return 0;
}


