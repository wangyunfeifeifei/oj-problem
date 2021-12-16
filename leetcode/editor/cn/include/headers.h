//
// Created by wang on 2021/12/15.
//

#ifndef POJ_PROBLEM_HEADERS_H
#define POJ_PROBLEM_HEADERS_H

#include <vector>
#include <algorithm>
#include <map>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //POJ_PROBLEM_HEADERS_H
