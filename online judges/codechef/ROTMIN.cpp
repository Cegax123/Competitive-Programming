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
        int n, p, q; cin >> n >> p >> q;
        string s; cin >> s;

        const int E = 26;
        vi cntR(E, 0), cntL(E, 0);

        auto get_sum = [&](int x, const vi& cnt) {
            int ans = 0;

            for(int i = 0; i < E; i++) {
                int need = min(x, cnt[i]);
                x -= need;
                ans += need * i;
            }
            return ans;
        };

        auto cmp =[&](int x) {
            return get_sum(x, cntR) <= p;
        };

        vi toR(E, 0);
        int sumR = 0;
        int sumL = 0;

        int total = 0;
        string ans = "";
        for(int i = 0; i < n; i++) {
            int p = s[i]-'a';
            
            for(int c = 0; c < E; c++) {
                int R = (p <= c ? c-p : E + c-p);
                int L = (E-R)%E;

                if(L == 0 and R == 0) {
                    cout << s[i];
                    break;
                }

                char x = '#';

                if(sumR + R <= p) {
                    sumR += R;
                }
                else {
                    int ind = -1;
                    for(int i = 0; i < E; i++)
                        if(toR[i]) ind = i;
                    if(ind == -1) continue;
                    if(sumR-ind + R <= p and sumL + (26-ind) <= q) {
                        sumR += -ind+R;
                        sumL += 26-ind;
                        toR[ind]--;
                        toR[R]++;
                        x = c + 'a';
                    }
                }

                if(x != '#') {
                    cout << x;
                    break;
                }
            }
        }
        cout << "\n";
    }

	
    return 0;
}


