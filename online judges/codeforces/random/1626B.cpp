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
        string s; cin >> s;

        bool found = 0;
        for(int i = (int) s.size()-2; i >= 0; i--) {
            int a = s[i]-'0';
            int b = s[i+1]-'0';

            if(a+b >= 10) {
                for(int j = 0; j < i; j++)
                    cout << s[j];

                cout << a+b;

                for(int j = i+2; j < (int) s.size(); j++)
                    cout << s[j];

                found = 1;
                break;
            }
        }

        if(found == false) {
            int a = s[0]-'0';
            int b = s[1]-'0';
            cout << a+b;

            for(int i = 2; i < (int) s.size(); i++)
                cout << s[i];
        }

        cout << "\n";
    }
	
	
	return 0;
}

