#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_NODE = 1000000 + 10;
const int CHARSET  = 26;
int trie[MAX_NODE][CHARSET] = {0};
int color[MAX_NODE] = {0};
int k = 1;

void insert(char *w) {
	int len = strlen(w);
	int p = 0;
	for (int i = 0; i < len; i++) {
		int c = w[i] - 'a';
		if (!trie[p][c]) {
			trie[p][c] = k++;
		}
		p = trie[p][c];
	}
	color[p] = 1;
}

int search(char *w) {
	int len = strlen(w);
	int p   = 0;
	for (int i = 0; i < len; i++) {
		int c = w[i] - 'a';
		if (!trie[p][c]) return 0;
		p = trie[p][c];
	}
	return color[p] == 1;
}

int main() {
	int in, se;
	char s[20];
	cin >> in >> se;
	while (in--) {
		cin >> s;
		insert(s);
	}
	while (se--) {
		cin >> s;
		if (search(s)) cout << "Y" << endl;
		else cout << "N" << endl;
	}
	return 0;
}
