// Codeforces 383/C
// [fenwick], [fenwick tree]

using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;


class Program {
	static int N;
	static int M;
	static int[] A;
	static int[] P;
	static List<int>[] E;
	static Node[] T;
	static int[][] FT = new int[2][];

	class Node {
		public int even;
		public int di;
		public int fi;
	};

	static void Main() {
		Scanner sc = new Scanner();
		
		N = sc.Next<int>();
		M = sc.Next<int>();

		A = sc.NextN<int>(N);
		P = new int[N + 1];
		T = new Node[N + 1];
		E = new List<int>[N + 1];

		for (int i = 0; i <= N; ++i) {
			P[i] = 0;
			E[i] = new List<int>();
		}
		for (int i = 0; i < N - 1; ++i) {
			int u = sc.Next<int>();
			int v = sc.Next<int>();
			E[u].Add(v);
			E[v].Add(u);
		}

		BuildTree(1, 0, 0);
		T[0] = new Node();
		
		FT[0] = new int[dfsi[0] + 1];
		FT[1] = new int[dfsi[1] + 1];

		for (int q = 0; q < M; ++q) {
			int type = sc.Next<int>();
			int x = sc.Next<int>();
			int even = T[x].even;
			if (type == 1) {
				int d = sc.Next<int>();
				Inc(even, T[x].di, d);
				Inc(even, T[x].fi, -d);
			} else {
				int res = Sum(even, T[x].di) - Sum(1-even, T[P[x]].di);
				Console.WriteLine(res + A[x-1]);
			}
		}
	}

	static int[] dfsi = new int[2];
	static void BuildTree(int u, int parent, int depth) {
		if (T[u] != null) return;
		int even = depth % 2 == 0 ? 1 : 0;
		P[u] = parent;
		T[u] = new Node();
		T[u].even = even;
		T[u].di = ++dfsi[even];
		foreach (int v in E[u]) {
			BuildTree(v, u, depth + 1);
		}
		T[u].fi = ++dfsi[even];
	}

	static void Inc(int even, int i, int x) {
		for (; i < FT[even].Length; i = (i | (i - 1)) + 1) {
			FT[even][i] += x;
		}
	}

	static int Sum(int even, int i) {
		int res = 0;
		for (; i > 0; i = i & (i - 1)) {
			res += FT[even][i];
		}
		return res;
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

	public T[] NextN<T>(int n) {
		T[] res = new T[n];
		for (int i = 0; i < n; ++i) res[i] = Next<T>();
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
