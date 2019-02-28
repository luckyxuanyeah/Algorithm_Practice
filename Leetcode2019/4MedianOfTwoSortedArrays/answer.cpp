#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int findKth(vector<int>& nums1,int i,vector<int>& nums2,int j,int k)
{
	//如何在两个有序数组中找到第K个元素；使用i,j来标识位置，来处理偏僻个例；
	//如果i或j大于数组的长度，那么这个数组就变成空数组了，只去另一个数组中查找就可以；
	//如果K=1，那么比较两个数组起始位置ij的值，就可以确定第K个元素。

	//普通情况下使用二分法，对K二分。
	//数组中到底存不存在第K/2个数字，如果存在就取出来，否则就赋值上一个整型最大值。
	//如果某个数组没有第K/2个数字，那么我们就淘汰另一个数组的前K/2个数字即可。
	//二分法的核心:
	//比较这两个数组的第K/2小的数字midVal1和midVal2的大小，如果第一个数组的第K/2个数字小的话，那么说明我们要找的数字肯定不在nums1中的前K/2个数字.
	//所以我们可以将其淘汰，将nums1的起始位置向后移动K/2个，并且此时的K也自减去K/2，调用递归。
	if (i >= nums1.size())
		return nums2[j + k - 1];
	if (j >= nums2.size())
		return nums1[i + k - 1];
	if (k == 1)
		return min(nums1[i], nums2[j]);
	//如果左边是真，那么选择：前面的
	//如果右边是真，那么选择：后面的
	int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
	int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
	if (midVal1 < midVal2)
		return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
	else
		return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
}

int main()
{
	vector<int> nums1, nums2;
	/*int a, b;
	while (scanf("%d", &a) != EOF)
		nums1.push_back(a);
	while (scanf("%d", &b) != EOF)
		nums2.push_back(b);*/
	nums1.push_back(1);
	nums1.push_back(2);
	nums2.push_back(3);
	nums2.push_back(4);
	int m = nums1.size();
	int n = nums2.size();
	//添加一个trick，求(m+n+1)/2和(m+n+2)/2的位置上的值的平均值！！
	int left = (m + n + 1) / 2;
	int right = (m + n + 2) / 2;
	printf("%lf", (findKth(nums1,0,nums2,0,left)+ findKth(nums1,0,nums2,0,right)) / 2.0);
	return 0;
}

//Runtime: 40 ms, faster than 97.04% of C++ online submissions for Median of Two Sorted Arrays.
//Memory Usage : 21.6 MB, less than 35.72% of C++ online submissions for Median of Two Sorted Arrays.
//Next challenges :
//Largest Rectangle in Histogram
//Maximize Distance to Closest Person
//Flip String to Monotone Increasing

//bool judge(int sum,int sum1,int i,int j)
//{
//	if (sum / 2 + 1 < sum1) //（找第sum/2+1个数）中位数在nums1[i]左边和nums2[j]左边（包含nums2）
//		i = i - 1;
//	else if (sum / 2 + 1 > sum1) //中位数在nums1[i]右边和
//	{
//
//	}
//	bool yes = false;
//
//	return yes;
//}

//int main()
//{
//	vector<int> nums1, nums2;
//	int a, b;
//	while (scanf("%d", &a) != EOF)
//		nums1.push_back(a);
//	while (scanf("%d", &b) != EOF)
//		nums2.push_back(b);
//	int m = nums1.size();
//	int n = nums2.size();
//	double ans = 0.0;
//	if (m == 0)
//	{
//		if (n / 2 == 0)
//			ans = ((double)(nums2[n / 2] + nums2[n / 2 + 1])) / 2;
//		else
//			ans = (double)nums2[n / 2];
//	}
//	else if (n == 0)
//	{
//		if (m / 2 == 0)
//			ans = ((double)(nums1[m / 2] + nums2[m / 2 + 1])) / 2;
//		else
//			ans = (double)nums1[m / 2];
//	}
//	else
//	{
//		int i = m / 2;
//		int j = n / 2;
//		int sum = m + n;
//		//添加一个trick，求（m+n+1）/2和（m+n+2）/2的位置上的值的平均值！！
//		if (sum / 2 == 0)
//		{
//			int position1 = sum / 2;
//			int position2 = sum / 2 + 1;
//
//		}
//		else if (sum / 2 != 0)
//		{
//			int position = sum / 2 + 1;//sum/2+1就是中位数的位置,现在逐渐缩小范围，找第position个位置的数
//			if (nums1[i] > nums2[j]) 
//			{
//				int sum1 = i + j + 1;
//				while (position != sum1)
//				{
//					if (judge(sum, sum1, i, j) == true)
//					{
//
//					}
//				}
//				if (position == sum1)
//				{
//					i = i - 1;
//					if (nums1[i] > nums2[j])
//						ans = nums1[i];
//					else
//						ans = nums2[j];
//				}
//			}
//			else if (nums1[i] < nums2[j])
//			{
//				int sum2 = ;
//
//			}
//		}
//	}
//	printf("%lf", ans);
//    return 0;
//}
