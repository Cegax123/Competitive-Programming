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

const int maxn = 100;
vector<string> ans[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ans[1].push_back("1");
    ans[3].push_back("169");
    ans[3].push_back("196");
    ans[3].push_back("961");

    for(int i = 5; i < maxn; i += 2) {
        ans[i] = ans[i-2];
        for(string& s : ans[i]) s += "00";

        ans[i].push_back("1"+string((i-3)/2, '0')+"6"+string((i-3)/2, '0')+"9");
        ans[i].push_back("9"+string((i-3)/2, '0')+"6"+string((i-3)/2, '0')+"1");
    }

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(string& s : ans[n]) cout << s << "\n";
    }
	
    return 0;
}


