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

double dist(double x, double y) {
    return sqrt(x * x + y * y);
}

struct Circle {
    double x, y, r, s;
};

double distrad(Circle a, Circle b) { 
    return dist(a.x - b.x, a.y - b.y);
}

double get_time(Circle a, Circle b) {
    return (distrad(a, b) - (a.r + b.r)) / (a.s + b.s);
}

bool collision(Circle a, Circle b) {
    return distrad(a, b) <= a.r + b.r;
}

void update(Circle& a, double t) {
    a.r += t * a.s;
}

Circle combine(const vector<Circle>& circles) {
    Circle c;

    c.x = 0, c.y = 0, c.s = 0, c.r = 0;

    for(auto a : circles) {
        c.r += a.r * a.r;
        c.x += a.x;
        c.y += a.y;
        c.s = max(c.s, a.s);
    }

    c.r = sqrt(c.r);
    c.x /= (double) circles.size();
    c.y /= (double) circles.size();

    return c;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    vector<Circle> circles(n);

    for(int i = 0; i < n; i++) {
        cin >> circles[i].x >> circles[i].y >> circles[i].r >> circles[i].s;
    }

    while((int)circles.size() > 1) {
        //cout << circles.size() << endl;
        double mind = 1e12;
        int a=0, b=0;

        vector<bool> marked(circles.size(), 0);

        for(int i = 0; i < (int) circles.size(); i++) {
            for(int j = i + 1; j < (int) circles.size(); j++) {
                if(get_time(circles[i], circles[j]) < mind) {
                    mind = get_time(circles[i], circles[j]);
                    a = i, b = j;
                }
            }
        }

        cout << mind << endl;

        marked[a] = marked[b] = 1;

        //cout << "mind: " << mind << endl;

        for(int i = 0; i < (int) circles.size(); i++)
            update(circles[i], mind);

        Circle curr = combine({circles[a], circles[b]});

        set<int> alives;

        for(int i = 0; i < (int) circles.size(); i++)
            if(!marked[i]) alives.insert(i);

        //cout << alives.size() << endl;

        while(true) {
            vector<Circle> to_combine(1, curr);
            vector<int> to_erase;

            for(int x : alives) {
                if(collision(curr, circles[x])) {
                    marked[x] = 1;
                    to_erase.pb(x);
                    to_combine.pb(circles[x]);
                }
            }

            if(to_erase.empty()) break;

            for(int x : to_erase) alives.erase(x);
            curr = combine(to_combine);
        }

        vector<Circle> tmp(1, curr);

        for(int i = 0; i < (int) circles.size(); i++)
            if(!marked[i]) tmp.pb(circles[i]);

        circles = tmp;
    }

    cout << setprecision(12) << fixed;
    cout << circles[0].x << " " << circles[0].y << "\n" << circles[0].r << "\n";
	
    return 0;
}


