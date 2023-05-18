#include <iostream>
int a[25] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,7,7,8,8,8,8,8,9,9,9,10};
int main() {
    int pre = a[0], k = 0;
    for (int i = 1; i < 25; ++i) {
        if (pre == a[i]) {
            k++;
        } else {
            pre = a[i];
            a[i - k] = a[i];
        }
    }
    for (int i = 0; i < 25; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl << k;
    return 0;
}
