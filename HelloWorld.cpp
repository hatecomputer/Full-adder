#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_vector(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

vector<int> sum(int size,int other_size,vector<int> &x, vector<int> &y) {
	int i;
	int carry = 0;
	vector<int> z(size+1);
	for (i = other_size; i < size; i++) {
		y.insert(y.begin(), 1 ,0);
	}
	for (i = size-1; i >= 0; i--) {
		if ((x[i] == 1) && (y[i] == 1)) {
			if (carry == 1) {
				z[i + 1] = 1;
				carry = 1;
			}
			else {
				z[i + 1] = 0;
				carry = 1;
			}
		}
		else if (x[i] != y[i]) {
			if (carry == 1) {
				z[i+1] = 0;
				carry = 1;
			}
			else {
				z[i+1] = 1;
				carry = 0;
			}
		}
		else {
			if (carry == 1) {
				z[i+1] = 1;
				carry = 0;
			}
			else {
				z[i+1] = 0;
				//carry = 0;
			}
		}	
	
	}
	if (carry == 1) {
		z[0] = 1;
	}
	else {
		z.erase(z.begin());
	}
	print_vector(z);
	cout << endl << endl;
	return z;
}

int main() {
	vector<int> a;
	vector<int> b;
	int i;
	char temp;

	for (i = 0; ; i++) {
		cin.get(temp);
		if (temp == ' ') continue;
		if (temp == '\n') break;
		a.push_back((int)temp-48);
	}
	while (1) {
		vector<int> value;
		value.clear();
		b.clear();
		for (i = 0; ; i++) {
			cin.get(temp);
			if (temp == ' ') continue;
			if (temp == '\n') break;
			b.push_back((int)temp - 48);
		}

		if (a.size() >= b.size()) {
			value = sum(a.size(), b.size(), a, b);
		}
		else {
		 	value = sum(b.size(), a.size(), b, a);
		}
		a.swap(value);
	}
}