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
    int ind = -1;

    for(int i = 0; i < (int) s.size(); i++) {
        if(s[i] == '1') {
            ind = i;
            break;
        }
    }

    if(ind == -1) {
        cout << "no\n";
        return 0;
    }

    int cnt = 0;

    for(int i = ind+1; i < (int) s.size(); i++) cnt += s[i] == '0';

    cout << (cnt >= 6 ? "yes\n" : "no\n");
	
    return 0;
}


