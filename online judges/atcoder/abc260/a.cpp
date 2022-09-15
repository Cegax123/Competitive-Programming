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
    string s; cin >> s;

    map<char, int> cnt;
    for(char c : s)
        cnt[c]++;

    bool found = 0;
    for(char c : s) {
        if(cnt[c] == 1) {
            cout << c;
            found = 1;
            break;
        }
    }

    if(!found) cout << -1;
	
    return 0;
}


