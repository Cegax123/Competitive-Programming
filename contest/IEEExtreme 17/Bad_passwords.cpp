#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back

const int SUML = 25000 + 5;
map<char, int> trie[SUML];
int val[SUML];
int h[SUML];
int nodes = 1;

int main() {
    int n; cin >> n;

    set<pair<int, int>> poss;
    for(int i = 1; i <= n; i++) {
        int m; cin >> m;
        vi curr;
        for(int j = 0; j < m; j++) {
            string s; cin >> s;

            int pos = 0;
            for(char c : s) {
                if(trie[pos][c] == 0) {
                    trie[pos][c] = nodes++;
                    h[trie[pos][c]] = h[pos]+1;
                }
                pos = trie[pos][c];
            }
            curr.pb(pos);
        }

        for(int j = 0; j < m; j++) {
            for(int k = j+1; k < m; k++) {
                int x = min(curr[j], curr[k]);
                int y = max(curr[j], curr[k]);

                poss.insert({x, y});
            }
        }
    }
    
    int q; cin >> q;
    while(q--) {
        string a, b; cin >> a >> b;
        int r1 = a.size()-1, r2 = b.size()-1;

        while(r1 >= 0 and r2 >= 0 and a[r1] == b[r2]) { 
            r1--;
            r2--;
        }

        bool cmp = 0;
        for(int i = 0; i < min((int) a.size(), (int) b.size()); i++) {
            vector<pair<int, int>> s1, s2;
            int pos = 0;

            for(int j = 0; j < 10; j++) {
                if(i + j >= (int) a.size()) break;
                pos = trie[pos][a[i+j]];
                if(pos == 0) break;

                //if(val[pos] == 6) cout << i << " " << j << endl;

                if(i+j+1 > r1) {
                    s1.pb({pos, (int) a.size() - (i+j+1)});
                }
            }

            pos = 0;

            for(int j = 0; j < 10; j++) {
                if(i + j >= (int) b.size()) break;
                pos = trie[pos][b[i+j]];
                if(pos == 0) break;
                
                if(i+j+1 > r2) {
                    s2.pb({pos, (int) b.size() - (i+j+1)});
                }
            }

            for(auto e : s1) {
                for(auto p : s2) {
                    if(e.second != p.second) continue;
                    int x = min(e.first, p.first);
                    int y = max(e.first, p.first);

                    if(poss.count({x, y})) cmp = 1;
                }
            }

            if(a[i] != b[i]) break;
        }

        cout << (cmp ? "REJECT\n" : "OK\n");
    }

    return 0;
}
