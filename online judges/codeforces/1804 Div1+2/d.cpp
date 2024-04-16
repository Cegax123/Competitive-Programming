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

bool cmp(char x, char y, vector<pair<char, char>> v) {
    for(auto e : v) {
        if(e.first == x and e.second == y) return true;
    }
    return false;
}

int find(vector<string> b, int n, int m, vector<pair<char, char>> v1, vector<pair<char, char>> v2) {
    int ans_max = 0;

    for(int i = 0; i < n; i++) {
        vector<bool> marked(m);

        int lmt = m/4;
        int last_pos = -1;

        for(int j = 0; j < m; j += 2) {
            if(lmt and cmp(b[i][j], b[i][j+1], v1)) {
                marked[j] = marked[j+1] = 1;
                lmt--;
                last_pos = max(last_pos, j);
            }
        }

        if(last_pos != -1) {
            lmt++;
            marked[last_pos+1] = 0;
        }

        int first_pos = m;


        for(int j = m-1; j >= 0; j -= 2) {
            if(lmt and j > last_pos+1 and cmp(b[i][j-1], b[i][j], v2)) {
                marked[j] = marked[j-1] = 1;
                first_pos = min(first_pos, j);
                lmt--;
            }
        }

        if(last_pos != -1 and first_pos < m) {
            marked[first_pos-1] = 0;
        }

        if(first_pos == m and last_pos >= 0) {
            marked[last_pos+1] = 1;
            lmt--;
        }

        //for(int j = 0; j < m; j++)
            //cout << marked[j];
        //cout << endl;


        int last = 1;
        for(int j = 0; j < m; j++) {
            if(j%2 == 0 and last == 1 and !marked[j] and !marked[j+1] and lmt) {
                lmt--;
                marked[j] = marked[j+1] = 1;
            }
            else if(marked[j]) {
                last = j % 2;
            }
        }

        int ans = 0;
        string tmp;

        for(int j = 0; j < m; j++) {
            if(!marked[j]) tmp += b[i][j];
            else if(b[i][j] == '1') ans++;
        }

        for(int j = 0; j < (int) tmp.size(); j+=2) {
            if(tmp[j] == '1' or tmp[j+1] == '1') ans++;
        }
        //cout << " ";

        //cout << ans << "\n";

        ans_max += ans;
    }
    return ans_max;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    vector<string>b(n);
    
    for(int i = 0; i < n; i++)
        cin >> b[i];

    cout << find(b, n, m, {{'0', '1'}, {'0', '0'}}, {{'1', '0'}, {'0', '0'}}) << " ";
    cout << find(b, n, m, {{'1', '1'}}, {{'1', '1'}});

    //cout << find(b, n, m, '0', '1') << " ";
    //cout << find(b, n, m, '1', '1') << "\n";
	
    return 0;
}


