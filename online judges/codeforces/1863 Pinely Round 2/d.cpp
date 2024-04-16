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
        int n, m; cin >> n >> m;
        string b[n];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        char a[n][m];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[i][j] = '.';
            }
        }
        
        string c = "WB";
        bool cmp = true;

        for(int i = 0; i < n; i++) {
            int sum = 0;

            for(int j = 0; j < m; j++) {
                if(a[i][j] != '.') {
                    if(a[i][j] == 'W') sum++;
                    else sum--;
                }
            }
            for(int j = 0; j < m; j++) {
                if(a[i][j] == '.' and (b[i][j] == 'U' or b[i][j] == 'D')) {
                    if(sum < 0) {
                        a[i][j] = 'W';
                        sum++;

                        if(b[i][j] == 'U') {
                            a[i+1][j] = 'B';
                        }
                    }
                    else {
                        a[i][j] = 'B';
                        sum--;
                        
                        if(b[i][j] == 'U') {
                            a[i+1][j] = 'W';
                        }
                    }
                }
            }
            if(sum) cmp = false;
        }

        for(int j = 0; j < m; j++) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                if(a[i][j] != '.') {
                    if(a[i][j] == 'W') sum++;
                    else sum--;
                }
            }
            for(int i = 0; i < n; i++) {
                            if(a[i][j] == '.' and (b[i][j] == 'L' or b[i][j] == 'R')) {
                    if(sum < 0) {
                        a[i][j] = 'W';
                        sum++;

                        if(b[i][j] == 'L') {
                            a[i][j+1] = 'B';
                        }
                    }
                    else {
                        a[i][j] = 'B';
                        sum--;

                        if(b[i][j] == 'L') {
                            a[i][j+1] = 'W';
                        }
                    }
                }
            }
            if(sum) cmp = false;
        }
        
        if(!cmp) {
            cout << -1 << "\n";
            continue;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }

	
    return 0;
}


