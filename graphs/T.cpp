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

template <class T>
using EdgeList = vector<Edge<T>>;


class Matrix
{
	using Row = vector <int>;
	using Repr = vector <Row>;
	Repr m;
public:
	Matrix(EdgeList<int> edgeList) {
		int matrixsize = 0;
		for (auto edge : edgeList) {
			if (edge.end > matrixsize) { matrixsize = edge.end; }
			if (edge.start > matrixsize) { matrixsize = edge.start; }
		}
		//create empty matrix
		for (int i = 0; i <= matrixsize; i++) {
			m.push_back(Row(matrixsize + 1));
		}
		//fill matrix
		for (auto edge : edgeList) {
			m[edge.start][edge.end] = 1;
		}
	}
	void vyvod() {
		for (auto row : m) {
			for (auto cell : row) {
				cout << cell << '\t';
			}
			cout << '\n';
		}
	}
};

int main() {
	EdgeList<int> edgeList = EdgeList<int>{
		Edge<int>(0, 1),
		Edge<int>(0, 2),
		Edge<int>(1, 3)
	};
	for (auto edge : edgeList) { edge.vyvod(); cout << endl; }

	Matrix matrix = Matrix(edgeList);
	matrix.vyvod();

	return 0;
}