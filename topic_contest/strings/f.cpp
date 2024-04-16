#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(const string& s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    string rs = s;
    reverse(rs.begin(), rs.end());
    int t; cin >> t;
    int ans = 0;
    while(t--) {
        string p; cin >> p;

        if((int) p.size() == 1) {
            continue;
        }

        vector<int> zl = z_function(p + "#" + s);

        reverse(p.begin(), p.end());
        vector<int> zr = z_function(p + "#" + rs);

        vector<int> ind_pref(p.size()+1, 1e5+100);
        vector<int> ind_suff(p.size()+1, 1e5+100);

        for(int i = (int) zl.size()-1; i > (int) p.size(); i--) {
            ind_pref[zl[i]] = i-(int) p.size() - 1;
            ind_suff[zr[i]] = i-(int) p.size() - 1;
        }   

        for(int i = (int) p.size() - 1; i >= 0; i--) {
            ind_pref[i] = min(ind_pref[i], ind_pref[i+1]);
            ind_suff[i] = min(ind_suff[i], ind_suff[i+1]);
        }

        for(int& x : ind_suff) x = (int) s.size() - 1 - x;

        bool cmp = 0;
        for(int i = 0; i <= (int) p.size(); i++) {
            int lft = (int) p.size() - i;

            if(ind_suff[lft] - ind_pref[i] + 1 >= (int) p.size()) cmp = 1;
        }
        ans += cmp;
    }

    cout << ans << "\n";


    return 0;
}
