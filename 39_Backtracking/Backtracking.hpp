//
// Created by 李研 on 2020/2/9.
//

#ifndef BEAUTYOFDATASTRUCTUREANDALGORITHM_BACKTRACKING_HPP
#define BEAUTYOFDATASTRUCTUREANDALGORITHM_BACKTRACKING_HPP

#include <iostream>
#include <vector>

using std::ostream;
using std::vector;

/*
 * 八皇后问题
 */
class EightQueens {
public:
    EightQueens(int queens_num = 8) : _queens_num(queens_num), _result(_queens_num) {}

    ostream &printQueens(ostream &os = std::cout) const {
        for (int row = 0; row < _queens_num; ++row) {
            for (int column = 0; column < _queens_num; ++column) {
                if (_result[row] == column)
                    os << "Q ";
                else
                    os << "* ";
            }
            os << std::endl;
        }
        os << std::endl;
        return os;
    }

    void calQueens(int row = 0) {
        if (row == _queens_num) { // 棋子都放置好了，打印结果
            printQueens();
            return;
        }
        for (int column = 0; column < _queens_num; ++column) { // 每一行都有列数_queens_num种放法
            if (isOk(row, column)) { // 有些放法不满足要求被剪枝
                _result[row] = column; // 第row行的棋子放到了column列
                calQueens(row + 1); // 考察下一行
            }
        }
    }


private:
    bool isOk(int row, int column) { //判断row行column列放置是否合适
        int leftup = column - 1, rightup = column + 1;
        for (int i = row - 1; i >= 0; --i) { // 逐行往上考察每一行
            if (_result[i] == column) { // 考察正上方：第i行的column列有棋子吗？
                return false;
            }
            if (leftup >= 0) { // 考察左上对角线：第i行leftup列有棋子吗？
                if (_result[i] == leftup) return false;
            }
            if (rightup < _queens_num) { // 考察右上对角线：第i行rightup列有棋子吗？
                if (_result[i] == rightup) return false;
            }
            --leftup;
            ++rightup;
        }
        return true;
    }

private:
    const int _queens_num;
    vector<int> _result; // 下标表示行,值表示queen存储在哪一列
};

#endif //BEAUTYOFDATASTRUCTUREANDALGORITHM_BACKTRACKING_HPP
