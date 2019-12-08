//
// Created by liyan on 2019/12/8.
//

#ifndef BEAUTYOFDATASTRUCTUREANDALGORITHM_BINARYSEARCH_HPP
#define BEAUTYOFDATASTRUCTUREANDALGORITHM_BINARYSEARCH_HPP


#include <vector>

using std::vector;

class BinarySearch {
public:
    /*
     * 1. 二分查找的简单实现
     */
    static int bsearchSimple(const vector<int> &a, int n, int value) {
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] < value) {
                low = mid + 1;
            } else if (a[mid] > value) {
                high = mid - 1;
            } else {
                return mid;
            }
        }

        return -1;
    }

    /*
     * 2. 二分查找递归实现
     */
    static int bsearchRecursion(const vector<int> &a, int n, int value) {
        return bsearchInternally(a, 0, n - 1, value);
    }

private:
    static int bsearchInternally(const vector<int> &a, int low, int high, int value) {
        if (low > high) { return -1; }

        int mid = low + ((high - low) >> 1); // 优化: 防止 low+high 溢出, 位运算比除法效率高
        if (a[mid] < value) {
            return bsearchInternally(a, mid + 1, high, value);
        } else if (a[mid] > value) {
            return bsearchInternally(a, low, mid - 1, value);
        } else {
            return mid;
        }
    }
};

#endif //BEAUTYOFDATASTRUCTUREANDALGORITHM_BINARYSEARCH_HPP
