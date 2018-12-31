#include "iostream"
using namespace std;

int main()
{
	int k1, k2;
  scanf("%d", &k1);
  int N1[11], N2[11], N3[21];
  double A1[11], A2[11], A3[21];
  for (int i = 0; i < k1; i++)
    scanf("%d%lf", &N1[i], &A1[i]);
  scanf("%d", &k2);
  for (int i = 0; i < k2; i++)
    scanf("%d%lf", &N2[i], &A2[i]);
  int index1 = 0, index2 = 0, index3 = 0;
  while (index1<k1 || index2<k2)
  {
    if (N1[index1] < N2[index2] && index1<k1 && index2<k2)
    {
        N3[index3] = N2[index2];
        A3[index3] = A2[index2];
        index2++, index3++;
    }
    else if (N1[index1] == N2[index2] && index1<k1 && index2<k2)
    {
        N3[index3] = N1[index1];
        A3[index3] = A1[index1] + A2[index2];
        if(A3[index3]==0)
            index1++,index2++;
        else
            index1++, index2++, index3++;
    }
    else if (N1[index1] > N2[index2] && index1<k1 && index2<k2)
    {
        N3[index3] = N1[index1];
        A3[index3] = A1[index1];
        index3++, index1++;
    }
    else if(index1==k1 && index2!=k2)
    {
        N3[index3] = N2[index2];
        A3[index3] = A2[index2];
        index3++,index2++;
    }
    else if(index2==k2 && index1!=k1)
    {
        N3[index3]=N1[index1];
        A3[index3]=A1[index1];
        index3++,index1++;
    }
  }
  printf("%d", index3);
  for (int i = 0; i < index3; i++)
    printf(" %d %.1f", N3[i], A3[i]);
  return 0;
}
