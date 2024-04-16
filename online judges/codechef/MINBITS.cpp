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

int count(int x) {
    int ans = 0;
    while(x) {
        if(x&1) ans++;
        x >>= 1;
    }
    return ans;
}

string binary(int x, int n) {
    string s;
    for(int i = 0; i < n; i++) {
        s += (char) '0' + (x&1);
        x >>= 1;
    }
    reverse(all(s));
    return s;
}

int get(string s) {
    int n = s.size();

    int num = 0;

    for(char c : s) {
        num <<= 1;
        if(c == '1') num++;
    }

    int ans = 1000;
    int x=0, y=0;
    for(int i = 0; i < (1 << n); i++) {
        if(i >= num) {
            int curr = count(i) + count(i-num);
            if(curr < ans or (ans == curr and i-num < y)) {
                ans = curr;
                x = i; y = i-num;
            }
        }
    }

    cout << binary(x, n) << "\n";
    cout << binary(y, n) << "\n";

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        int ans = 0;

        for(char c : s) ans += c == '1';

        int num1 = ans;
        int ind = n;
        int holes = 0;
        int cnt = 0;
        bool st = 1;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '1') {
                st = 0;
                num1--;
                continue;
            }

            if(st) {
                cnt++;
                holes++;
                continue;
            }
            
            int curr = 1 + holes + num1;
            
            curr++;
            curr -= cnt;
            
            if(curr < ans) {
                ans = curr;
                ind = i;
            }

            holes++;
        }

        string a;

        for(int i = 0; i < n; i++) {
            if(i < ind) a += s[i];
            else if(i == ind) a += '1';
            else a += '0';
        }
            
        int carry = 0;
        string b;

        for(int i = n-1; i >= 0; i--) {
            int curr = carry + s[i]-'0';
            int target = a[i] - '0';

            if(curr == target) {
                b += '0';
                carry = 0;
            }
            else {
                b += '1';
                carry = (curr + 1) / 2;
            }
        }

        reverse(all(b));

        cout << a << "\n" << b << "\n";

        cout << get(s) << "\n";

        //assert(ans == get(s));
    }
    

	
    return 0;
}


