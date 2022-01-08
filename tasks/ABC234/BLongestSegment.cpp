#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

class BLongestSegment {
public:
    int lengthSquare(pair<double, double> p, pair<double, double> q) {
        return pow((p.first - q.first), 2) + pow((p.second - q.second), 2);
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        vector<pair<double, double>> dots(N);
        for (int i = 0; i < N; ++i) {
            cin >> dots.at(i).first >> dots.at(i).second;
        }

        int ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                    ans = max(ans, lengthSquare(dots.at(i), dots.at(j)));
            }
        }

        cout << fixed << setprecision(10);
        cout << sqrt(ans) << endl;
    }
};