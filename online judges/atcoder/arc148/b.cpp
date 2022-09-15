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
    int n; cin >> n;
    string s; cin >> s;

    for(char& c : s) {
        if(c == 'd') c = '0';
        else c = '1';
    }

    int k = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            k = i;
            break;
        }
    }

    if(k == -1) {
        for(char c : s) {
            if(c == '0') cout << 'd';
            else cout << 'p';
        }
        return 0;
    }

    vector<string> S;

    for(int i = k; i < n; i++) {
        if(s[i] == '1') {
            string tmp;
            for(int t = 0; t < k; t++)
                tmp += '0';

            for(int t = i; t >= k; t--) {
                if(s[t] == '1') tmp += '0';
                else tmp += '1';
            }

            for(int t = i+1; t < n; t++)
                tmp += s[t];

            S.pb(tmp);
        }
    }

    sort(all(S));

    for(char c : S[0]) {
        if(c == '0') cout << 'd';
        else cout << 'p';
    }
	
    return 0;
}


