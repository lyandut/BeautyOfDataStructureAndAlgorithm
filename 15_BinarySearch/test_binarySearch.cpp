//
// Created by liyan on 2019/12/8.
//

#include "../tester.h"
#include "binarySearch.hpp"

void Tester::testBinarySearch() {
    cout << "==== testBinarySearch ====" << endl;

    vector<int> a = {8, 11, 19, 23, 27, 33, 45, 55, 67, 98};
    cout << BinarySearch::bsearchSimple(a, a.size(), 19) << endl;
    cout << BinarySearch::bsearchRecursion(a, a.size(), 19) << endl;

    cout << BinarySearch::bsearchSqrt(10) << endl;
}