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
    string s = "atcoder";
    int pos[30];
    
    for(int i = 0; i < 7; i++)
        pos[s[i]-'a'] = i;

    string t; cin >> t;
    vi x;

    for(int i = 0; i < 7; i++) {
        x.pb(pos[t[i]-'a']);
    }

    int cnt = 0;

    for(int i = 0; i < 7; i++) {
        for(int j = i+1; j < 7; j++)
            if(x[i] > x[j]) cnt++;
    }

    cout << cnt << "\n";
	
    return 0;
}


