//
// Created by 李研 on 2020/1/12.
//

#ifndef BEAUTYOFDATASTRUCTUREANDALGORITHM_DYNAMICPROGRAMMING_HPP
#define BEAUTYOFDATASTRUCTUREANDALGORITHM_DYNAMICPROGRAMMING_HPP

#include <vector>

using std::vector;

class DynamicProgramming2 {
public:
    /*
     * 1. 0-1背包问题：求背包中可装入物品总重量的最大值
     * weight:物品重量，n:物品个数，w:背包可承载重量
     */
    static int knapsack(const vector<int> &weight, int n, int w) {
        vector<vector<bool>> states(n, vector<bool>(w + 1, false)); // 二维状态转移表
        // 起始状态：第一个物品放 or 不放
        states[0][0] = true;
        if (weight[0] <= w) states[0][weight[0]] = true;
        // 动态规划状态转移
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= w; ++j) { // 第i个物品不放入背包
                if (states[i - 1][j] == true) states[i][j] = true;
            }
            for (int j = 0; j <= w - weight[i]; ++j) { // 第i个物品放入背包
                if (states[i - 1][j] == true) states[i][j + weight[i]] = true;
            }
        }
        // 输出结果
        for (int j = w; j >= 0; --j) {
            if (states[n - 1][j] == true) return j;
        }
        return 0;
    }

    /*
     * 2. 0-1背包改进
     * 使用一维数组作状态转移表
     */
    static int knapsack_2(const vector<int> &weight, int n, int w) {
        vector<bool> states(w + 1, false); // 初始化一维状态转移表
        // 起始状态
        states[0] = false;
        if (weight[0] <= w) states[weight[0]] = true;
        // 动态规划
        for (int i = 1; i < n; ++i) {
            for (int j = w - weight[i]; j >= 0; --j) { // 第i个物品放入背包，Ps：从大到小处理
                if (states[j] == true) states[j + weight[i]] = true;
            }
        }
        // 输出结果
        for (int j = w; j >= 0; --j) {
            if (states[j] == true) return j;
        }
        return 0;
    }

    /*
     * 3. 0-1背包升级版：求背包中可装入物品总价值的最大值
     * weight:物品重量，value:物品价值，n:物品个数，w:背包可承载重量
     */
    static int knapsack_3(const vector<int> &weight, const vector<int> &value, int n, int w) {
        vector<int> states(w + 1, -1); // 初始化一维状态转移表
        // 起始状态
        states[0] = 0;
        if (weight[0] <= w) states[weight[0]] = value[0];
        // 动态规划
        for (int i = 1; i < n; ++i) {
            for (int j = w - weight[i]; j >= 0; --j) { // 第i个物品放入背包，Ps：从大到小处理
                if (states[j] >= 0) {
                    int v = states[j] + value[i];
                    if (v > states[j + weight[i]]) states[j + weight[i]] = v;
                }
            }
        }
        // 输出结果
        int max_value = -1;
        for (int j = 0; j <= w; ++j) {
            if (states[j] > max_value) max_value = states[j];
        }
        return max_value;
    }

    /*
     * 4. LeetCode120 三角形最小路径和
     */
    static int minimumTotal(vector<vector<int>> &triangle) {
        vector<int> dp(triangle.size() + 1, 0);
        for (int i = triangle.size() - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                int min = dp[j] < dp[j+1] ? dp[j] : dp[j+1];
                dp[j] = min + triangle[i][j];
            }
        }
        return dp[0];
    }

};

#endif //BEAUTYOFDATASTRUCTUREANDALGORITHM_DYNAMICPROGRAMMING_HPP
