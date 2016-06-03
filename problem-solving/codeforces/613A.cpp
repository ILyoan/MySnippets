// Codeforces Round #339 (Div.1) A.Peter and Snow Blower
// [geometry], [line], [vector]

#include <cstdio>
#include <cmath>

const int MAX_N = 100000;
const double INF = 1e15;
const double PI = 3.141592653589793;
struct Point {
  double x, y;
};

typedef Point Vector;

Point polygon[MAX_N + 1];

double min(double a, double b) { return a < b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }
double abs(double a) { return a >= 0 ? a : -a; }

double dist(Point p1, Point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}


double dist_line(Point p, Point p1, Point p2) {
  double len = dist(p2, p1);
  Vector v1 = { p2.x - p1.x, p2.y - p1.y };
  Vector v2 = { p.x - p1.x, p.y - p1.y };
  double dot = v1.x * v2.x + v1.y * v2.y;
  double prj = dot / len;
  if (prj < 0 || prj > len) return INF;
  Point vp = { p1.x + v1.x * prj / len, p1.y + v1.y * prj / len };
  return dist(p, vp);
}

double circle(double r) {
  return r * r * PI;
}

int main() {
  int n;
  Point p;
  scanf("%d%lf%lf", &n, &p.x, &p.y);
  for (int i = 0; i < n; ++i) {
    scanf("%lf%lf", &polygon[i].x, &polygon[i].y);
  }
  double near = INF;
  double far = 0;
  polygon[n] = polygon[0];
  for (int i = 0; i < n; ++i) {
    Point p1 = polygon[i];
    Point p2 = polygon[i + 1];
    far = max(far, dist(p, p1));
    far = max(far, dist(p, p2));
    near = min(near, dist(p, p1));
    near = min(near, dist(p, p2));
    near = min(near, dist_line(p, p1, p2));
  }
  printf("%.15lf\n", circle(far) - circle(near));

  return 0;
}
