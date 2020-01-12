//
// Created by 李研 on 2020/1/12.
//

#ifndef BEAUTYOFDATASTRUCTUREANDALGORITHM_DYNAMICPROGRAMMING2_HPP
#define BEAUTYOFDATASTRUCTUREANDALGORITHM_DYNAMICPROGRAMMING2_HPP

#include <vector>

using std::vector;

/*
 * 棋盘左上角到右下角的最短路径
 */
class DynamicProgramming2 {
public:
    /*
     * 1. 状态转移表法
     */
    static int minDistDP(const vector<vector<int>> &matrix, int n) {
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
                int min = states[i - 1][j] < states[i][j - 1] ? states[i - 1][j] : states[i][j - 1];
                states[i][j] = matrix[i][j] + min;
            }
        }
        return states[n - 1][n - 1];
    }

    /*
     * 2. 状态转移方程法
     */
    static int minDistDP2(){

    }

};

#endif //BEAUTYOFDATASTRUCTUREANDALGORITHM_DYNAMICPROGRAMMING2_HPP
