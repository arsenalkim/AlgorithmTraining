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
	// �� ���ڸ� �˻��� ������ �ݺ��ڸ� �� ĭ ������ �̵�
	char head = *it;
	++it;

	// base case, ù ���ڰ� b �Ǵ� w ���
	if (head == 'b' || head == 'w')
		return string(1, head);

	string upperLeft  = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft  = reverse(it);
	string lowerRight = reverse(it);

	// ���� ���� �Ʒ� �������� ��ġ�� �ٲ� -> ��/�� ����
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight; 
}