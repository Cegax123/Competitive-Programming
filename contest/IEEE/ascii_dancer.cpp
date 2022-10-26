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
    
    auto get_leg = [](int status, char dir) {
        if(status == 0) {
            if(dir == 'L') return '/';
            else return '\\';
        }
        if(status == 1) {
            if(dir == 'L') return '<';
            else return '>';
        }
    };

    auto get_hand = [](int status, char dir) {
        if(status == 0) {
            if(dir == 'L') return '/';
            else return '\\';
        }
        
        if(status == 1) {
            if(dir == 'L') return '(';
            else return ')';
        }

        if(status == 2) {
            if(dir == 'L') return '<';
            else return '>';
        }
    };

    int t; cin >> t;
    while(t--) {
        int leg[2], hand[2];
        leg[0] = leg[1] = hand[0] = hand[1] = 0;

        bool front = 1;

        int d; cin >> d;

        while(d--) {
            string s; cin >> s;
            if(s == "say") {
                cin.ignore(); getline(cin, s);
                cout << s << "\n";
            }
            else {
                if(s == "turn") front = !front;
                else {
                    int idx = s == "right";
                    string b; cin >> b;
                    string t;
                    if(b == "hand") {
                        cin >> t >> t;
                        if(t == "start") hand[idx] = 0;
                        if(t == "head") hand[idx] = 1;
                        if(t == "hip") hand[idx] = 2;
                    }
                    else {
                        cin >> t;
                        if(t == "out") leg[idx] = 0;
                        if(t == "in") leg[idx] = 1;
                    }
                }

                char stick_man[3][3];

                for(int i = 0; i < 3; i++)
                    for(int j = 0; j < 3; j++)
                        stick_man[i][j] = ' ';

                stick_man[0][1] = 'o';
                stick_man[1][1] = '|';
                
                char lh, rh, ll, rl;

                if(front) {
                    lh = get_hand(hand[1], 'L');
                    rh = get_hand(hand[0], 'R');
                    ll = get_leg(leg[1], 'L');
                    rl = get_leg(leg[0], 'R');
                }
                else {
                    lh = get_hand(hand[0], 'L');
                    rh = get_hand(hand[1], 'R');
                    ll = get_leg(leg[0], 'L');
                    rl = get_leg(leg[1], 'R');
                }

                if(lh == '(') stick_man[0][0] = lh;
                else stick_man[1][0] = lh;

                if(rh == ')') stick_man[0][2] = rh;
                else stick_man[1][2] = rh;

                stick_man[2][0] = ll;
                stick_man[2][2] = rl;

                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        cout << stick_man[i][j];
                    }
                    cout << "\n";
                }

            }

        }
    }
	
    return 0;
}


