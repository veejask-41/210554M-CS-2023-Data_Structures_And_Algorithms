int power_sum_count (int x, int n, int i = 1) {
    int p = pow (i, n);
    if (p > x) return 0;
    if (p == x) return 1;
    return power_sum_count (x, n, i + 1) + power_sum_count (x - p, n, i + 1);
}