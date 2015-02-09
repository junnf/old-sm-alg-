int V;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];

//拓扑序列
int cmp[MAX_V];

void add_edge(int from,int to){
G[from].push_back[to];
rG[to].push_back[from];
}

void dfs(int v){
	used[v] = true;
	for(int i = 0;i<G[v].size();i++) {
		if(!used[G[v][i]]) dfs(G[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v,int k)
{
	used[v] = true;
	cmp[v] = k;
	for(int i = 0;i<rG[v].size();i++) {
		if(!used[rG[v][i]]) dfs(rG[v][i]);
	}
}

int scc() {
	memset(used, 0, sizeof(used));
	vs.clear();
	for(int v = 0; v < V; v++) {
		if(!used[v]) dfs[v];
	}
	memset(used, 0, sizeof(used));
	int k = 0;
	for(int i = vs.size()-1;i>=0; i--) {
		if(!used[vs[i]]) rdfs(vs[i],k++);
	}
	return k;
}