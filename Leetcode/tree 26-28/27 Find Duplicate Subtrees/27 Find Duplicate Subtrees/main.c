//
//  main.c
//  27 Find Duplicate Subtrees
//
//  Created by Ivana_xuan on 2018/4/5.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//  Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.
//  Two trees are duplicate if they have the same structure with same node values.

#include <stdio.h>
#include <malloc/malloc.h>
#define MAX 10000

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//Return an array of size *returnSize.
//Note: The returned array must be malloced, assume caller calls free().
struct TotalNode
{
    struct TreeNode* n;
    int pos;
    int num;
};

struct TotalNode temp[MAX];

int Count_subTree(struct TreeNode* node)
{
    if(node!=NULL)
        return Count_subTree(node->left)+Count_subTree(node->right)+1;
    return 0;
}

int FindSameVal(struct TotalNode Node1,struct TotalNode Node2)//已经找到两个点位置不一样而且子树的节点个数一样,而且节点上的值一样
{
    if(Node1.n!=NULL && Node2.n!=NULL)
    {
        if(Node1.n->val==Node2.n->val && Node1.num==Node2.num && Node1.pos!=Node2.pos)
        {
            if(FindSameVal(temp[Node1.pos*2],temp[Node2.pos*2])==1 && FindSameVal(temp[Node1.pos*2+1],temp[Node2.pos*2+1])==1)
                return 1;
        }
    }
    else if(Node1.n==NULL && Node2.n==NULL)
        return 1;
    return -1;
}
int count;
struct TreeNode** findDuplicateSubtrees(struct TreeNode* root, int* returnSize)
{
    int in=0,out=0;
    temp[in].n=root;
    temp[in++].pos=1;
    while(out<in)
    {
        if(temp[out].n!=NULL)
        {
            temp[in].n=temp[out].n->left;
            temp[in++].pos=temp[out].pos*2;
            temp[in].n=temp[out].n->right;
            temp[in++].pos=temp[out].pos*2+1;
        }
        out++;
    }
    
    int out2=0;
    
    while(out2<in)
    {
        temp[out2].num=Count_subTree(temp[out2].n);
        out2++;
    }
    int visited[MAX]={0};
    struct TreeNode **shuchu;
    shuchu=(struct TreeNode **)malloc(*returnSize*sizeof(struct TreeNode*));
    for(int i=0;i<*returnSize;i++)
    {
        shuchu[i]=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        shuchu[i]->left=NULL;
        shuchu[i]->right=NULL;
    }
    for(int i=0;i<in;i++)
    {
        for(int j=0;j<in;j++)
        {
            if(temp[i].n!=NULL && temp[j].n!=NULL)
            {
                if(FindSameVal(temp[i], temp[j])==1 && visited[i]==0 && visited[j]==0)
                {
                    visited[i]=1;
                    visited[j]=1;
                    shuchu[count++]=temp[i].n;
                }
            }
        }
    }
    return shuchu;
}

int main()
{
    struct TreeNode *root;
    root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left=NULL;
    root->left->right=NULL;
    root->right->left=NULL;
    root->right->right=NULL;
    scanf("%d%d%d",&root->val,&root->left->val,&root->right->val);
    int size=500;
    int *returnSize=&size;
    struct TreeNode** fanhui=findDuplicateSubtrees(root, returnSize);
    for(int i=0;i<count;i++)
        printf("%d\n",fanhui[i]->val);
    return 0;
}
