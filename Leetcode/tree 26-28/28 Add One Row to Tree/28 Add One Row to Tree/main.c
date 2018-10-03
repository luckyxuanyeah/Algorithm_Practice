//
//  main.c
//  28 Add One Row to Tree
//
//  Created by Ivana_xuan on 2018/4/5.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.

//Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1.
#include <stdio.h>
#include <malloc/malloc.h>
#define MAX 100000
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* addOneRow(struct TreeNode* root, int v, int d)
{
    struct TreeNode* queue[MAX],* temp[MAX];
    if(d==1)
    {
        struct TreeNode* newRoot;
        newRoot=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        newRoot->left=NULL;
        newRoot->right=NULL;
        newRoot->val=v;
        newRoot->left=root;
        return newRoot;
    }
    int in1=0,out1=0;
    queue[in1++]=root;
    int depth=1;
    while(depth<d-1)
    {
        int in2=0;
        while(out1<in1)
        {
            struct TreeNode* node;
            node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            node->left=NULL;
            node->right=NULL;
            node=queue[out1++];
            if(node->left!=NULL)
                temp[in2++]=node->left;
            if(node->right!=NULL)
                temp[in2++]=node->right;
        }
        for(int i=0;i<in2;i++)
            queue[in1++]=temp[i];
        depth++;
    }
    while(in1>out1)
    {
        struct TreeNode* temp1;
        temp1=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp1->left=NULL;
        temp1->right=NULL;
        
        temp1=queue[out1]->left;
        queue[out1]->left=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        queue[out1]->left->left=NULL;
        queue[out1]->left->right=NULL;
        queue[out1]->left->val=v;
        queue[out1]->left->left=temp1;
        
        temp1=queue[out1]->right;
        queue[out1]->right=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        queue[out1]->right->left=NULL;
        queue[out1]->right->right=NULL;
        queue[out1]->right->val=v;
        queue[out1]->right->right=temp1;
        out1++;
    }
    return root;
    /*
    while(out1<in1)
    {
        if(temp[out].depth<d-1)
        {
            temp[in].n=temp[out].n->left;
            temp[in++].depth=temp[out].depth+1;
            temp[in].n=temp[out].n->right;
            temp[in++].depth=temp[out].depth+1;
        }
        else if(temp[out].depth==d-1)
        {
            linshi1.n=temp[out].n->left;
            linshi1.depth=temp[out].depth+2;
            linshi2.n=temp[out].n->right;
            linshi2.depth=temp[out].depth+2;
            temp[out].n->left->val=v;
            temp[in].n=temp[out].n->left;
            temp[in].n->left=linshi1.n;
            temp[in++].depth=d;
            temp[out].n->right->val=v;
            temp[in].n=temp[out].n->right;
            temp[in].n->right=linshi2.n;
            temp[in++].depth=d;
        }
        out++;
    }
    return root;
     */
}


int main()
{
    return 0;
}
