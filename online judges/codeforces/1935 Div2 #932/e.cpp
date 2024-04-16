#include<bits/stdc++.h>
using namespace std;

const int L = 20;
const int maxn = 2e5 + 100;
const int maxnodos = maxn * L;

int trie[maxnodos][2];
vector<int> s[maxnodos];
int nodes = 1;

void insert(int x, int j) {
    int pos = 0;
    for(int i = L-1; i >= 0; i--) {
        int nxt = (x>>i)&1;

        if(trie[pos][nxt] == 0) {
            trie[pos][nxt] = nodes++;
        }

        pos = trie[pos][nxt];
        s[pos].push_back(j);
    }
}

int find(int l, int r) {
    int pos = 0;
    int ans = 0;
     for(int i = L-1; i >= 0; i--) {
        int need = 1;
        int bit = 0;

        if(trie[pos][need] == 0) {
            pos = trie[pos][bit];
            continue;
        }

        int nxtpos = trie[pos][need];

        if(s[nxtpos].empty()) {
            pos = trie[pos][bit];
            continue;
        }

        bool can = false;
        int tl = 0, tr = s[nxtpos].size()-1;

        while(tl < tr) {
            //int tm = (tl+tr) >> 1;
            int tm = (tr-tl)/2 + tl;
            if(s[nxtpos][tm] >= l) tr = tm;
            else tl = tm+1;
        }

        if(s[nxtpos][tl] >= l and s[nxtpos][tl] <= r) can = true;

        if(can) {
            pos = trie[pos][need];
            ans |= (1 << i);
        }
        else {
            pos = trie[pos][bit];
        }
    }

     return ans;
}

pair<int, int> t[4 * maxn];
int mx[maxn];

pair<int, int> get_max(pair<int, int> a, pair<int, int> b) {
    vector<int> c;
    c.push_back(a.first);
    c.push_back(b.first);
    c.push_back(a.second);
    c.push_back(b.second);

    sort(c.begin(), c.end());

    return {c[3], c[2]};
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = {mx[tl], -1};
    }
    else {
        int tm = (tl+tr)>>1;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = get_max(t[v*2], t[v*2+1]);
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return {-1, -1};
    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        int tm =(tl+tr) >> 1;
        return get_max(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(tm+1, l), r));
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
        while(t--) {
        int n; cin >> n;
        int a[n], b[n];

        for(int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            int pref = 0;

            mx[i] = -1;
            for(int j = L-1; j >= 0; j--) {
                if(((x>>j)&1) == ((y>>j)&1)) {
                    int bit = (x>>i)&1;
                    pref |= (bit << i);
                }
                else {
                    mx[i] = j;
                    break;
                }
            }

            

            insert(pref, i+1);
            a[i] = x; b[i] = y;
        }

        build(1, 0, n-1);

        int q; cin >> q;
        while(q--) {
            int l, r; cin >> l >> r;

            if(l == r) {
                cout << b[l-1] << " ";
                continue;
            }

            int ans = find(l, r);
            auto mask = query(1, 0, n-1, l-1, r-1);

            cout << "MASK=" << mask.first << " " << mask.second << endl;

            if(mask.first != -1) ans |= (1 << mask.first);
            if(mask.second != -1) ans |= (1 << mask.second)-1;

              cout << ans << " ";
        }
        cout << "\n";
    }


    return 0;
}

