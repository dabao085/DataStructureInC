#include <stdio.h>
#include <string.h>

int* getPrefix(char P[])	//在自己身上找重复的子串，字符串的下标从1开始
{
	int m = strlen(P);
	int pi[3] = {0};
	pi[1] = 0;
	int k = 0;
	for (int q = 2; q <= m;q++)
	{
		while (k > 0 && P[k + 1] != P[q])
		{
			k = pi[k];
		}
		if (P[k + 1] == P[q])
			k = k + 1;
		pi[q] = k;
	}

	return pi;
}

void KMP_Matcher(char T[],char P[],int length1,int length2)
{
	int n = length1;
	int m = length2;
	int *ppi;
	ppi= getPrefix(P, length2);
	int q = 0;
	for (int i = 1; i <= n; i++)
	{
		while (q > 0 && P[q + 1] != T[i])
		{
			q = ppi[q];
		}
		if (P[q + 1] == T[i])
		{
			q = q + 1;
		}
		if (q == m)
		{
			printf("Pattern occurs with shift %d\n",i-m);
			q = ppi[q];
		}
	}
	
}

int main()
{
	char ch1[] = " hello world! wo";
	char ch2[] = " wo";
	KMP_Matcher(ch1, ch2, 17, 3);
	return 0;
}
