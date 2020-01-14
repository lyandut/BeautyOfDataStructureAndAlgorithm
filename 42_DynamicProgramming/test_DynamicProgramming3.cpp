//
// Created by 李研 on 2020/1/13.
//

#include "../tester.h"
#include "DynamicProgramming3.hpp"

void Tester::testDynamicProgramming3() {
    cout << "==== testDynamicProgramming3 ====" << endl;

    string a = "mitcmu", b = "mtacnu";
    cout << DynamicProgramming3::lwstDP(a, b) << endl;
    cout << DynamicProgramming3::lcsDP(a, b) << endl;

    vector<int> aa = {2, 9, 3, 6, 5, 1, 7};
    cout << DynamicProgramming3::longestIncreaseSubsequence(aa) << endl;
}