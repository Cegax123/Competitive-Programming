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
    vector<int> pi = prefix_function(s);

    int ind = (int) s.size()-1;
    vector<int> ans;

    do {
        ans.push_back(pi[ind]);
        ind = pi[ind]-1;
    } while(ind >= 0);

    for(int x : ans) cout << (int) s.size()-x << " ";
    	
    return 0;
}


