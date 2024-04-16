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
    int p, u; cin >> p >> u;
    int n = p + u;
    vi sp(p), su(u);

    vector<bool> marked(n+1, 0);

    for(int i = 0; i < p; i++) cin >> sp[i];
    for(int i = 0; i < u; i++) cin >> su[i];


    reverse(all(su));

    int x, y; cin >> x >> y;

    vi ep(x), eu(y);

    for(int i = 0; i < x; i++) cin >> ep[i];
    //sort(all(ep));

    for(int i = 0; i < y; i++) cin >> eu[i];
    reverse(all(eu));
    //sort(all(eu));

    int pos[n+1];

    for(int i = 0; i < x; i++)
        pos[ep[i]] = i;

    for(int i = 0; i < y; i++) 
        pos[eu[i]] = i;

    for(int t : ep) marked[t] = 1;

    vi sta; deque<int> fina;
    vi stb; deque<int> finb;

    for(int t : sp) {
        if(!marked[t]) sta.pb(pos[t]);
        else finb.pb(pos[t]);
    }

    for(int t : su) {
        if(!marked[t]) fina.pb(pos[t]);
        else stb.pb(pos[t]);
    }

    //for(int t : sta) cout << t << " ";
    //cout << endl;
    //for(int t : fina) cout << t << " ";
    //cout << endl << endl;

    //for(int t : stb) cout << t << " ";
    //cout << endl;
    //for(int t : finb) cout << t << " ";
    //cout << endl << endl;

    auto get = [](vi st, deque<int> fin) {
        int k = st.size() + fin.size();

        vi lft(k, 0);

        for(int x : st) lft[x] = 1;

        int ans = 0;

        for(int i = 0; i < k; i++) {
            if(!lft[i]) {
                while(fin[0] != i) {
                    lft[fin[0]] = 1;
                    fin.pop_front();
                    ans++;
                }
                fin.pop_front();
            }
            else if(lft[i]) {
                while(!fin.empty()) {
                    ans++;
                    lft[fin.back()] = 1;
                    fin.pop_back();
                }
                ans++;
            }
        }

        return ans;
    };

    //cout << get(sta, fina) << "\n";
    //cout << get(stb, finb) << "\n";

    cout << get(sta, fina) + get(stb, finb) << endl;
    return 0;
}


