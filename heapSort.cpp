#include <iostream>
using namespace std;

void swap(int tree[], int i, int j) {
  int temp = tree[i];
  tree[i] = tree[j];
  tree[j] = temp;
}

void heapify (int tree[], int n, int i) {
  if (i >= n) {
    return;
  }
  int c1 = 2 * i + 1;
  int c2 = 2 * i + 2;
  int max = i;
  if (c1 < n &&tree[c1] > tree[max]) {
    max = c1;
  }
  if (c2 < n && tree[c2] > tree[max]) {
    max = c2;
  }
  if (max != i) {
    swap(tree, i, max);
    heapify(tree, n, max);
  }
}

void build_heap(int tree[], int n) {
  int last_node = n - 1;
  int parent = (last_node - 1) / 2;
  int i;
  for (i = parent; i >= 0; i--) {
    heapify(tree, n, i);
  }
}

void heap_sort(int tree[], int n) {
  build_heap(tree, n);
  int i;
  for (i = n - 1; i >= 0; i--) {
    swap(tree, i, 0);
    heapify(tree, i, 0);
  }
}

int main() {
  int tree[] = {4, 10, 3, 5, 1, 2, 6};
  int n = 7;
  heap_sort(tree, n);
  for (int i = 0; i < n; i++) {
    cout << tree[i] << endl;
  }
  return 0;
}
