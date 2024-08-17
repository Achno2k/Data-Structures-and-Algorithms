#include <bits/stdc++.h>
using namespace std;

void topoSortBFS(int V, vector<int> adj[]) {
	int indegree[V] = {0};
	for (int i=0; i<V; i++) {
		for (auto it: adj[i]) {
			indegree[it]++;
		}
	}

	queue<int> q;
	for (int i=0; i<V; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";
		for (auto it: adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0) {
				q.push(it);
			}
		}
	}
}

void dfs(int node, vector<int> adj[], stack<int>& stk, int vis[]) {
	vis[node] = 1;
	for (auto it: adj[node]) {
		if (!vis[it]) {
			dfs(it, adj, stk, vis);
		}
	}
	stk.push(node);
}

void topoSortDFS(int V, vector<int> adj[]) {
	stack<int> stk;
	int vis[V] = {0};
	for (int i=0; i<V; i++) {
		if (!vis[i]) {
			dfs(i, adj, stk, vis);
		}
	}
	while (!stk.empty()) {
		cout << stk.top() << " ";
		stk.pop();
	}
}

int main() {
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0,1}, {2,0}};
	topoSortBFS(6, adj);
	cout << endl;
	topoSortDFS(6, adj);

	return 0;
}