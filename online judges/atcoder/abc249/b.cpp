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

bool isLower(char c) {
    return 'a' <= c and c <= 'z';
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s; cin >> s;

    int cntl = 0, cntu = 0;
    bool cmp = 1;
    set<char> x;

    for(int i = 0; i < (int) s.size(); i++) {
        if(x.count(s[i])) cmp = 0;
        x.insert(s[i]);
        if(isLower(s[i])) cntl++;
        else cntu++;
    }

    if(cntl == 0 or cntu == 0) cmp = 0;

    if(cmp) cout << "Yes\n";
    else cout << "No\n";
   
    return 0;
}


