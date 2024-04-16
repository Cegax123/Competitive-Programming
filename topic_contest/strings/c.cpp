#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, t; cin >> s >> t;
    vector<int> cnt(10, 0);

    for(char c : s) {
        cnt[c-'0']++;
    }

    int num_digits = 0;

    for(int i = 1; i <= 7; i++) {
        int k = (int) s.size() - i;
        int cd = 0;
        while(k) {
            cd++;
            k /= 10;
        }

        if(cd == i) {
            num_digits = (int) s.size()-i;
        }
    }

    if(num_digits == 1) {
        cnt[1]--;

        for(int i = 0; i < 10; i++) cout << string(cnt[i], '0'+i);
        cout << "\n";
        return 0;
    }

    for(char c : t) {
        cnt[c-'0']--;
    }


    while(num_digits) {
        cnt[num_digits % 10]--;
        num_digits /= 10;
    }

    string ans;

    int x = t[0]-'0';

    if(x) {
        string curr = t;

        for(int i = 0; i < 10; i++) curr += string(cnt[i], '0'+i);

        if(ans.empty()) ans = curr;
        ans = min(ans, curr);
    }

    int q = 0;

    for(int i = 1; i < 10; i++) if(cnt[i]) {
        q = i;
        break;
    }

    if(q) {
        cnt[q]--;

        string curr; 
        curr += string(1, '0'+q);

        for(int i = 0; i < x; i++) curr += string(cnt[i], '0'+i);

        curr += t;

        for(int i = x; i < 10; i++) curr += string(cnt[i], '0'+i);

        if(ans.empty()) ans = curr;
        ans = min(ans, curr);

        curr = "";
        curr += string(1, '0'+q);

        for(int i = 0; i <= x; i++) curr += string(cnt[i], '0'+i);

        curr += t;
        
        for(int i = x+1; i < 10; i++) curr += string(cnt[i], '0'+i);

        if(ans.empty()) ans = curr;
        ans = min(ans, curr);
    }

    cout << ans << "\n";

    return 0;
}
