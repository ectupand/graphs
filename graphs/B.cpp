#include <iostream>
#include <vector>
using namespace std;


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

template <typename Matrix>
vector<Edge<size_t>> matrixToEdges(Matrix const& m) {
	vector<Edge<size_t>> edges;
	size_t n = sizeof(m) / sizeof(m[0]);
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			if (m[i][j] == 1) {
				edges.push_back(Edge<size_t>(i, j));
			}
		}
	}
	return edges;
}


int main() {
	const size_t n = 5;
	int m[n][n] = {
	{0, 1, 0, 0, 1},
	{1, 0, 1, 0, 0},
	{0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0},
	{1, 0, 1, 0, 0} };

	auto edges = matrixToEdges(m);
	for (auto edge : edges) {
		edge.vyvod();
	}

}