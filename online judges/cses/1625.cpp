#include<bits/stdc++.h>
using namespace std;

const int L = 7;
const int LEN_PATH = L * L - 1;
int board[L][L];
string pat;
vector<string> total;

int cnt[] = {15, 9, 12, 12};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

string dir = "DURL";

void backtrack(int x = 0, int y = 0, int len = 0) {
    if(len == LEN_PATH) {
        if(x == L-1 and y == 0) 
            total.push_back(pat);
        return;
    }

    for(int d = 0; d < 4; d++) {
        if(cnt[d] == 0) continue;
        int nx = x + dx[d], ny = y + dy[d];
        if(nx < 0 or nx >= L or ny < 0 or ny >= L) continue;
        if(board[nx][ny] == 1) continue;
        
        pat += dir[d];
        cnt[d]--;
        board[nx][ny] = 1;
        backtrack(nx, ny, len+1);

        board[nx][ny] = 0;
        cnt[d]++;
        pat.pop_back();
    }
}

int main() {
    board[0][0] = 1;
    backtrack();

    for(string pat : total) cout << pat << "\n";

    return 0;
}
