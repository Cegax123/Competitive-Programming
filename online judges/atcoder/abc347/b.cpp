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
    int n = s.size();

    vector<string> subs;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int len = j-i+1;
            subs.push_back(s.substr(i, len));
        }
    }

    sort(all(subs));

    subs.erase(unique(all(subs)), subs.end());

    cout << subs.size() << "\n";
	
    return 0;
}


