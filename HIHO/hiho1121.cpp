/*
━━━━━┒ギリギリ♂ eye！
┓┏┓┏┓┃キリキリ♂ mind！
┛┗┛┗┛┃＼○／
┓┏┓┏┓┃ /
┛┗┛┗┛┃ノ)
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┃┃┃┃┃┃
┻┻┻┻┻┻
*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define fr first
#define sc second
#define cl clear
#define BUG puts("here!!!")
#define W(a) while(a--)
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%lld", &a)
#define Rs(a) scanf("%s", a)
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))
#define lrt rt << 1
#define rrt rt << 1 | 1
#define pi 3.14159265359
#define RT return
#define lowbit(x) x & (-x)
#define onenum(x) __builtin_popcount(x)
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<LL, LL> pll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

typedef struct Edge {
	int u, v;
	int next;
}Edge;

const int maxn = 10010;
const int maxm = 80080;
int n, m, ecnt;
int color[maxn];
int head[maxn];
Edge edge[maxm];
int q[maxm], front, tail;

void init() {
	ecnt = 0;
	Clr(head, -1); Clr(color, -1);
}
void adde(int u, int v) {
	edge[ecnt].u = u;
	edge[ecnt].v = v;
	edge[ecnt].next = head[u];
	head[u] = ecnt++;
}

bool bfs(int u) {
	front = tail = 0;
	color[u] = 0;
	q[tail++] = u;
	int p = -1;
	while(front < tail) {
		int t = q[front++];
		for(int i = head[t]; ~i; i=edge[i].next) {
			int v = edge[i].v;
			if(v == t) continue;
			if(color[v] == -1) {
				color[v] = 1 ^ color[t];
				q[tail++] = v;
			}
			else if(color[v] == color[t]) return 0;
		}
	}
	return 1;
}

int main() {
	// FRead();
	int T, u, v;
	Rint(T);
	W(T) {
		Rint(n); Rint(m);
		init();
		Rep(i, m) {
			Rint(u); Rint(v);
			adde(u, v); adde(v, u);
		}
		bool exflag = 0;
		For(i, 1, n+1) {
			if(color[i] == -1) {
				if(bfs(i) == 0) {
					exflag = 1;
					break;
				}
			}
		}
		if(exflag) printf("Wrong\n");
		else printf("Correct\n");
	}
	RT 0;
}