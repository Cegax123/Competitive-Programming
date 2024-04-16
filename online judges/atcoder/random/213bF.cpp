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

vector<int> lcp_array(vector<int> &s, vector<int> &a){
    int n = s.size();
    vector<int> rank(n);
    for(int i = 0; i < n; i++) rank[a[i]] = i;
    int k = 0;
    vector<int> lcp(n);
    for(int i = 0; i < n; i++){
        if(rank[i] + 1 == n){
            k = 0;
            continue;
        }
        int j = a[rank[i] + 1];
        while(i + k < n and j + k < n and s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
        if(k) k--;
    }
    return lcp;
}

vector<int> suffix_array(vector<int> &s){
    int n = s.size();
    vector<int> a(n);
    vector<int> mapeo(n);
    iota(a.begin(), a.end(), 0);
    sort(a.begin(), a.end(), [&] (int i, int j){
        return s[i] < s[j];
    });
    mapeo[a[0]] = 0;
    for(int i = 1; i < n; i++){
        mapeo[a[i]] = mapeo[a[i - 1]] + (s[a[i - 1]] != s[a[i]]);
    }
    int len = 1;
    vector<int> head(n);
    vector<int> new_mapeo(n);
    vector<int> sorted_by_second(n);
    while(len < n){
        for(int i = 0; i < n; i++) sorted_by_second[i] = (a[i] - len + n) % n;
        for(int i = n - 1; i >= 0; i--) head[mapeo[a[i]]] = i;
        for(int i = 0; i < n; i++){
            int x = sorted_by_second[i];
            a[head[mapeo[x]]++] = x;
        }
        new_mapeo[a[0]] = 0;
        for(int i = 1; i < n; i++){
            if(mapeo[a[i - 1]] != mapeo[a[i]]){
                new_mapeo[a[i]] = new_mapeo[a[i - 1]] + 1;
            }
            else{
                int pre = mapeo[(a[i - 1] + len) % n];
                int cur = mapeo[(a[i] + len) % n];
                new_mapeo[a[i]] = new_mapeo[a[i - 1]] + (pre != cur);
            }
        }
        swap(mapeo, new_mapeo);
        len <<= 1;
    }
    return a;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    vi vs;

    for(int x : s)
        vs.pb(x);

    vs.pb(0);
    
    vi a = suffix_array(vs), lcp = lcp_array(vs, a);

    ll ans[n+1];
    memset(ans, 0, sizeof(ans));

    ii st[n+1];
    st[0] = {0, 1};

    int top = 0;
    ll curr = 0;

    auto last_cant = [&](ll rev) {
        return (ll) st[top].first * rev * (st[top].second - st[top-1].second);
    };

    int pos[n];

    for(int i = 1; i <= n; i++)
        pos[a[i]] = i;

    for(int i = 2; i <= n; i++) {
        while(st[top].first > lcp[i-1]) {
            curr -= (ll) last_cant(1);
            top--;
        }

        top++;
        st[top] = {lcp[i-1], i};
        curr += last_cant(1);
        ans[i] += curr;
    }

    top = 0;
    st[0] = {0, n};

    curr = 0;

    for(int i = n-1; i >= 1; i--) {
        while(st[top].first > lcp[i]) {
            curr -= last_cant(-1);
            top--;
        }

        top++;
        st[top] = {lcp[i], i};

        curr += last_cant(-1);
        ans[i] += curr;
    }

    for(int i = 0; i < n; i++)
        cout << ans[pos[i]]+n-i << "\n";
	
    return 0;
}


