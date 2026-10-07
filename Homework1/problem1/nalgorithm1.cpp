#include <iostream>
#include <stack>
using namespace std;
int ack(int m, int n) {
	stack<int> s1;
	s1.push(m);
	while (!s1.empty()) {
		m = s1.top();
		s1.pop();
		if (m == 0)n += 1;
		else if (n == 0) {
			s1.push(m - 1);
			n = 1;
		}
		else {
			s1.push(m - 1);
			s1.push(m);
			n -= 1;
		}
	}
	return n;
}
int main() {
	int m1, n1;
	cin >> m1 >> n1;
	cout << ack(m1, n1);
}
