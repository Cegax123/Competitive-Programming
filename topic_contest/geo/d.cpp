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
    vector<int> len;
    int x; 
    while(cin >> x and x) {
        len.push_back(x);
    }

    sort(len.begin(), len.end());

    int ind = -1;

    for(int i = 2; i < (int) len.size(); i++) {
        if(len[i] < len[i-1] + len[i-2]) {
            ind = i;
        }
    }

    if(ind == -1) cout << "NIE\n";
    else {
        cout << len[ind] << " " << len[ind-1] << " " << len[ind-2] << "\n";
    }
	
    return 0;
}


