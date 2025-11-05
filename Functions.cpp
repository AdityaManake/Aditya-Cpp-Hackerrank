#include <iostream>
using namespace std;

int max_of_four(int a, int b, int c, int d) {
    if (a >= b && a >= c && a >= d)
        return a;
    else if (b >= a && b >= c && b >= d)
        return b;
    else if (c >= a && c >= b && c >= d)
        return c;
    else
        return d;
}

int main() {
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    cout << max_of_four(w, x, y, z) << endl;
    return 0;
}
