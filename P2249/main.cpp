#include <cstdio>
#include <cmath>
using namespace std;

int search(int target, int left, int right, unsigned int* list) {
    if (left == right) {
        if(list[left] == target) //left逼近到了right，如果找到目标，即为最左的目标值
            return left + 1;
        else //如果不为目标，即没有遇到相等情况
            return -1;
    }
    int mid = floor((left + right) / 2); //下一次查找的mid一定小于right(因为做了floor)
    if (target <= list[mid]) { //如果相等也继续查找，让left持续逼近，最终可以保证找到最左边的目标
        return search(target, left, mid, list); //当前mid也作为可能目标
    } else {
        return search(target, mid + 1, right, list);
    }
}

int main() {
    int n, m;
    scanf("%i%i", &n, &m);

    unsigned int list[n];
    for (int i = 0; i < n; i++)
        scanf("%i", &list[i]);
    for (int i = 0; i < m; i++) {
        int target, ans;
        scanf("%i", &target);
        printf("%i ", search(target, 0, n - 1, list));
    }
    return 0;
}