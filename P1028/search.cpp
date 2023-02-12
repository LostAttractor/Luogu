#include <iostream>

using namespace std;

int* search(int last, int* sum) {
    for(int i = 1; i <= last / 2; i++) {
        *sum += 1;
        search(i, sum);
    }
    return sum;
}

int main() {
    int input;
    cin >> input;
    cout << *search(input, new int) + 1;
    return 0;
}