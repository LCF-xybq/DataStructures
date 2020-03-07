class QuickUnionUF {
private:
  int *roots;
public:
  void QuickUnionUF(int N) {
    roots = new int[N];
    for (int i = 0; i < N; i++) {
      roots[i] = i;
    }
  }

  int findRoot(int i) {
    int root = i;
    while (root != roots[root]) {
      root = roots[root];
    }
    while (i != root) {
      int tmp = roots[i];
      roots[i] = root;
      i = tmp;
    }
    return root;
  }

  bool connected(int p, int q) {
    return findRoot(p) == findRoot(q);
  }

  void union(int p, int q) {
    int proot = findRoot(p);
    int qroot = findRoot(q);
    roots[proot] = qroot;
  }
};
