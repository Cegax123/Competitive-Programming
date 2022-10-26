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

const int L = 20;
const int T = (1 << L);

int n, q;
ll P[T], Q[T];

int cnt = 0;
int generated_masks[100];

void gen(const string& x, int curr = 0, int pos = 0) {
    if(pos >= n) {
        generated_masks[cnt++] = curr;
        return;
    }

    if(x[pos] == '?') {
        gen(x, (curr | (1 << pos)), pos+1);
        gen(x, curr, pos+1);
    }
    else {
        int nxt = curr;
        if(x[pos] == '1') nxt |= (1 << pos);

        gen(x, nxt, pos+1);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    string s; cin >> s;

    for(int i = 0; i < (1 << n); i++) 
        P[i] = Q[i] = s[i]-'0';

    for(int i = 0; i < L; i++) {
        for(int mask = 0; mask < T; mask++) {
            if((mask & (1 << i)))
                P[mask] += P[mask ^ (1 << i)];

            if((mask & (1 << i)) == 0) 
                Q[mask] += Q[mask | (1 << i)];
        }
    }

    while(q--) {
        string x; cin >> x;
        
        reverse(all(x));

        int numq = 0, num0 = 0, num1 = 0;

        for(char c : x) {
            if(c == '?') numq++;
            else if(c == '0') num0++;
            else num1++;
        }
            
        int opt = 0;
            
        if(num0 <= numq and num0 <= num1) opt = 1;
        if(num1 <= numq and num1 <= num0) opt = 2;
            
        if(opt == 0) {
            cnt = 0;
            gen(x);
            
            ll ans = 0;
            
            for(int i = 0; i < cnt; i++) {
                int mask = generated_masks[i];
                ans += s[mask] - '0';
            }
                
            cout << ans << "\n";
        }
        else if(opt == 1) {
            string w;
            int d = 0;

            for(int i = 0; i < n; i++) {
                if(x[i] == '0') w += '?';
                else w += '0';

                if(x[i] == '1') d |= (1 << i);
            }

            cnt = 0;
            gen(w);

            ll ans = 0;

            for(int i = 0; i < cnt; i++) {
                int mask = generated_masks[i];
                if(__builtin_popcount(mask) & 1) 
                    ans -= Q[d | mask];
                else 
                    ans += Q[d | mask];
            }
            
            cout << ans << "\n";
        }
        else {
            string w;
            int d = 0;

            for(int i = 0; i < n; i++) {
                if(x[i] == '1') w += '?';
                else w += '0';

                if(x[i] != '0') d |= (1 << i);
            }

            cnt = 0;
            gen(w);

            ll ans = 0;

            for(int i = 0; i < cnt; i++) {
                int mask = generated_masks[i];
                if(__builtin_popcount(mask) & 1) 
                    ans -= P[d ^ mask];
                else 
                    ans += P[d ^ mask];
            }
            
            cout << ans << "\n";
        }
    }
	
    return 0;
}


