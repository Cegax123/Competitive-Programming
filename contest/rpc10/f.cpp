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
    map<char, string> morse;

    morse['a'] = "01";
    morse['b'] = "1000";
    morse['c'] = "1010";
    morse['d'] = "100";
    morse['e'] = "0";
    morse['f'] = "0010";
    morse['g'] = "110";
    morse['h'] = "0000";
    morse['i'] = "00";
    morse['j'] = "0111";
    morse['k'] = "101";
    morse['l'] = "0100";
    morse['m'] = "11";
    morse['n'] = "10";
    morse['o'] = "111";
    morse['p'] = "0110";
    morse['q'] = "1101";
    morse['r'] = "010";
    morse['s'] = "000";
    morse['t'] = "1";
    morse['u'] = "001";
    morse['v'] = "0001";
    morse['w'] = "011";
    morse['x'] = "1001";
    morse['y'] = "1011";
    morse['z'] = "1100";

    morse['0'] = "11111";
    morse['1'] = "01111";
    morse['2'] = "00111";
    morse['3'] = "00011";
    morse['4'] = "00001";
    morse['5'] = "00000";
    morse['6'] = "10000";
    morse['7'] = "11000";
    morse['8'] = "11100";
    morse['9'] = "11110";
	
    string s;
    getline(cin, s);

    string res;
    for(char c : s) {
        if((c >= 'a' and c <= 'z')) res += morse[c];
        else if(c >= 'A' and c <= 'Z') res += morse[c-'A'+'a'];
        else if(c >= '0' and c <= '9') res += morse[c];
    }

    bool cmp = 1;

    if(res.empty()) cmp = 0;

    int n = res.size();
    for(int i = 0; i < n; i++) {
        int j = n-1-i;
        if(res[i] != res[j]) cmp = 0;
    }

    cout << (cmp ? "YES\n" : "NO\n");

    return 0;
}


