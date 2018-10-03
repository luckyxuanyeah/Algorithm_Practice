//
//  main.c
//  26 Maximum Width of Binary Tree
//
//  Created by Ivana_xuan on 2018/4/5.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//  Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

#include <stdio.h>
#define MAX 10000000000 
//4294967296

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TotalNode
{
    struct TreeNode* n;
    int depth;
    int pos;
};

int widthOfBinaryTree(struct TreeNode* root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 1;
    struct TotalNode temp[MAX];
    int in=0,out=0;
    temp[in].n=root;
    temp[in].depth=1;
    temp[in++].pos=1;
    int max=1;
    int curDepth=1;
    int left=1;
    while(out<in)
    {
        if(temp[out].n!=NULL)
        {
            temp[in].n=temp[out].n->left;
            temp[in].depth=temp[out].depth+1;
            temp[in++].pos=temp[out].pos*2;
            temp[in].n=temp[out].n->right;
            temp[in].depth=temp[out].depth+1;
            temp[in++].pos=temp[out].pos*2+1;
            if(curDepth!=temp[out].depth)
            {
                curDepth=temp[out].depth;
                left=temp[out].pos;
            }
            if(max<temp[out].pos-left+1)
                max=temp[out].pos-left+1;
        }
        out++;
    }
    return max;
}

int main()
{
    int N,E;
    scanf("%d%d",&N,&E);
    int a,b;
    struct TreeNode* root;
    for(int i=0;i<E;i++)
    {
        scanf("%d%d",&a,&b);
        root->left
    }
    return 0;
}
