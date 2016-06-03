// Codeforces Round #264 (Div. 2) E. Caisa and Tree (463/E)
// [math], [prime], [prime factor]

import java.io.*;
import java.util.*;
import java.util.stream.*;

public class CaisaAndTree {
  public static void main(String[] args) {
    Solver solver = new Solver();
    solver.solve();
  }
}

class Vertex {
  public int id;
  public int depth;
  public int v;
  public LinkedList<Vertex> neighbors = new LinkedList<Vertex>();
  public LinkedList<Integer> pfs = null;

  public Vertex(int id, int v) {
    this.id = id;
    this.v = v;
  }

  public void add(Vertex v) {
    this.neighbors.add(v);
  }

  public void factorize(Factorizer fz) {
    this.pfs = fz.factorize(v);
  }
}

class Factorizer {
  public int [] fs;

  public Factorizer(int maxValue) {
    fs = new int[maxValue + 1];
    for (int i = 2; i <= maxValue; ++i) {
      if (fs[i] == 0) {
        for (long j = (long)i * i; j <= maxValue; j += i) {
          if (fs[(int)j] == 0) {
            fs[(int)j] = i;
          }
        }
        fs[i] = i;
      }
    }
  }

  public LinkedList<Integer> factorize(int n) {
    LinkedList<Integer>res = new LinkedList<Integer>();
    while (n > 1) {
      int factor = fs[n];
      res.add(factor);
      while (n % factor == 0) {
        n /= factor;
      }
    }
    return res;
  }
}

class Searcher {
  Vertex[] vs;
  Vertex[] ui;
  Vertex[] ls;
  boolean[] vd;

  public Searcher(Vertex[] vs, int maxValue) {
    this.vs = vs;
    this.ui = new Vertex[this.vs.length + 1];
    this.ls = new Vertex[maxValue + 1];
    this.vd = new boolean[this.vs.length + 1];
  }

  public void search() {
    search(this.vs[1], 1);
  }

  public void search(Vertex v, int depth) {
    if (this.vd[v.id]) {
      return;
    }
    
    v.depth = depth;
    this.vd[v.id] = true;
    
    Vertex lastest = null;
    Vertex[] before = new Vertex[v.pfs.size()];
    int i = 0;
    for (int pf : v.pfs) {
      Vertex lastv = this.ls[pf];
      if (lastv != null) {
        if (lastest == null || lastest.depth < lastv.depth) {
          lastest = lastv;
        }
      }
      this.ls[pf] = v;
      before[i++] = lastv;
    }
    
    this.ui[v.id] = lastest;
    
    for (Vertex vertex : v.neighbors) {
      search(vertex, depth + 1);
    }
    
    i = 0;
    for (int pf : v.pfs) {
      this.ls[pf] = before[i++];
    }
  }

  public int getuid(Vertex v) {
    if (this.ui[v.id] == null) {
      return -1;
    } else {
      return this.ui[v.id].id;
    }
  }
}

class Solver {
  final int MAX_VALUE = 2000000;
  
  void solve() {
    MyReader in = new MyReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(System.out);

    int n = in.nextInt();
    int q = in.nextInt();
    Vertex[] vs = new Vertex[n + 1];
    
    for (int i = 1; i <= n; ++i) {
      vs[i] = new Vertex(i, in.nextInt());
    }
    
    for (int i = 1; i < n; ++i) {
      int x = in.nextInt();
      int y = in.nextInt();
      vs[x].add(vs[y]);
      vs[y].add(vs[x]);
    }

    Factorizer fz = new Factorizer(MAX_VALUE);
    
    for (int i = 1; i <= n; ++i) {
      vs[i].factorize(fz);
    }

    Searcher searcher = new Searcher(vs, MAX_VALUE);
    searcher.search();

    for (int i = 0; i < q; ++i) {
      int t = in.nextInt();
      int v = in.nextInt();
      if (t == 1) {
        out.println(searcher.getuid(vs[v]));
      } else {
        vs[v].v = in.nextInt();
        vs[v].factorize(fz);
        searcher = new Searcher(vs, MAX_VALUE);
        searcher.search();
      }
    }
    out.close();
  }
}

class MyReader extends BufferedReader {
  StringTokenizer st = null;

  public MyReader(Reader in) {
    super(in);
  }

  public int nextInt() {
    return Integer.parseInt(nextToken());
  }

  public long nextLong() {
    return Long.parseLong(nextToken());
  }

  public double nextDouble() {
    return Double.parseDouble(nextToken());
  }

  public String nextString() {
    return nextToken();
  }

  public String nextToken() {
    try {
      if (st == null || !st.hasMoreTokens()) {
        st = new StringTokenizer(readLine());
      }
      return st.nextToken();
    } catch (Exception e) {
      return "";
    }
  }
}
