#include <bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s; cin >> s;
    int n = s.size();

    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }

    int pos=0, len=0;
    for(int i = 0; i < (int) d1.size(); i++) {
        if(len < 2 * d1[i] - 1) {
            len = 2 * d1[i]-1;
            pos = i-d1[i]+1;
        }
    }
    for(int i = 0; i < (int) d2.size(); i++) {
        if(len < 2 * d2[i]) {
            len = 2 * d2[i];
            pos = i-1-d2[i]+1;
        }
    }

    //cout << pos << " " << len << endl;

    cout << s.substr(pos, len) << "\n";

    return 0;
}


