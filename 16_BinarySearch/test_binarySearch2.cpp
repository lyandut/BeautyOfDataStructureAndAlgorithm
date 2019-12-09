//
// Created by liyan on 2019/12/9.
//

#include "../tester.h"
#include "binarySearch2.hpp"

void Tester::testBinarySearch2() {
    cout << "==== testBinarySearch2 ====" << endl;

    vector<int> a = {1, 3, 4, 5, 6, 8, 8, 8, 11, 18};
    cout << BinarySearch2::bsearch_1(a, 8) << endl;
    cout << BinarySearch2::bsearch_2(a, 8) << endl;

    vector<int> b = {3, 4, 6, 7, 10};
    cout << BinarySearch2::bsearch_3(b, 5) << endl;
    cout << BinarySearch2::bsearch_4(b, 7) << endl;

    vector<int> c = {4, 5, 6, 7, 0, 1, 2};
    cout << BinarySearch2::searchInRotatedSortedArray_1(c, 0) << endl;
    cout << BinarySearch2::searchInRotatedSortedArray_2(c, 0) << endl;
}