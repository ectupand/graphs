#include <iostream>
using namespace std;

template <typename Matrix>
size_t edges_counter(Matrix const& m) {
	size_t count = 0;
	size_t n = sizeof(m) / sizeof(m[0]);
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < i; j++) {
			if (m[i][j] == 1) {
				count++;
			}
		}
	}
	return count;
}

void print(size_t count) {
	if (count == 1) {
		cout << "V graphe 1 rebro";
	}
	else if (count < 5) {
		cout << "V graphe " << count << " rebra";
	}
	else if (count >= 5) {
		cout << "V graphe " << count << " ryober";
	}
}

int main() {
	const size_t n = 5;
	int m[n][n] = {
	{0, 1, 0, 0, 1},
	{1, 0, 1, 0, 0},
	{0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0},
	{1, 0, 1, 0, 0} };

	size_t count = edges_counter(m);
	print(count);

}