int gcf(int a, int b) {
    int big, small;
    if (a == b) return a;
    if (a < b) {
        big = b;
        small = a;
    } else {
        big = a;
        small = b;
    }
    return gcf(small, big - small);
}

