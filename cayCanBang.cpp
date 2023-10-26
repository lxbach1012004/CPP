//kiem tra dó có ph?i là cây nh? phân cân b?ng hay không

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int depth, vector<vector<int> > &adjList, vector<int> &depthList) {
    depthList[node] = depth;
    for (int x : adjList[node]) {
        if (x != parent) {
            dfs(x, node, depth + 1, adjList, depthList);
        }
    }
}

int main() {
	int n;
	cin >> n;
    vector<vector<int> > adjList(n);
    vector<int> depthList(n, 0);
    
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    dfs(0, -1, 0, adjList, depthList);
    bool balance = true;
    for (int i = 0; i < n; i++) {
        for (int x : adjList[i]) {
            if (abs(depthList[i] - depthList[x]) > 1) {
                balance = false;
                break;
            }
        }
    }
    if(balance) 
    	cout << "yes";
    else cout << "no";
    
}
