// Codeforces 400/D
// [scc], [connected component]

using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program {
	static int N, M, K;
	static List<int> C;
	static List<Edge> E;
	
	static void Main() {
		Scanner sc = new Scanner();
		N = sc.Next<int>();
		M = sc.Next<int>();
		K = sc.Next<int>();
		C = sc.Next<int>(K);
		E = new List<Edge>();
		for (int i = 0; i < M; ++i) {
			E.Add(new Edge(sc.Next<int>() - 1, sc.Next<int>() - 1, sc.Next<int>()));
		}

		// kind of each bacteria.
		List<int> kind = new List<int>();
		{
			int k = 0;
			foreach(int c in C) {
				for (int j = 0; j < c; ++j) {
					kind.Add(k);
				}
				k++;
			}
		}

		// Get edges with zero cost.
		List<Edge> zeroEdge = E.Where(e => e.w == 0).ToList();

		// zero cost edge connected components.
		CCSolver ccSolver = new CCSolver(N, zeroEdge);
		List<int> cc = ccSolver.Solve();

		// check if bacteria of the same kind are in the same group.
		bool isYes = true;
		for (int i = 0, ci = -1, pk = -1; i < N; ++i) {
			if (pk != kind[i]) {
				ci = cc[i];
				pk = kind[i];
			} else if (ci != cc[i]) {
				isYes = false;
				break;
			}
		}

		if (isYes) {
			Console.WriteLine("Yes");
			int INF = 1000000000;
			int[,] D = new int[K, K];
			for (int i = 0; i < K; ++i) {
				for (int j = 0; j < K; ++j) {
					D[i, j] = INF;
				}
			}
			for (int i = 0; i < K; ++i) {
				D[i, i] = 0;
			}
			for (int i = 0; i < M; ++i) {
				int k1 = kind[E[i].u];
				int k2 = kind[E[i].v];
				D[k1, k2] = Math.Min(D[k1, k2], E[i].w);
				D[k2, k1] = Math.Min(D[k2, k1], E[i].w);
			}
			for (int k = 0; k < K; ++k) {
				for (int i = 0; i < K; ++i) {
					for (int j = 0; j < K; ++j) {
						D[i, j] = Math.Min(D[i, j], D[i, k] + D[k, j]);
					}
				}
			}
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < K; ++i) {
				for (int j = 0; j < K; ++j) {
					if (j > 0) {
						sb.Append(" ");
					}
					sb.Append(D[i, j] >= INF ? -1 : D[i, j]);
				}
				sb.Append("\n");
			}
			Console.Write(sb.ToString());
		} else {
			Console.WriteLine("No");
		}
	}
}

class Edge {
	public int u, v, w;
	public Edge(int u, int v, int w) {
		this.u = u;
		this.v = v;
		this.w = w;
	}
};

class CCSolver {
	int N;
	List<List<int>> G;
	List<bool> V;
	List<int> CC;
	int CI;

	public CCSolver(int n, List<Edge> edges) {
		N = n;
		G = new List<List<int>>();
		for (int i = 0; i < N; ++i) {
			G.Add(new List<int>());
		}
		foreach (Edge e in edges) {
			G[e.u].Add(e.v);
			G[e.v].Add(e.u);
		}
	}

	public List<int> Solve() {
		V = new List<bool>(new bool[N]);
		CC = new List<int>(new int[N]);
		CI = 0;
		for (int i = 0; i < N; ++i) {
			if (!V[i]) {
				Solve(i);
				CI++;
			}
		}
		return CC;
	}

	public void Solve(int u) {
		if (V[u]) return;
		V[u] = true;
		CC[u] = CI;
		
		foreach (int v in G[u]) {
			Solve(v);
		}
	}
}

class Scanner {
	private Queue<string> buffer = new Queue<string>();
	private TextReader tr;

	public Scanner() : this(Console.In) {}
	public Scanner(TextReader tr) {
		this.tr = tr;
	}

	public T Next<T>() {
		return (T)Convert.ChangeType(Next(), typeof(T));
	}

	public List<T> Next<T>(int n) {
		List<T> res = new List<T>();
		for (int i = 0; i < n; ++i) {
			res.Add(Next<T>());
		}
		return res;
	}

	public string Next() {
		while (buffer.Count == 0) {
			ReadLine();
		}
		return buffer.Dequeue();
	}

	private void ReadLine() {
		try {
			foreach (string token in this.tr.ReadLine().Split()) {
				if (token.Trim() != "") {
					buffer.Enqueue(token);
				}
			}
		} catch (Exception) {
		}
	}
}
 
