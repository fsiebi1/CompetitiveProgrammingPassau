#include <iostream>
#include <queue>

using namespace std;

vector<pair<int, int>> outp;

int main() {
	int n;
	cin >> n;

	priority_queue<pair<int, int>> q;

	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x)
			q.push({x, i});
	}

	while (q.size() > 1) {
		pair<int, int> a, b;
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();

//		printf("%d %d, %d %d - %d\n", a.first, a.second, b.first, b.second, q.size());

		a.first--;
		b.first--;

		if (a.first)
			q.push(a);
		if (b.first)
			q.push(b);

		outp.push_back({a.second, b.second});
	}

	if(q.empty()) {
		printf("yes\n");
		for(int i = 0; i < outp.size(); i++)
			printf("%d %d\n", outp[i].first, outp[i].second);

	} else {
		printf("no\n");
	}

	return 0;
}
