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

string ans;
string curr, s;
bool banned_ord[10], banned_letter[30];
vi ord;
int n;
int cnt = 0;

void solve(int pos=0, int sum=0) {
    if(!ans.empty()) return;
    if(pos == n) {
        ans = curr;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(banned_ord[i]) continue;

        int poss = s[pos]-'0' - sum - i;
        poss %= 10;
        if(poss < 10) poss += 10;

        while(poss < 26) {
            if(!banned_letter[poss]) {
                bool cmp = 1;

                for(int j = 0; j < pos; j++) {
                    if(i < ord[j] and poss > curr[j]-'a') cmp = 0;
                    if(i > ord[j] and poss < curr[j]-'a') cmp = 0;
                }

                if(cmp) {
                    curr += (char) 'a' + poss;
                    ord.pb(i);
                    banned_ord[i] = 1;
                    banned_letter[poss] = 1;

                    solve(pos+1, sum+poss);

                    curr.pop_back();
                    ord.pop_back();
                    banned_ord[i] = 0;
                    banned_letter[poss] = 0;
                }
            }
            poss += 10;
        }
    }
}
string encrypt(string S){
	const int N = S.size();
	vector<int> W(N, 0);
	for(int i = 0; i < N; i++){
		if(S[i] < 'a' or 'z' < S[i]) return "";
		for(int j = 0; j < N; j++){
			if(S[i] > S[j]) W[i]++;
		}
		for(int j = i; j < N; j++){
			if(i != j and S[i] == S[j]) return "";
			W[i] = W[i] + S[j] - 'a';
		}
		W[i] %= 10;
	}
	string res = "";
	for(int i = 0; i < N; i++) res.push_back('0' + W[i]);
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t >> n;

    for(int i = 0; i < t; i++) {
        cin >> s;
        reverse(all(s));
        
        ans = "";
        solve();

        reverse(all(ans));
        if(ans.empty()) cout << -1 << "\n";
        else cout << ans << "\n";
    }

	
    return 0;
}


