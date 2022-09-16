// Code written by Carson Hallford
// BFS Stackoverflow for guidance/reference: https://stackoverflow.com/questions/2505431/breadth-first-search-and-depth-first-search/2508261#:~:text=BFS%20is%20an%20uninformed%20search,goal%20until%20it%20finds%20it.

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

class Node {
 public:
  Node(std::string name) : name(name) {}
  std::string name;
  // a vector of all the outgoing connections to other nodes.
  std::vector<Node*> children;
};

// a map holding all the nodes by their name.
std::map<std::string, Node> graph;

int main() {
  // TODO: implement
  std::string name;
  std::string temp;
  std::map<std::string, Node> graph;
  int n;

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> name;
    Node n = Node(name);
    graph.emplace(name, n);
  }

  int m;
  std::string name1, name2;
  std::cin >> m;
  for (int i = 0; i < m; i++) {
    std::cin >> name1 >> name2;
    graph.at(name1).children.push_back(&graph.at(name2));
  }

  std::cin >> temp;
  std::queue<std::string> queue;
  queue.push(temp);

  std::set<std::string> visit;
  while (!queue.empty()) {
    // use queue front
    std::string temp2 = queue.front();

    queue.pop();

    if (!visit.count(temp2)) {
      std::cout << temp2 << std::endl;
      visit.insert(temp2);
      for (int i = 0; i < graph.at(temp2).children.size(); i++) {
        { queue.push(graph.at(temp2).children[i]->name); }
      }
    }
  }
}