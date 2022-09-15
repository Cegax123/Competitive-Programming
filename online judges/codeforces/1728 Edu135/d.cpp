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

const int maxn = 2005;
char result[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();

        for(int i = 0; i+1 < n; i++) {
            if(s[i] == s[i+1]) {
                result[i][i+1] = 'D';
            }
            else {
                result[i][i+1] = 'A';
            }
        }

        auto get_result = [&] (int posa, int posb, int i, int j) {
            if(result[i][j] == 'A') return 'A';
            if(result[i][j] == 'D') {
                if(s[posa] < s[posb]) return 'A';
                else if(s[posa] == s[posb]) return 'D';
                else return 'B';
            }
            return 'B';
        };

        for(int len = 4; len <= n; len += 2) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                char bestr;

                char resf = get_result(i, j, i+1, j-1);
                char ress = get_result(i, i+1, i+2, j);

                if(resf == 'A' and ress == 'A') bestr = 'A';
                else if(resf == 'B' or ress == 'B') bestr = 'B';
                else bestr = 'D';

                resf = get_result(j, i, i+1, j-1);
                ress = get_result(j, j-1, i, j-2);

                if(resf == 'A' and ress == 'A') bestr = 'A';
                if(resf == 'D' and ress == 'D') {
                    if(bestr == 'B') bestr = 'D';
                }

                result[i][j] = bestr;
            }
        }

        if(result[0][n-1] == 'A') cout << "Alice\n";
        else if(result[0][n-1] == 'B') cout << "Bob\n";
        else cout << "Draw\n";
    }

	
    return 0;
}


