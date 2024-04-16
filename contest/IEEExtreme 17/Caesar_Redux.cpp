#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        cin.ignore();
        string s; getline(cin, s);

        vector<string> words;

        string curr;
        for(int i = 0; i < (int) s.size(); i++) {
            if(s[i] == ' ') {
                words.pb(curr);
                curr = "";
            }
            else curr += s[i];
        }

        words.pb(curr);

        bool cmp = 0;
        for(string x : words) {
            if((int) x.size() == 3 and x == "the") cmp = 1;
        }

        for(string& x : words) {
            for(char& c : x) {
                int d = c-'a';
                if(cmp) {
                    d += 26-a;
                    d %= 26;
                }
                else {
                    d += a;
                    d %= 26;
                }

                c = 'a' + d;
            }
        }

        for(int i = 0; i < (int) words.size()-1; i++) {
            cout << words[i] << " ";
        }
        cout << words.back() << "\n";
    }


    return 0;
}
