#include <iostream>

using namespace std;

int main() {
    int n, a[1001] = {1, 1};
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            a[i] = a[i - 1] + a[i / 2];
        } else {
            a[i] = a[i - 1];
        }
    }
    cout << a[n];
    return 0;
}

// f498 = f1 + f2 + f3 + ... + f249
// f499 = f498
// f500 = f1 + f2 + f3 + ... + f249 + f250
// f500 = f499 + f250

// f2 = f1 + f1

//     6   1
//   1+6   f1
//   2+6   f2
//   3+6   f3
// 1+2+6   in f2
// 1+3+6   in f3

// f6 = f1 + f2 + f3 + 1
// f6 = 1 + 2 + 2 + 1


// 假设已知 f499 的答案，求 f500 的答案。 很显然，将 n=499 的所有解中的 499 由 500 替代之后，可以得出绝大多数 n=500 的解，
// 下面分析缺少的部分。由于 n=499 第一次添加的数从 1 到 249，而 n=500 第一次添加的数从 1 到 250，因此缺少的部分是 f250。

// 假设已知 f500 的答案，求 f501 的答案。将 n=500 的所有解中的 500 由 501 替代之后，可以得出绝大多数 n=501 的解，
// 下面分析缺少的部分。由于 n=500 第一次添加的数从 1 到 250，而 n=501 第一次添加的数也是从 1 到 250，因此不缺少。

// 递推公式：f2n=f2n−1+fnf2n​=f2n−1​+fn​, f2n+1=f2nf2n+1​=f2n​