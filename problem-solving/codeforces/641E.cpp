// Codeforces VK Cup 2016 - Round 2. E. Little Artem and Time Machine
// [fenwick], [fenwick tree]

#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class FenwickTree {
  public:
    FenwickTree(int n) : _tree(n + 1) {}

    // Returns sum of [0..pos]
    int Sum(int pos) {
        int res = 0;
        for (int i = pos + 1; i > 0; i &= (i - 1)) {
            res += _tree[i];
        }
        return res;
    }
    
    // Add x to A[pos]
    int Increase(int pos, int x) {
        for (int i = pos + 1; i < _tree.size(); i += (i & -i)) {
            _tree[i] += x;
        }
    }
  private:
    vector<int> _tree;
};

struct Query {
    int i, a, t, x, p;
    Query(int _i, int _a, int _t, int _x) : i(_i), a(_a), t(_t), x(_x), p(0) {}
};

int main() {
    int n;
    scanf("%d", &n);
    map<int, vector<Query>> queries_map;

    for (int i = 0; i < n; ++i) {
        int a, t, x;
        scanf("%d%d%d", &a, &t, &x);
        queries_map[x].push_back(Query(i, a, t, x));
    }

    vector<pair<int, int>> answers;

    for (auto& queries_item : queries_map) {
        auto x = queries_item.first;
        auto queries = queries_item.second;
        int count = queries.size();
        vector<pair<int, Query*>> times;
        for (auto& query : queries) {
            times.push_back(make_pair(query.t, &query)); 
        }
        sort(times.begin(), times.end());
        for (int i = 0; i < times.size(); ++i) {
            times[i].second->p = i;
        }

        FenwickTree ft(count);
        for (auto& query : queries) {
            if (query.a == 1) {
                ft.Increase(query.p, 1);
            } else if (query.a == 2) {
                ft.Increase(query.p, -1);
            } else {
                answers.push_back(make_pair(query.i, ft.Sum(query.p)));
            }
        }
    }

    sort(answers.begin(), answers.end());

    for (auto answer : answers) {
        printf("%d\n", answer.second);
    }

    return 0;
}

