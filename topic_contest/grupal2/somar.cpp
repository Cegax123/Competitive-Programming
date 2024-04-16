#include<bits/stdc++.h>
#define pb push_back
#define all(c) (c).begin(), (c).end()
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
   return uniform_int_distribution<long long>(l,r)(rng);
}


const int maxn = 50005;

pair<int, int> t[4 * maxn];

int b[2];
int pb[2][maxn];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = {0, 0};
    }
    else {
        int tm = (tl+tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);
        t[v] = {0, 0};
    }
}

void update(int v, int tl, int tr, int pos, pair<int, int> delta) {
    if(tl == tr) {
        t[v].first = (t[v].first + delta.first) % mod;
        t[v].second = (t[v].second + delta.second) % mod;
    }
    else {
        int tm = (tl+tr) >> 1;
        if(pos <= tm) update(v * 2, tl, tm, pos, delta);
        else update(v * 2+1, tm+1, tr, pos, delta);

        t[v].first = (t[v * 2].first + t[v * 2 + 1].first) % mod;
        t[v].second = (t[v * 2].second + t[v * 2 + 1].second) % mod;
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l) return {0, 0};
    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        int tm = (tl+tr) >> 1;
        auto q1 = query(v * 2, tl, tm, l, min(r, tm));
        auto q2 = query(v * 2 + 1, tm+1, tr, max(tm+1, l), r);

        return {(q1.first+q2.first)%mod, (q1.second+q2.second)%mod};
    }
}

void gen() {
    for(int i = 0; i < 2; i++) {
        b[i] = random(0, mod-1);
        pb[i][0] = b[i];
        for(int j = 1; j < maxn; j++) {
            pb[i][j] = pb[i][j-1] * 1ll * b[i] % mod;
        }
    }
}

int main(){
    gen();

    int t;
    cin>>t;
    while(t--){
        int n,v;
        cin>>n>>v;
        vector<int> h(n);
        vector<pair<int,int>> sweep1,sweep2;
        for(int i=0;i<n;i++){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            if(x1>x2) swap(x1,x2);
            if(y1>y2) swap(y1,y2);
            sweep1.pb({x1,i});
            h[i]=y2-y1;
        }
        for(int i=0;i<n;i++){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            if(x1>x2) swap(x1,x2);
            if(y1>y2) swap(y1,y2);
            sweep2.pb({x1,i});
        }
        sort(all(sweep1));
        sort(all(sweep2));

        vector<int> d;
        for(int i = 0; i < n; i++) d.push_back(h[i]);

        sort(d.begin(), d.end());
        d.erase(unique(d.begin(), d.end()), d.end());

        int k = d.size();

        build(1, 0, k-1);

        vector<ll> H1(n);
        for(int i = 0; i < n; i++) {
            int x = sweep1[i].second;

            int l = 0, r = (int) d.size()-1;

            while(l < r) {
                int m = (l+r) >> 1;
                if(d[m] > v-h[x]) r = m;
                else l = m+1;
            }

            if(d[l] > v-h[x]) {
                auto q = query(1, 0, k-1, l, k-1);
                H1[x] = q.first * 1ll * mod + q.second;
            }

            else H1[x] = 0;

            int ind = lower_bound(all(d), h[x]) - d.begin();
            update(1, 0, k-1, ind, {pb[0][ind], pb[1][ind]});
        }

        build(1, 0, k-1);
        vector<ll> H2(n);
        for(int i = 0; i < n; i++) {
            int x = sweep2[i].second;

            int l = 0, r = (int) d.size()-1;

            while(l < r) {
                int m = (l+r) >> 1;
                if(d[m] > v-h[x]) r = m;
                else l = m+1;
            }

            if(d[l] > v-h[x]) {
                auto q = query(1, 0, k-1, l, k-1);
                H2[x] = q.first * 1ll * mod + q.second;
            }
            else H2[x] = 0;

            int ind = lower_bound(all(d), h[x]) - d.begin();

            update(1, 0, k-1, ind, {pb[0][ind], pb[1][ind]});
        }

        bool cmp = 1;
        for(int i = 0; i < n; i++) if(H1[i] != H2[i]) cmp = 0;

        cout << (cmp ? "ANO\n" : "NIE\n");
    }

    return 0;
}