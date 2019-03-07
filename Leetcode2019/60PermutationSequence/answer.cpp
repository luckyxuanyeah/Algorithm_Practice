class Solution {
public:
    
char returnNum[10];
int num[10] = { 0 };
int find(int level,int n)
{
	int weizhi;
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (num[i] == -1)
			continue;
		else
		{
			count++;
			if (count == level)
			{
				weizhi = num[i];
				break;
			}
		}
	}
	return weizhi;
}
void DFS(int k,int lun,int n,int j)
{
	int kaitou;
	if (k%lun == 0)
	{
		kaitou = k / lun;
		kaitou = find(kaitou, n);
		num[kaitou] = -1;
		returnNum[j] = kaitou + 48;
		int count = j + 1;
		for (int i = n; i > 0; i--)
		{
			if (num[i] == -1)
				continue;
			else
				returnNum[count++] = num[i] + 48;
		}
	}
	else
	{
		kaitou = k / lun + 1;
		kaitou = find(kaitou, n);
		num[kaitou] = -1;
		returnNum[j] = kaitou + 48;
		k = k % lun;
		lun = lun / (n - j - 1);
		DFS(k, lun, n, j + 1);
	}
}
    string getPermutation(int n, int k) {
        for (int i = 1; i <= n; i++)
		    num[i] = i;
	    int number = 1;
	    for (int i = 1; i <= n; i++)
		    number = number * i;
	    int lun = number / n;
	    DFS(k, lun, n, 0);
        string a=returnNum;
        return a;
    }
};
//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Permutation Sequence.
//Memory Usage: 9.3 MB, less than 80.12% of C++ online submissions for Permutation Sequence.
//Next challenges: Next Permutation    Permutations
