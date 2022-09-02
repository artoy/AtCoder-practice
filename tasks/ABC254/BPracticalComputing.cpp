#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

class BPracticalComputing {
public:

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        vector<vector<int>> Avec(50, vector<int>(50));
//        for (int i = 0; i < 30; i++) {
//            for (int j = 0; j < i + 1; j++) {
//                Avec.at(i).push_back(0);
//            }
//        }

        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    Avec.at(i).at(j) = 1;
                } else {
                    Avec.at(i).at(j) = Avec.at(i - 1).at(j - 1) + Avec.at(i - 1).at(j);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i + 1; j++) {
                cout << Avec.at(i).at(j);

                if (j == i) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }
    }
};