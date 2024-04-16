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
    string s, t; cin >> s >> t;
    int n = s.size();

    int cnts = 0, cntt = 0;

    multiset<char> ss, st;

    for(char c : s) {
        if(c == '@') cnts++;
        else ss.insert(c);
    }

    for(char c : t) {
        if(c == '@') cntt++;
        else st.insert(c);
    }

    vector<char> to_delete;
    for(char c : ss) {
        if(st.find(c) != st.end()) {
            st.erase(st.find(c));
            to_delete.pb(c);
        }
    }

    for(char c : to_delete)
        ss.erase(ss.find(c));

    set<char> poss;
    poss.insert('a');
    poss.insert('t');
    poss.insert('c');
    poss.insert('o');
    poss.insert('d');
    poss.insert('e');
    poss.insert('r');

    to_delete.clear();
    for(char c : ss) {
        if(poss.count(c)) {
            if(cntt) {
                cntt--;
                to_delete.pb(c);
            }
        }
    }
    for(char c : to_delete)
        ss.erase(ss.find(c));

    to_delete.clear();

    for(char c : st) {
        if(poss.count(c)) {
            if(cnts) {
                cnts--;
                to_delete.pb(c);
            }
        }
    }

    for(char c : to_delete)
        st.erase(st.find(c));

    if(st.empty() and ss.empty()) {
        cout << "Yes\n";
    }
    else cout << "No\n";
	
    return 0;
}


