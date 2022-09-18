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
    string s[10];

    for(int i = 0; i < 10; i++)
        cin >> s[i];

    int a=-1, b, c, d;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(s[i][j] == '#') {
                c = i, d = j;

                if(a == -1) { 
                    a = i, b = j;
                }
            }
        }
    }

    cout << a+1 << " " << c+1 << "\n" << b+1 << " " << d+1 << "\n";
	
    return 0;
}


