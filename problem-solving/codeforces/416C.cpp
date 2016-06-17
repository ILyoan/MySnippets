// Codeforces 416/C
// [fenwick], [fenwick tree]

#include <cstdio>
#include <vector>
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

class Paper {
 public:
   Paper(int length) : ft(length + 1), lo(1), ro(length), flipped(false) {
     for (int i = 1; i <= length; ++i) {
       ft.increase(i, 1);
     }
   }

   void fold(int p) {
     if (flipped) {
       if (ro - 2 * p + 1 < lo) {
         flipped = !flipped;
         fold(ro - lo - p + 1);
       } else {
         int i = ro - p;
         int j = i + 1;
         while (j <= ro) {
           ft.increase(i, ft.sum(j, j + 1));
           --i;
           ++j;
         }
         ro -= p;
       }
     } else {
       if (lo + 2 * p - 1> ro) {
         flipped = !flipped;
         fold(ro - lo - p + 1);
       } else {
         int i = lo + p - 1;
         int j = i + 1;
         while (i >= lo) {
           ft.increase(j, ft.sum(i, i + 1));
           --i;
           ++j;
         }
         lo += p;
       }
     }
   }

   int query(int l, int r) {
     if (flipped) {
       return ft.sum(ro - r + 1, ro - l + 1);
     } else {
       return ft.sum(lo + l, lo + r);
     }
   }

 private:
   Fenwick ft;
   int lo;
   int ro;
   bool flipped;
};

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  Paper paper(n);
  for (int i = 0; i < q; ++i) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int p;
      scanf("%d", &p);
      paper.fold(p);
    }
    else {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", paper.query(l, r));
    }
  }

  return 0;
}
