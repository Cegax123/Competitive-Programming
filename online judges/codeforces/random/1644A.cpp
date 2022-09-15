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
        string s; cin >> s;
        map<char,int> cnt;
        bool cmp = 1;

        for(int i = 0; i < 6; i++) {
            if(s[i] == 'R' and cnt['r'] == 0) cmp = 0;
            if(s[i] == 'B' and cnt['b'] == 0) cmp = 0;
            if(s[i] == 'G' and cnt['g'] == 0) cmp = 0;

            if(s[i] == 'r' or s[i] == 'b' or s[i] == 'g') cnt[s[i]]++;
        }

        if(cmp) cout << "YES\n";
        else cout << "NO\n";
    }
	
	
	return 0;
}

