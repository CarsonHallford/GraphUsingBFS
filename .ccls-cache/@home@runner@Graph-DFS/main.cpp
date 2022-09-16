#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <set>

int main() {
  std::map<std::string, Node> graph;

  // Read all the nodes.
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::string name;
    std::cin >> name;
    graph[name] = Node();
  }

  // Read all the edges.
  int m;
  std::cin >> m;
  for (int i = 0; i < m; i++) {
    std::string from, to;
    std::cin >> from >> to;
    graph[from].children.push_back(to);
  }

  // Read the node to start at.
  std::string start;
  std::cin >> start;
  
  // Perform a BFS.
  std::set<std::string> visited;
  std::queue<std::string> queue;
  queue.push(start);
  visited.insert(start);
  while (!queue.empty()) {
    std::string next = queue.front();
    queue.pop();
    std::cout << next << std::endl;
    for (std::string& child : graph[next].children) {
      if (visited.count(child) == 0) {
        visited.insert(child);
        queue.push(child);
      }
    }
  }
}