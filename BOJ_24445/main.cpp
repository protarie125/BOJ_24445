#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

int n, m, r;
vvi adj;
vi ans;
int now;

void bfs() {
	auto visit = vb(n + 1, false);
	auto q = queue<int>{};
	q.push(r);
	visit[r] = true;

	while (!q.empty()) {
		auto f = q.front();
		q.pop();

		ans[f] = now;
		++now;

		for (const auto& y : adj[f]) {
			if (visit[y]) {
				continue;
			}

			q.push(y);
			visit[y] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m >> r;

	adj = vvi(n + 1, vi{});
	while (0 < (m--)) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (auto&& x : adj) {
		sort(x.begin(), x.end(), greater());
	}

	now = 1;
	ans = vi(n + 1, 0);
	bfs();

	for (auto i = 1; i <= n; ++i) {
		cout << ans[i] << '\n';
	}

	return 0;
}