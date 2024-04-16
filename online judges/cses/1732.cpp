#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s; cin >> s;
    int n = s.size();

    vector<int> pi = prefix_function(s);

    vector<int> ans;

    int ind = n-1;

    while(true) {
        if(pi[ind] == 0) break;
        ans.push_back(pi[ind]);

        ind = pi[ind]-1;
    }

    for(int i = (int) ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
	
    return 0;
}


