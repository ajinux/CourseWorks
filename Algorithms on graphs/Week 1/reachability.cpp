#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int reach(vector<vector<int> > &adj, vector<int> &visited, int x, int y) {
	visited[x] = 1;
	for (int i = 0; i < adj[x].size(); i++)
	{
		if (adj[x][i] == y)
			return 1;
		else if (visited[adj[x][i]] == 0)
			if(reach(adj, visited, adj[x][i], y) == 1)
            {
                return 1;
            }
	}
	return 0;
}

int main() {
	size_t n, m;
	std::cin >> n >> m; //n - no. of vertices and m - no. of edges
	vector<vector<int> > adj(n, vector<int>()); //initializing a adjacency list
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	int x, y;
	std::cin >> x >> y; // x - from, y - to
	vector<int> visited(n, 0);
	std::cout << reach(adj, visited, x - 1, y - 1);
}
