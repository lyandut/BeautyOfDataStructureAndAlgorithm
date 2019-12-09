//
// Created by liyan on 2019/12/9.
//

#ifndef BEAUTYOFDATASTRUCTUREANDALGORITHM_BINARYSEARCH2_HPP
#define BEAUTYOFDATASTRUCTUREANDALGORITHM_BINARYSEARCH2_HPP

#include <vector>
#include "../15_BinarySearch/binarySearch.hpp"

using std::vector;

class BinarySearch2 {
public:
    /*
     * 变体一: 查找第一个值等于给定值的元素
     */
    static int bsearch_1(const vector<int> &a, int value) {
        int low = 0, high = a.size() - 1;

        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (a[mid] > value) {
                high = mid - 1;
            } else if (a[mid] < value) {
                low = mid + 1;
            } else {
                if ((mid == 0) || (a[mid - 1] != value)) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }

    /*
     * 变体二: 查找最后一个值等于给定值的元素
     */
    static int bsearch_2(const vector<int> &a, int value) {
        int low = 0, high = a.size() - 1;

        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (a[mid] > value) {
                high = mid - 1;
            } else if (a[mid] < value) {
                low = mid + 1;
            } else {
                if ((mid == a.size() - 1) || (a[mid + 1] != value)) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            }
        }

        return -1;
    }

    /*
     * 变体三: 查找第一个大于等于给定值的元素
     */
    static int bsearch_3(const vector<int> &a, int value) {
        int low = 0, high = a.size() - 1;

        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (a[mid] >= value) {
                if ((mid == 0) || (a[mid - 1] < value)) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }

    /*
     * 变体四: 查找最后一个小于等于给定值的元素
     */
    static int bsearch_4(const vector<int> &a, int value) {
        int low = 0, high = a.size() - 1;

        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (a[mid] <= value) {
                if ((mid == a.size() - 1) || (a[mid + 1] > value)) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }

    /* ===========================================
     * LeetCode 33: Search in Rotated Sorted Array
     * 假设数组中不存在重复的元素，时间复杂度必须是 O(log n) 级别。
     * ===========================================
     *
     * 思路1：二分查找旋转下标，分成两个有序数组，分别做两个简单二分查找。
     * 关于循环退出条件，low和high的更新需要仔细斟酌
     * https://github.com/lyandut/MyLeetCode/blob/master/searchInRotatedSortedArray.cpp
     */
    static int searchInRotatedSortedArray_1(const vector<int> &a, int value) {
        if (a.empty()) { return -1; }
        if (a.size() == 1) { return a[0] == value ? 0 : -1; }

        int rotation_index = 0;
        int low = 0, high = a.size() - 1;
        if (a[low] > a[high]) {
            while (low <= high) {
                int mid = low + ((high - low) >> 1);
                if (a[mid] > a[mid + 1]) {
                    rotation_index = mid + 1;
                    break;
                }

                if (a[mid] >= a[low]) { // 前半部分为有序数组
                    low = mid + 1;
                } else { // 后半部分为有序数组
                    high = mid - 1;
                }
            }
        }

        int l_res = BinarySearch::bsearchInternally(a, 0, rotation_index - 1, value);
        int h_res = BinarySearch::bsearchInternally(a, rotation_index, a.size() - 1, value);

        return l_res == -1 ? h_res : l_res;
    }

    /*
     * 思路2：二分之后，总有一半是有序数组，另一半是循环数组。
     */
    static int searchInRotatedSortedArray_2(const vector<int> &a, int value) {
        int low = 0, high = a.size() - 1;

        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (a[mid] == value) { return mid; }

            if (a[mid] >= a[low]) { // 前半部分为有序数组
                if ((a[mid] > value) && (a[low] <= value)) { // value在有序部分
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else { // 后半部分为有序数组
                if ((a[mid] < value) && (a[high] >= value)) { // value在有序部分
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }


};

#endif //BEAUTYOFDATASTRUCTUREANDALGORITHM_BINARYSEARCH2_HPP
