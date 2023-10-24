#include<bits/stdc++.h>
using namespace std;

int treeHeight(map<int, vector<int>> &adjList, int node) {
	int height = 0;
	for (int child : adjList[node]) {
		height = max(height, 1 + treeHeight(adjList, child));
	}
	return height;
}

void preOrder(map<int, vector<int>> &adjList, int node) {
	cout << node << " ";
	for (int child : adjList[node]) {
		preOrder(adjList, child);
	}
}

void postOrder(map<int, vector<int>> &adjList, int node) {
	for (int child : adjList[node]) {
		postOrder(adjList, child);
	}
	cout << node << " ";
}

bool isBinaryTree(map<int, vector<int>> &adjList) {
	int nodeSize;
	for (auto it = adjList.begin(); it != adjList.end(); it++) {
		nodeSize = (it -> second).size();
		if(nodeSize != 0 && nodeSize != 2)
			return false;
	}
	return true;
}

void inOrder(map<int, vector<int>> &adjList, int node) {
	if (adjList[node].size() == 1) {
		inOrder(adjList, adjList[node][0]);
		cout << node << " ";
	}
	else if (adjList[node].size() == 2) {
		inOrder(adjList, adjList[node][0]);
		cout << node << " ";
		inOrder(adjList, adjList[node][1]);
	}
	else cout << node << " ";
		
}

int main() {
	map<int, vector<int>> adjList;
	int N, M, x, y;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		adjList[x].push_back(y);
	}
	
	cout << treeHeight(adjList, 1) << endl;
	
	preOrder(adjList, 1);
	cout << endl;
	
	postOrder(adjList, 1);
	cout << endl;
	
	if (isBinaryTree(adjList))
		inOrder(adjList, 1);
	else cout << "NOT BINARY TREE"; 
	
}
