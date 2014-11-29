/*
* Data : 2014.11.27.
* Authore : jskim
* Description : divide conquer, QUADTREE, Low
*/

#include "stdafx.h"
#include "quadtree.h"


void quadtree()
{
	string strInput, strOutput;

	cin >> strInput;

	string::iterator it = strInput.begin();
	
	strOutput = reverse(it);

	cout << endl << "<output>" << endl;
	cout << strOutput << endl;

	return ;
}

string reverse(string::iterator& it)
{
	// 한 글자를 검사할 때마다 반복자를 한 칸 앞으로 이동
	char head = *it;
	++it;

	// base case, 첫 글자가 b 또는 w 경우
	if (head == 'b' || head == 'w')
		return string(1, head);

	string upperLeft  = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft  = reverse(it);
	string lowerRight = reverse(it);

	// 각각 위와 아래 조각들의 위치를 바꿈 -> 상/하 변형
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight; 
}