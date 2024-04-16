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
    string s[8];
    int x, y;

    for(int i = 0; i < 8; i++) {
        cin >> s[i];
        for(int j = 0; j < 8; j++) {
            if(s[i][j] == '*') x = i, y=j;
        }
    }

    char a = y + 'a';
    char b = 7-x+'1';

    cout << a << b << "\n";
	
    return 0;
}


