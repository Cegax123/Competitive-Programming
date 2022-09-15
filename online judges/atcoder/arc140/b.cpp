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
    multiset<int> t;

    for(int i = 0; i < n; i++) {
        if(s[i] != 'R') continue;

        int l = i-1, r = i+1;
        while(l >= 0 and s[l] == 'A') l--;
        while(r < n and s[r] == 'C') r++;

        l++; r--;

        int x = min(i-l, r-i);
        if(x > 0) t.insert(x);
    }


    int ans = 0;
    int turn = 0;
    while(!t.empty()) {
        if(turn == 0) {
            int x = *t.rbegin(); t.erase(t.find(x));
            ans++;

            if(x > 1) t.insert(x-1);
        }
        else {
            int x = *t.begin(); t.erase(t.find(x));
            ans++;
        }
        turn = 1 - turn;
    }

    cout << ans << "\n";

    return 0;
}


