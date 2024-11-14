#include<bits/stdc++.h>

struct BinaryTreeNode {
    int val;
    BinaryTreeNode *left, *right;

    BinaryTreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    BinaryTreeNode(int val, BinaryTreeNode* left, BinaryTreeNode* right) : val(val), left(left), right(right) {};
};