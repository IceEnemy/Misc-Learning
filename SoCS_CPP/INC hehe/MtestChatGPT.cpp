#include<bits/stdc++.h>
using namespace std;

struct datax {
    int x1;
    int y1;
    int t1;

    int x2;
    int y2;
    int t2;
};

int main() {
    int a;
    int b;
    int k;

    cin >> a >> b >> k;

    int n = min(a, b);
    int m = max(a, b);

    int total = 0;
    int tempN, tempM;

    if (n * m == k) {
        total = 0;
    } else if (m >= k) {
        total = 1;
    } else {
        tempN = n;
        tempM = m;

        do {
            datax res;
            for (int i = 1; i < tempM; i++) {
                if (tempN * (tempM - i) <= k) {
                    res.x1 = tempN;
                    res.y1 = i;
                    res.x2 = tempN;
                    res.y2 = tempM - i;
                    res.t1 = res.x1 * res.y1;
                    res.t2 = res.x2 * res.y2;
                    k -= res.t2;
                    total++;
                    tempN = min(res.x1, res.y1);
                    tempM = max(res.x1, res.y1);
                    break;
                }
            }
        } while (k > 0);

        n = tempN;
        m = tempM;
    }

    cout << total;

    return 0;
}

