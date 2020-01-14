//
// Created by 李研 on 2020/1/12.
//

#ifndef BEAUTYOFDATASTRUCTUREANDALGORITHM_DYNAMICPROGRAMMING2_HPP
#define BEAUTYOFDATASTRUCTUREANDALGORITHM_DYNAMICPROGRAMMING2_HPP

#include <vector>
#include <algorithm>

using std::vector;

/*
 * 棋盘左上角到右下角的最短路径
 */
class DynamicProgramming2 {
public:
    /*
     * 1. 状态转移表法
     */
    static int minDistStateTable(const vector<vector<int>> &matrix, int n) {
        vector<vector<int>> states(n, vector<int>(n, 0));
        int sum = 0;
        for (int j = 0; j < n; ++j) { // 初始化states第一行
            sum += matrix[0][j];
            states[0][j] = sum;
        }
        sum = 0;
        for (int i = 0; i < n; ++i) { // 初始化states第一列
            sum += matrix[i][0];
            states[i][0] = sum;
        }
        // 模拟状态转移填表过程
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                states[i][j] = matrix[i][j] + std::min(states[i - 1][j], states[i][j - 1]);
            }
        }
        return states[n - 1][n - 1];
    }

    /*
     * 2. 状态转移方程法
     */
    static int minDistStateEquation(const vector<vector<int>> &matrix, int n) {
        vector<vector<int>> mem(n, vector<int>(n, 0)); // 备忘录
        return minDistRecursion(n - 1, n - 1, matrix, mem);
    }

private:
    static int minDistRecursion(int i, int j, const vector<vector<int>> &matrix, vector<vector<int>> &mem) {
        if (i == 0 && j == 0) return matrix[0][0]; // 递归终止条件
        if (mem[i][j] > 0) return mem[i][j]; // “备忘录”避免重复计算
        // 递归计算
        int min_left = INT_MAX;
        if (j - 1 >= 0) min_left = minDistRecursion(i, j - 1, matrix, mem);
        int min_up = INT_MAX;
        if (i - 1 >= 0) min_up = minDistRecursion(i - 1, j, matrix, mem);
        int min_curr = matrix[i][j] + std::min(min_left, min_up); // 状态转移方程
        mem[i][j] = min_curr;
        return mem[i][j];
    }
};

#endif //BEAUTYOFDATASTRUCTUREANDALGORITHM_DYNAMICPROGRAMMING2_HPP
