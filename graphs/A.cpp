using namespace std;
#include <vector>
#include <iostream>


template <class T>
class Edge {
public:
	T start; T end;
	Edge(T _start, T _end) {
		start = _start; end = _end;
	}
	void vyvod() {
		cout << "(" << start << ", " << end << ")";
	}
};
template <class T>
using EdgeList = vector<Edge<T>>;


template <typename EdgeList, typename Vertex>
void connect_vertices_undirected_edge_list(
	EdgeList& el, Vertex u, Vertex v) {
	el.emplace_back(u, v);
	el.emplace_back(v, u);
}
int main()
{
	EdgeList<int> edgeList = EdgeList<int>{
		Edge<int>(0, 1),
		Edge<int>(0, 2),
		Edge<int>(1, 3)
	};
	connect_vertices_undirected_edge_list(edgeList, 2, 3);
	for (auto edge : edgeList) { edge.vyvod(); cout << endl; }
}