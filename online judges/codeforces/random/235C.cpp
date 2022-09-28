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

struct state {
    int len, link;
    map<char, int> next;
};

const int MAXLEN = 1e5 + 5;
state st[MAXLEN * 2];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;

    while(p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }

    if(p == -1) {
        st[cur].link = 0;
    }
    else {
        int q = st[p].next[c];
        if(st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        }
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while(p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

ll d[MAXLEN * 2];
vi tmp;
bool term[MAXLEN * 2], vis[MAXLEN * 2];

void calc(int v) {
    if(d[v] != -1) return;

    if(term[v]) d[v] = 1;
    else d[v] = 0;

    for(char c = 'a'; c <= 'z'; c++) {
        if(st[v].next.count(c)) {
            int to = st[v].next[c];
            calc(to);

            d[v] += d[to];
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s; cin >> s;
    int q; cin >> q;

    sa_init();
    for(char c : s) sa_extend(c);

    memset(d, -1, sizeof(d));

    tmp.pb(last);

    while(st[tmp.back()].link != -1) 
        tmp.pb(st[tmp.back()].link);

    for(int x : tmp) term[x] = 1;

    calc(0);

    while(q--) {
        string t; cin >> t;
        int k = t.size();

        t += t;
        t.pop_back();

        int p = 0;
        vi nodes;

        for(int i = 0; i < (int) t.size(); i++) {
            while(p != -1 and !st[p].next.count(t[i])) {
                p = st[p].link;
            }
            if(p == -1) p = 0;
            else p = st[p].next[t[i]];
            
            while(p != 0 and st[st[p].link].len >= k) {
                p = st[p].link;
            }

            if(i >= k-1 and st[p].len >= k) {
                cout << i << " " << p << endl;
                nodes.pb(p);
            }
        }

        ll ans = 0;
        for(int x : nodes) {
            cout << x << endl;

            if(!vis[x]) ans += d[x];
            vis[x] = 1;
        }

        cout << endl;

        for(int x : nodes)
            vis[x] = 0;

        cout << ans << "\n";
    }
	
    return 0;
}


