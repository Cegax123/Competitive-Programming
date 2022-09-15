
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

void radix_sort(vector<pair<ii, int>>& a){
    int n = a.size();

    {
        vi cnt(n, 0);
        
        for(auto x : a)
            cnt[x.first.second]++;

        vector<pair<ii, int> > a_new(n);
        vi pos(n);

        pos[0] = 0;

        for(int i = 1; i < n; i++)
            pos[i] = pos[i-1] + cnt[i-1];

        for(auto x : a) {
            int i = x.first.second;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }

    {
        vi cnt(n, 0);
        
        for(auto x : a)
            cnt[x.first.first]++;

        vector<pair<ii, int> > a_new(n);
        vi pos(n);

        pos[0] = 0;

        for(int i = 1; i < n; i++)
            pos[i] = pos[i-1] + cnt[i-1];

        for(auto x : a) {
            int i = x.first.first;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        
        a = a_new;
    }
}

void suffix_array(string& s, vi& p, vi& lcp) {
    s += '$';
    int n = s.size();

    p.clear(); p.resize(n);
    lcp.clear(); lcp.resize(n);

    vi ord(n);

    vector<pair<char, int> > id(n);
    for(int i = 0; i < n; i++) 
        id[i] = {s[i], i};

    sort(all(id));

    for(int i = 0; i < n; i++)
        p[i] = id[i].second;

    ord[id[0].second] = 0;

    for(int i = 1; i < n; i++) {
        if(id[i].first == id[i-1].first)
            ord[p[i]] = ord[p[i-1]];

        else 
            ord[p[i]] = ord[p[i-1]]+1;
    }

    int k = 0;
    while((1 << k) < n) {
        vector<pair<ii, int> > id(n);

        for(int i = 0; i < n; i++) 
            id[i] = {{ord[i], ord[(i+(1 << k))%n]}, i};

        radix_sort(id);
        // sort(all(id));

        for(int i = 0; i < n; i++)
            p[i] = id[i].second;

        ord[p[0]] = 0;

        for(int i = 1; i < n; i++) {
            if(id[i].first == id[i-1].first)
                ord[p[i]] = ord[p[i-1]];

            else 
                ord[p[i]] = ord[p[i-1]]+1;
        }        

        k++;
    }

    int x = 0;

    for(int i = 0; i < n-1; i++) {
        int pi = ord[i];
        int j = p[pi-1];

        while(s[i+x] == s[j+x]) x++;
        lcp[pi] = x;

        x = max(x-1, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s, t; cin >> s >> t;

    string tmp = s + '&' + t;

    vi p, lcp;

    suffix_array(tmp, p, lcp);

    int n = tmp.size();
    
    // for(int i = 0; i < n; i++) 
    //  cout << lcp[i] << " " << p[i] << " " << tmp.substr(p[i], n-p[i]) << "\n";

    int ans = 0, pos = 0;

    for(int i = 1; i < n-1; i++) {
        int id1 = (p[i] < (int) s.size() ? 0 : 1);
        int id2 = (p[i+1] < (int) s.size() ? 0 : 1);

        if(id1 == id2) continue;

        if(lcp[i+1] > ans) {
            ans = lcp[i+1];
            pos = (id1 == 0 ? p[i] : p[i+1]);
        }
    }

    cout << s.substr(pos, ans);
    
    return 0;
}
