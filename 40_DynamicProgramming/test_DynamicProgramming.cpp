//
// Created by 李研 on 2020/1/12.
//

#include "../tester.h"
#include "DynamicProgramming.hpp"

void Tester::testDynamicProgramming() {
    cout << "==== testDynamicProgramming ====" << endl;

    vector<int> weight = {2, 2, 4, 6, 3};
    vector<int> value = {3, 4, 8, 9, 6};
    cout << DynamicProgramming2::knapsack(weight, 5, 9) << endl;
    cout << DynamicProgramming2::knapsack_2(weight, 5, 9) << endl;
    cout << DynamicProgramming2::knapsack_3(weight, value, 5, 9) << endl;

    vector<vector<int>> triangle = {{2},
                                    {3, 4},
                                    {6, 5, 7},
                                    {4, 1, 8, 3}};
    cout << DynamicProgramming2::minimumTotal(triangle) << endl;
}