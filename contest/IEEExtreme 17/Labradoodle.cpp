#include<bits/stdc++.h>
#define pb push_back
#define all(c) (c).begin(), (c).end()
using namespace std;
typedef vector<int> vi;

const int E = 26;
const int SUML = 500000 + 5;

int ptrie[SUML][E];
int pval[SUML];
int pnodes = 1;

int strie[SUML][E];
int sval[SUML];
int snodes = 1;

int main() {
    int n, m; cin >> n >> m;

    vector<string> qq;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        qq.pb(s);

        int pos = 0;
        for(char c : s) {
            int nxt = c-'a';
            
            if(ptrie[pos][nxt] == 0) {
                ptrie[pos][nxt] = pnodes++;
                pval[ptrie[pos][nxt]] = i+1;
            }

            pos = ptrie[pos][nxt];
            if(pval[pos] != i+1) pval[pos] = -1;
        }

        pos = 0;
        for(int j = (int) s.size()-1; j >= 0; j--) {
            int nxt = s[j]-'a';

            if(strie[pos][nxt] == 0) {
                strie[pos][nxt] = snodes++;
                sval[strie[pos][nxt]] = i+1;
            }

            pos = strie[pos][nxt];
            if(sval[pos] != i+1) sval[pos] = -1;
        }
    }

    for(int i = 0; i < m; i++) {
        string t; cin >> t;
        int k = t.size();
        vi pp(t.size(), 0), ss(t.size(), 0);

        int pos = 0;
        for(int i = 0; i < k; i++) {
            int nxt = t[i]-'a';
            pos = ptrie[pos][nxt];
            if(pos == 0) break;

            pp[i] = pval[pos];
        }

        pos = 0;
        for(int i = k-1; i >= 0; i--) {
            int nxt = t[i]-'a';
            pos = strie[pos][nxt];
            if(pos == 0) break;

            ss[i] = sval[pos];
        }

        vector<pair<int, int>> x;
        bool cmp = 1;
        for(int i = 2; i + 3 < k; i++) {
            if(pp[i] != 0 and ss[i+1] != 0) {
                x.pb({pp[i], ss[i+1]});
                if(pp[i] == -1 or ss[i+1] == -1) cmp = 0;
            }
        }

        for(int i = 2; i+2 < k; i++) {
            if(pp[i] != 0 and ss[i] != 0) {
                x.pb({pp[i], ss[i]});
                if(pp[i] == -1 or ss[i] == -1) cmp = 0;
            }
        }

        if(x.empty()) {
            cout << "none\n";
            continue;
        }

        sort(all(x));

        vector<pair<int, int>> cl;

        for(int i = 0; i < (int) x.size(); i++) {
            if(i == 0 or x[i] != x[i-1]) cl.pb(x[i]);
        }

        if((int) cl.size() > 1) cmp = 0;
        
        if(!cmp) {
            cout << "ambiguous\n";
            continue;
        }

        cout << qq[cl[0].first-1] << " " << qq[cl[0].second-1] << "\n";
    }

    return 0;
}
