#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int i, j, k, T, N[100010], s, e;

int main() {
  cin >> T;
  for (i = 0; i < T; i++) {
    int max = -10000, s1 = 1, sum = 0;
    cin >> k;
    for (j = 1; j <= k; j++) {
      cin >> N[j];
      sum += N[j];
      if (sum > max) {
        max = sum;
        s = s1;
        e = j;
      }
      if (sum < 0) {
        sum = 0;
        s1 = j + 1;
      }
    }
    if (i != 0) cout << endl;
    cout << "Case " << i + 1 << ":" << endl;
    cout << max << " " << s << " " << e << endl;
  }
  return 0;
}
