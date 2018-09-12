//
//  main.c
//  3 Longest Substring Without Repeating Characters
//
//  Created by Ivana_xuan on 2018/4/18.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.

//Given a string, find the length of the longest substring without repeating characters.

//Examples:
//Given "abcabcbb", the answer is "abc", which the length is 3.
//Given "bbbbb", the answer is "b", with the length of 1.
//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <stdio.h>

int lengthOfLongestSubstring(char* s)
{
    int length=0;
    while(s[length]!='\0')
        length++;
    if(length==0 || length==1)
        return length;
    int i=0;
    int j=i+1;
    while(i<length && j<length)
    {
        for(int k=i;k<j;k++)
        {
            if(s[j]==s[k])
            {
                i=k+1;
                break;
            }
        }
        j++;
    }
}
int main()
{
    
    return 0;
}
