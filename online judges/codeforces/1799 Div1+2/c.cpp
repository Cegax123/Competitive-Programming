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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        string x; cin >> x;
        string s = string(x.size(), '#');

        string temp = x;
        int k = s.size();

        set<pair<char, int>> b;

        vi cnt(26, 0);
        for(char c : x) cnt[c-'a']++;

        for(int i = 0; i < 26; i++) {
            if(cnt[i]) b.insert({'a'+i, cnt[i]});
        }

        int ind = 0;
        
        while(!b.empty()) {
            if((int) b.size() == 1) {
                auto x = *(b.begin());
                b.erase(x);

                if(x.second == 1) {
                    s[ind] = x.first;
                }
                else {
                    s[ind] = x.first;
                    s[k-ind-1] = x.first;
                    x.second -= 2;

                    ind++;
                    if(x.second) b.insert(x);
                }
            }
            else {
                auto x = *(b.begin());
                b.erase(x);

                if(x.second == 1) {
                    auto y = *(b.begin());
                    b.erase(y);

                    if(y.second > 2 or (y.second == 2 and b.empty())) {
                        s[ind] = y.first;
                        s[k-ind-1] = y.first;
                        y.second -= 2;
                    }
                    else {
                        s[ind] = y.first;
                        s[k-ind-1] = x.first;
                        x.second--;
                        y.second--;

                        string t;

                        t += string(x.second, x.first);
                        t += string(y.second, y.first);

                        while(!b.empty()) {
                            auto z = *(b.begin());
                            b.erase(z);
                            t += string(z.second, z.first);
                        }

                        sort(all(t));

                        ind++;
                        int p = t.size();
                        
                        for(int m = 0; m < p; m++) {
                            s[ind + m] = t[m];
                        }

                        break;
                    }

                    if(x.second) b.insert(x);
                    if(y.second) b.insert(y);
                }
                else {
                    x.second -= 2;

                    s[ind] = s[k-ind-1] = x.first;

                    if(x.second) b.insert(x);
                }
                ind++;
            }
        }

        temp = s;

        reverse(all(s));

        cout << max(s, temp) << "\n";

    }

	
    return 0;
}


