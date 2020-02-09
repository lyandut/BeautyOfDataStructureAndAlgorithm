//
// Created by 李研 on 2020/2/9.
//

#include "../tester.h"
#include "Backtracking.hpp"

ostream &operator<<(ostream &os, const EightQueens &eq) {
    os << "==== testEightQueens ====" << endl;
    return eq.printQueens(os);
}

void Tester::testBacktracking() {
    cout << "==== testBacktracking ====" << endl;
    EightQueens eq;
    eq.calQueens();
}