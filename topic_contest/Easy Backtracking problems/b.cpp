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

int n, k;
string s;
int cnt[5];

void backtrack(int pos = 0) {
    if(pos == n) {
        for(int i = 0; i < k; i++)
            if(cnt[i] == 1) return;

        cout << s << "\n";
        return;
    }

    for(int i = 0; i < k; i++) {
        cnt[i]++;
        s += (char) 'a' + i;

        backtrack(pos+1);

        cnt[i]--;
        s.pop_back();
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        backtrack();
        cout << "---\n";
    }

	
    return 0;
}


