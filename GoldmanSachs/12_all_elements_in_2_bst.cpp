#include<bits/stdc++.h>
using namespace std;


/*
    1. Do inorder in first tree and find order
    2. Do inorder in second tree and find order
    3. merge both binary trees
*/
vector<int> merge(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();
    vector<int> result;
    int i=0, j=0;
    while(i!=n && j!=m){
        if(arr1[i] < arr2[j])
            result.push_back(arr1[i++]);

        else if(arr1[i] > arr2[j])
            result.push_back(arr2[j++]);

        else{
            result.push_back(arr1[i++]);
            result.push_back(arr2[j++]);
        }
    }
    while(i!=n)
        result.push_back(arr1[i++]);
    while(j!=m)
        result.push_back(arr2[j++]);

    return result;
}

void inorder(TreeNode* root, vector<int> &ans){
    if(root == NULL) return;

    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> arr1;
    vector<int> arr2;
    vector<int> result;

    inorder(root1, arr1);
    inorder(root2, arr2);

    result = merge(arr1, arr2);
    return result;
}


int main()
{

    return 0;
}