#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
    int n, m; cin >> n >> m;
    set<string> r[n];

    cin.ignore();
    for(int i = 0; i < n; i++) {
        string s; getline(cin, s);

        string curr;

        for(int j = 0; j < (int) s.size(); j++) {
            if(s[j] == ' ') {
                r[i].insert(curr);
                curr = "";
            }
            else {
                curr += s[j];
            }
        }
        r[i].insert(curr);
    }

    cin.ignore();
    cin.ignore();

    vi cnt(n, 0);

    vi id(m);

    for(int i = 0; i < m; i++) {
        string t; getline(cin, t);

        string curr;

        for(int j = 0; j < (int) t.size(); j++) {
            if(t[j] == ' ') {
                curr = "";
            }
            else {
                curr += t[j];
            }
        }

        for(char& c : curr)
            c = tolower(c);


        id[i] = -1;
        for(int j = 0; j < n; j++) {
            if(r[j].count(curr)) {
                cnt[j]++;
                id[i] = j;
            }
        }

    }

    vector<bool> used(n, 0);
    map<int, char> letter;
    char mm = 'A';

    for(int i = 0; i < m; i++) {
        if(id[i] == -1 or cnt[id[i]] == 1) cout << "X";
        else {
            if(used[id[i]]) cout << letter[id[i]];
            else {
                letter[id[i]] = mm;
                used[id[i]] = 1;

                cout << letter[id[i]];
                mm++;
                if(mm == 'X') mm++;
            }
        }
    }

    return 0;
}
