using namespace std;
#include <vector>
#include <iostream>
#include <string>


bool is_01(const std::string& str)
{
	return str.find_first_not_of("01") == std::string::npos;
}

vector<vector<bool>> read_01matrix(istream& in) {
	vector<string> stringMatrix;
	string stringValue;
	vector<vector<bool>> boolMatrix;
	getline(in, stringValue);

	while (is_01(stringValue) and !stringValue.empty()) {//cin 01 matrix
		stringMatrix.push_back(stringValue);
		getline(in, stringValue);
	}

	size_t len = 0;
	for (size_t i = 0; i < stringMatrix.size(); i++) {
		if (len < stringMatrix[i].length())	len = stringMatrix[i].length();//find longest line
	}

	for (string& row : stringMatrix) { //fill irregular lines with zeros
		row.resize(len, '0');
	}

	for (auto& row : stringMatrix) {//turn string matrix to bool
		vector<bool> boolRow;
		for (auto cell : row) {
			if (cell == '0') {
				boolRow.push_back(false);
			}
			else if (cell == '1') {
				boolRow.push_back(true);
			}
		}
		boolMatrix.push_back(boolRow);
	}
	return boolMatrix;
}


void write_01matrix(ostream& out, vector<vector<bool>> const& matrix) {
	for (auto& row : matrix) {
		for (auto cell : row) {
			out << cell;
		}
		out << '\n';
	}
	out << '\n';
}
int main() {
	vector<vector<bool>> m = read_01matrix(cin);
	write_01matrix(cout, m);
	return 0;
}