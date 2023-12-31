vector<int> is_prime, mnp, prime;
void sieve(int n) {
    is_prime.assign(n + 1, true);
    mnp.assign(n + 1, 0);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            mnp[i] = i;
        }
        for (auto x : prime) {
            if (i * x > n) break;
            is_prime[i * x] = false;
            mnp[i * x] = x;
            if (x == mnp[i]) break;
        }
    }
}
