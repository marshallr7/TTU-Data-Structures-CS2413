#include <iostream>
#include <list>

using namespace std;

class Graph {
  int v;

  list<int> *adj;

  public:
    Graph(int v) {
      this->v = v;
      adj = new list<int>[v];
    }

    void addEdge(int v, int w) {
      adj[v].push_back(w);
    }

  void breadthFirstSearch(int s) {
    bool *visited = new bool[v];

    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }
 
    list<int> queue;
 
    visited[s] = true;
    queue.push_back(s);
 
    list<int>::iterator i;
 
    while(!queue.empty()) {
        s = queue.front();
        cout << "visited " << queue.front() << "\n";
        queue.pop_front();
 
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
  }
};



int main() {
  Graph g(4);
  g.addEdge(2, 0);
  g.addEdge(2, 1);
  g.addEdge(2, 3);

  g.breadthFirstSearch(2);
} 
