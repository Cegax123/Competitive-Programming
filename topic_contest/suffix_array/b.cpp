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

vi suffix_array(string& s) {
    s += '$';
    int n = s.size();

    vi p(n), ord(n);

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

    return p;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s; cin >> s;

    vi p = suffix_array(s);
    int n = s.size();
	
    int q; cin >> q;
    while(q--) {
        string t; cin >> t;

        int L, R;
        int l = 0, r = n-1;

        while(l < r) {
            int m = (l+r) >> 1;

            if(s.substr(p[m], min(n-p[m], (int) t.size())) >= t) r = m;
            else l = m+1;
        }

        L = l;

        l = 0, r = n-1;

        while(l < r) {
            int m = (l+r+1) >> 1;

            if(s.substr(p[m], min(n-p[m], (int) t.size())) <= t) l = m;
            else r = m-1;
        }

        R = l;

        if(s.substr(p[L], min(n-p[L], (int) t.size())) == t and s.substr(p[R], min(n-p[R], (int) t.size())) == t) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
	
	return 0;
}


