// https://leetcode.cn/problems/minimum-cost-to-equalize-array/solutions/2765974/mei-ju-by-tsreaper-l8id/

class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int n = nums.size();
        int lim = 0;
        for (int x : nums) lim = max(lim, x);

        // 计算一开始每个桶里有几个石头
        long long sm = 0;
        int mx = 0;
        for (int x : nums) {
            int det = lim - x;
            sm += det;
            mx = max(mx, det);
        }

        const int MOD = 1e9 + 7;
        // 排除特殊情况
        if (nums.size() <= 2 || cost1 * 2 <= cost2) return sm * cost1 % MOD;

        long long ans = 1e18;
        // 从 lim 到 lim * 2 枚举目标数
        for (int i = lim; i <= lim * 2; i++) {
            long long tmp;
            if (mx > sm - mx) {
                // 情况 1
                tmp = (sm - mx) * cost2;
                long long rem = mx - (sm - mx);
                tmp += rem * cost1;
            } else {
                // 情况 2
                tmp = sm / 2 * cost2;
                if (sm & 1) tmp += cost1;
            }
            ans = min(ans, tmp);
            // 目标数每增加 1，s 增加 n，m 增加 1
            sm += n;
            mx++;
        }
        return ans % MOD;
    }
};

// 作者：TsReaper
// 链接：https://leetcode.cn/problems/minimum-cost-to-equalize-array/solutions/2765974/mei-ju-by-tsreaper-l8id/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
