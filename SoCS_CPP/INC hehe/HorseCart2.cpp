#include <bits/stdc++.h>
using namespace std;

struct treasure {
    long long weight;
    long long price;
    double ratio;
};

bool customComp(treasure a, treasure b) {
    if (a.ratio == b.ratio) return a.price < b.price;
    return a.ratio > b.ratio;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<treasure> chest(N);
    vector<long long> cap(M);

    for (int i = 0; i < N; i++) {
        cin >> chest[i].weight >> chest[i].price;
        chest[i].ratio = (double)chest[i].price / chest[i].weight;
    }

    sort(chest.begin(), chest.end(), customComp);
    sort(cap.begin(), cap.end());

    int num = 0;
    long long total = 0;

    for (int i = 0; i < N; i++) {
        for (int j = num; j < M; j++) {
            if (cap[j] >= chest[i].weight) {
                num = j + 1;
                total += chest[i].price;
                break;
            }
        }
    }

    cout << total << endl;
    return 0;
}

