int vi[N];
// int nvl[N], pai[N];
vector<int> g[N];
void dfs(int x, int p = -1){
	for (auto y : g[x]){
		if (y != p)
			dfs(y, x);
	//	nvl[y] = nvl[x] + 1; pai[y] = x;
	}
}
