#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

class CKSwap {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;

        vector<vector<long long>> v (K, vector<long long>((N + K - 1) / K));

        for (int j = 0; j < (N + K - 1) / K; j++) {
            for (int i = 0; i < K; i++) {
                v.at(i).at(j) = 10000000000;
            }
        }

        for (int j = 0; j < (N + K - 1) / K; j++) {
            for (int i = 0; i < K; i++) {
                cin >> v.at(i).at(j);
            }
        }

        for (int i = 0; i < K; i++) {
            sort(v.at(i).begin(), v.at(i).end());
        }

        for (int j = 0; j < (N + K - 1) / K; j++) {
            for (int i = 0; i < K; i++) {
                if (i == K - 1 && j == (N + K - 1) / K - 1) {
                    cout << "Yes" << endl;
                    return;
                } else if (i == K - 1 && v.at(i).at(j) > v.at(0).at(j + 1)) {
                    cout << "No" << endl;
                    return;
                } else if (i < K - 1) {
                    if (v.at(i).at(j) > v.at(i + 1).at(j)) {
                        cout << "No" << endl;
                        return;
                    }
                }
            }
        }
    }
};