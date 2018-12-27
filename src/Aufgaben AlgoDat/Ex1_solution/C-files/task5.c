int power(int base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent % 2) return base*power(base, exponent-1);
    else {
        int temp = power(base, exponent/2);
        return temp*temp;
    }
}
