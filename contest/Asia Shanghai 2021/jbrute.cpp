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

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
   return uniform_int_distribution<long long>(l,r)(rng);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int n = 5;
    //string a, b;
    //a = "11010";
    //b = "11000";

    //int n = 8;
    //string a, b;
    //a = "11110000";
    //b = "11111100";


    auto comp = [](string a, string b) {
        int n = a.size();
        int p[n+1];
        p[0] = 0;

        for(int i = 1; i <= n; i++) {
            p[i] = p[i-1] + (a[i-1] == '1');
        }

        string ans;

        for(int i = 1; i <= n; i++) {
            string c;
            for(int j = 1; j <= n; j++) {
                if(2 * (p[j]-p[max(j-i, 0)]) > j - max(j-i, 0)) c += '1';
                else c += '0';
            }

            if(b == c) ans += '1';
            else ans += '0';
        }

        return ans;
    };

    int n = 3; cin >> n;

    int cnt = 0;

    map<string, int> s;

    for(int i = 0; i < (1 << n); i++) {
        string a;
        for(int j = 0; j < n; j++) {
            if((i >> j)&1) a += '1';
            else a += '0';
        }

        for(int k = 0; k < (1 << n); k++) {
            string b;
            for(int j = 0; j < n; j++) {
                if((k >> j)&1) b += '1';
                else b += '0';
            }
            string ans = comp(a,b);
            reverse(all(ans));
            s[ans]++;
            //cout << a << " " << b << " " << comp(a, b) << "\n";
        }
    }

    cout << s.size() << "\n";

    for(auto x : s) {
        cout << x.first << " " << x.second << endl;
    }
    
    	
    return 0;
}


