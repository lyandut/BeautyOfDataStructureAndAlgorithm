//
// Created by 李研 on 2020/1/12.
//

#include "../tester.h"
#include "DynamicProgramming2.hpp"

void Tester::testDynamicProgramming2() {
    cout << "==== testDynamicProgramming2 ====" << endl;

    vector<vector<int>> matrix = {{1, 3, 5, 9}, {2, 1, 3, 4}, {5, 2, 6, 7}, {6, 8, 4, 3}};
    cout << DynamicProgramming2::minDistStateTable(matrix, 4) << endl;
    cout << DynamicProgramming2::minDistStateEquation(matrix, 4) << endl;
}