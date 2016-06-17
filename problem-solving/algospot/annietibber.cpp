// fenwick tree

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Fenwick {
  public:
    Fenwick(int size) : _tree(size + 1) {}

    void increase(int i, int delta) {
        for (; i < _tree.size(); i += (i & -i)) {
            _tree[i] += delta;
        }
    }

    int sum(int l, int r) {
        return sum(r - 1) - sum(l - 1);
    }

    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= (i & -i)) {
            res += _tree[i];
        }
        return res;
    }

  private:
    vector<int> _tree;
};

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int n, p, q;
        scanf("%d%d%d", &n, &p, &q);
        vector<pair<double, int>> annie;
        vector<pair<double, int>> tibber;
        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            annie.push_back(make_pair((double)(x - p) / y, i));
            tibber.push_back(make_pair((double)(q - x) / y, i));
        }
        sort(annie.begin(), annie.end());
        sort(tibber.begin(), tibber.end());
        
        int rank = 0;
        vector<int> tibber_rank(n);
        for (auto star : tibber) {
            tibber_rank[star.second] = ++rank;
        }

        Fenwick ft1(n);
        Fenwick ft2(n);
        
        for (auto star : annie) {
            int star_index = star.second;
            ft2.increase(tibber_rank[star_index], 1);
        }

        long long res = 0;
        for (auto star : annie) {
            int star_index = star.second;
            int rank = tibber_rank[star_index];

            ft2.increase(rank, -1);
            res += ft2.sum(rank, n + 1);

            res += ft1.sum(rank);
            ft1.increase(rank, 1);
        }
        printf("%lld\n", res / 2);
    }
    return 0;
}

