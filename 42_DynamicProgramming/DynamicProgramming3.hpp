//
// Created by 李研 on 2020/1/13.
//

#ifndef BEAUTYOFDATASTRUCTUREANDALGORITHM_DYNAMICPROGRAMMING3_HPP
#define BEAUTYOFDATASTRUCTUREANDALGORITHM_DYNAMICPROGRAMMING3_HPP

#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class DynamicProgramming3 {
public:
    /*
     * 1. 莱文斯坦距离
     * 1.1 算法描述
     * 如果 a[i] 与 b[j] 匹配，递归考察 a[i+1] 和 b[j+1]，编辑距离不变；
     * 如果 a[i] 与 b[j] 不匹配：
     * - 可以删除 a[i] 或者在 b[j] 前面添加一个跟 a[i] 相同的字符，然后递归考察 a[i+1] 和 b[j]，编辑距离 +1；
     * - 可以删除 b[j] 或者在 a[i] 前面添加一个跟 b[j] 相同的字符，然后递归考察 a[i] 和 b[j+1]，编辑距离 +1；
     * - 可以将 a[i] 替换成 b[j] 或者将 b[j] 替换成 a[i]，然后递归考察 a[i+1] 和 b[j+1]，编辑距离 +1。
     *
     * 1.2 状态转移方程：
     * 如果：a[i]!=b[j]，
     * 那么：min_edist(i, j) = min(min_edist(i-1,j)+1, min_edist(i,j-1)+1, min_edist(i-1,j-1)+1)
     * 如果：a[i]==b[j]，
     * 那么：min_edist(i, j) = min(min_edist(i-1,j)+1, min_edist(i,j-1)+1，min_edist(i-1,j-1))
     */
    static int lwstDP(const string &a, const string &b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> min_dist(n + 1, vector<int>(m + 1));
        // 初始化第0行: 空字符串与b[0..j]的编辑距离
        for (int j = 0; j <= m; ++j) { min_dist[0][j] = j; }
        // 初始化第0列: a[0..i]与空字符串的编辑距离
        for (int i = 0; i <= n; ++i) { min_dist[i][0] = i; }
        // 按行填表
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i] == b[j]) {
                    min_dist[i][j] = std::min(min_dist[i - 1][j - 1],
                                              std::min(min_dist[i - 1][j] + 1, min_dist[i][j - 1] + 1));
                } else {
                    min_dist[i][j] = std::min(min_dist[i - 1][j - 1] + 1,
                                              std::min(min_dist[i - 1][j] + 1, min_dist[i][j - 1] + 1));
                }
            }
        }
        return min_dist[n][m];
    }


    /*
     * 2. 最长公共子串长度
     * 2.1 算法描述
     * 如果 a[i] 与 b[j] 匹配，递归考察 a[i+1] 和 b[j+1]，最大公共子串长度 +1；
     * 如果 a[i] 与 b[j] 不匹配：
     * - 删除 a[i]，或者在 b[j] 前面加上一个跟 a[i] 相同的字符，然后递归考察 a[i+1] 和 b[j]，最长公共子串长度不变；
     * - 删除 b[j]，或者在 a[i] 前面加上一个跟 b[j] 相同的字符，然后递归考察 a[i] 和 b[j+1]，最长公共子串长度不变。
     *
     * 2.2 状态转移方程
     * 如果：a[i]==b[j]，
     * 那么：max_lcs(i, j) = max(max_lcs(i-1,j-1)+1, max_lcs(i-1, j), max_lcs(i, j-1))
     * 如果：a[i]!=b[j]，
     * 那么：max_lcs(i, j) = max(max_lcs(i-1,j-1), max_lcs(i-1, j), max_lcs(i, j-1))
     */
    static int lcsDP(const string &a, const string &b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> max_lcs(n, vector<int>(m));
        //初始化第0行：a[0..0]与b[0..j]的maxlcs
        for (int j = 0; j < m; ++j) {
            if (a[0] == b[j]) max_lcs[0][j] = 1;
            else if (j == 0) max_lcs[0][j] = 0;
            else max_lcs[0][j] = max_lcs[0][j - 1];
        }
        //初始化第0列：a[0..i]与b[0..0]的maxlcs
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[0]) max_lcs[i][0] = 1;
            else if (i == 0) max_lcs[i][0] = 0;
            else max_lcs[i][0] = max_lcs[i - 1][0];
        }
        // 按行填表
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                int temp = std::max(max_lcs[i - 1][j], max_lcs[i][j - 1]);
                if (a[i] == b[j]) {
                    max_lcs[i][j] = std::max(temp, max_lcs[i - 1][j - 1] + 1);
                } else {
                    max_lcs[i][j] = std::max(temp, max_lcs[i - 1][j - 1]);
                }
            }
        }
        return max_lcs[n - 1][m - 1];
    }

    /*
     * 3. 最长递增子序列
     */
    static int longestIncreaseSubsequence(const vector<int> &a) {
        vector<int> states(a.size());
        // 起始状态
        states[0] = 1;
        // 动态规划
        for (int i = 1; i < states.size(); ++i) {
            int max_state = 0;
            for (int j = 0; j < i; ++j) {
                if (a[i] > a[j] && states[j] > max_state)
                    max_state = states[j];
            }
            states[i] = max_state + 1;
        }
        return *max_element(states.begin(), states.end());
    }

};


#endif //BEAUTYOFDATASTRUCTUREANDALGORITHM_DYNAMICPROGRAMMING3_HPP
