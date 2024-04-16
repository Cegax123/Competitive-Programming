#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define pb push_back

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >>s;
        int n = s.size();

        int cnt0[n], cnt1[n];
        vi pos0, pos1;
        pos1.pb(-1);

        for(int i = 0; i < n; i++) {
            if(s[i] == '1') pos1.pb(i);
            else pos0.pb(i);
        }

        reverse(pos0.begin(), pos0.end());

        for(int i = n-1; i >= 0; i--) {
            cnt0[i] = s[i] == '0';
            if(i+1 < n) cnt0[i] += cnt0[i+1];
        }

        ll S = 0;

        for(int i = 0; i < n; i++) {
            cnt1[i] = s[i] == '1';
            if(i) cnt1[i] += cnt1[i-1];

            if(s[i] == '1') S += cnt0[i];
        }

        ll Sb[n];

        Sb[n-1] = s[n-1] == '0' ? cnt1[n-1] : 0;

        for(int i = n-2; i >= 0; i--) {
            Sb[i] = (s[i] == '0' ? cnt1[i] : 0) + Sb[i+1];
        }

        ll Sa = 0;
        ll ansX = n, ansY = n;
        for(int i = 0; i < (int) pos1.size(); i++) {
            while(!pos0.empty() and pos0.back() < pos1[i]) pos0.pop_back();
            
            if(pos1[i] != -1) Sa += cnt0[pos1[i]];

            ll C1, C2;

            if(pos0.empty()) {
                C1 = S - Sa;
                C2 = i;
            }
            else {
                int l = 0, r = pos0.size()-1;
                while(l < r) {
                    int m = (l+r+1) >> 1;
                    if(-cnt1[pos0[m]] + i <= -2) l = m;
                    else r = m-1;
                }

                if(-cnt1[pos0[l]] + i <= -2) {
                    C1 = S - Sa - Sb[pos0[l]] + (ll) i * (l+1);
                    C2 = i + (l+1);
                }
                else {
                    C1 = S-Sa;
                    C2 = i;
                }

                
            }

            if(C1 + C2 < ansX + ansY) {
                ansX = C1;
                ansY = C2;
            }
            else if(C1 + C2 == ansX + ansY) {
                if(C2 < ansY) {
                    ansY = C2;
                    ansX = C1;
                }
            }
        }

        ll C1 = (ll) 1e12, C2 = C1 + 1;

        cout << ansX * C1 + ansY * C2 << "\n";
    }


    return 0;
}
