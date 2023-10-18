// written by jiangly

struct Comb {
    int n;
    vector<modint> _fac;
    vector<modint> _invfac;
    vector<modint> _inv;

    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }

    void init(int m) {
        m = min(m, modint::getMod() - 1);
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }

    modint fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    modint invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    modint inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    modint binom(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

