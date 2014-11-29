/*
* Data : 2014.11.07.
* Authore : jskim
* Description : brute force, PICNIC, Low
*/

#include "stdafx.h"
#include "picnic.h"

// Input
int nStudents;					// 2 <= n <= 10
int nCouples;					// 0 <= m <= 45
bool arrCouples[10][10] = {false,};	

void picnic(int nTestCase)
{
	int nValue[10];

	for (int n = 0; n < nTestCase; n++)
	{
		scanf("%d %d", &nStudents, &nCouples);			// Keyboard Input-2

		for (int i = 0; i < nCouples; i++)
		{
			int val_1, val_2;
			scanf("%d %d", &val_1, &val_2);				// Keyboard Input-3

			// 가장 빠른 번호부터 순서 대로 삽입
			if (val_1 < val_2)
				arrCouples[val_1][val_2] = true;
			else
				arrCouples[val_2][val_1] = true;
		}
		
		bool taken[10] = {false,};
		nValue[n] = countPairings(taken);
	}

	printf("\n <output> \n");

	for (int i = 0; i < nTestCase; i++)
		printf("%d\n", nValue[i]);

	scanf("%d", &nValue[9]);

	return;
}

int countPairings(bool taken[10])
{
	// 가장 빠른 번호부터
	int firstFree = -1;

	for (int i = 0; i < nStudents; i++)
	{
		if ( !taken[i] )
		{
			firstFree = i;
			break;
		}
	}

	// 기저 사례 : 모든 학생이 짝을 찾았으면
	if ( firstFree == -1 )
	{
		printf("\n");
		return 1;
	}

	int ret = 0;
	// 짝지을 학생 결정
	for (int pairWith = firstFree+1; pairWith < nStudents; pairWith++)
	{
		if ( !taken[pairWith] && arrCouples[firstFree][pairWith] )
		{
			printf("(%d,%d) ", firstFree, pairWith);
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret;
}