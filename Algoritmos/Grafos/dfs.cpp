int vi[N];
// int nvl[N], pai[N];
void dfs(int x){
	if (vi[x])
		return;
	vi[x] = true;
	for (auto y : g[x]){
		dfs(y);
	//	nvl[y] = nvl[x] + 1; pai[y] = x;
	}
}
