/*
Convert prefix to postfix expression.
	Written by: wowo0709
	Date: 2021-03-11
*/
// ǥ��� �ٲٱ� ������ ��������� Ǫ�� �ڵ��Դϴ�. ǥ����� �����ϴ� �ڷᱸ���δ� Ʈ���� ���˴ϴ�. 
// ���� ǥ������� �Ǿ� �ִ� ������ �ΰ��� �ɰ��� �յ� ǥ����� ���� ���� ǥ������� ��ȯ�� �� �ٽ� �̾���̴� �������� �����Դϴ�. 
#include <stdio.h>
#include <string.h>

#define OPERATORS "+-*/" // ���� ����

// Prototype Declarations
void preToPostFix(char* preFixIn, char* exprOut);
int findExprLen(char* exprIn);

int main(void)
{
	// Local Definitions
	char preFixExpr[256] = "-+*ABC/EF"; // prefix ǥ����
	char postFixExpr[256] = "";         // postfix�� ��ȯ�� ǥ������ ����� �� ���ڿ�

	// Statements
	printf("Begin prefix to postfix conversion\n\n");

	preToPostFix(preFixExpr, postFixExpr);
	printf("Prefix expr: %-s\n", preFixExpr);
	printf("Postfix expr: %-s\n", postFixExpr);

	printf("\nEnd prefix to postfix conversion\n");
	return 0;
}

/* �μ�1�� ���޹��� prefix ������ �μ�2�� ���޹��� postfix �������� ��ȯ */
void preToPostFix(char* preFixIn, char* postFix) // ��� ����
{
	// Local Definitions
	char operator[2];
	char postFix1[256]; // ù��° prefix ������ postfix �� ��ȯ�� ����
	char postFix2[256]; // �ι�° prefix ������ postfix �� ��ȯ�� ����
	char temp[256];
	int lenPreFix;      // ������ ����

	// Statements
	if (strlen(preFixIn) == 1) // preFixIn�� ���̰� 1�̴� == ���ڿ��� ���� ���� �ǿ������̴�
	{
		*postFix = *preFixIn;  // postfix �Ŀ� ����
		*(postFix + 1) = '\0'; // EOS
		return;
	} // if only operand

	*operator = *preFixIn; // �� �� ����(������) ����
	*(operator+1) = '\0';  // EOS

	// Find first expression
	lenPreFix = findExprLen(preFixIn + 1);
	strncpy(temp, preFixIn + 1, lenPreFix); // temp�� ù��° ���� ����
	*(temp + lenPreFix) = '\0';             // EOS
	preToPostFix(temp, postFix1);           // ù��° ���Ŀ� ���� �ٽ� ����

	// Find second expression
	strcpy(temp, preFixIn + 1 + lenPreFix); // temp�� �ι�° ���� ����
	preToPostFix(temp, postFix2);           // �ι�° ���Ŀ� ���� �ٽ� ����

	// Concatenate to postFix
	strcpy(postFix, postFix1); // postFix�� ù��° prefix ������ postfix�� ��ȯ�� ���� copy
	strcat(postFix, postFix2); // postFix�� �ι�° prefix ������ postfix�� ��ȯ�� ���� concatenate
	strcat(postFix, operator); // postFix�� �������� ������ concatenate

	return;
}
/* ���޹��� prefix ���Ŀ��� �� �տ��� ���� ���� ������ prefix ������ ���̸� ��ȯ */
int findExprLen(char* exprIn) // �μ�: prefix�� ǥ���� ����, ���ϰ�: ���� ��ġ���� ���� ���� ������ ���� ǥ����� ����
{
	// Local Definitions
	int len1; // ���� ǥ����� ���� ��ġ
	int len2; // ���� ǥ����� �� ��ġ

	// Statements
	if (strcspn(exprIn, OPERATORS) == 0) // ������ �� �� ���ڰ� '������'���,
		// General Case: First character is operator
		// Find length of first expression
	{
		len1 = findExprLen(exprIn + 1);        // ������ ���� ���� �˻�
		// Find length of second expression
		len2 = findExprLen(exprIn + 1 + len1); // len1 + 1 ��ġ�� ���� �˻�
	}
	else                                 // ������ �� �� ���ڰ� '�ǿ�����'���.
		// Base case: First char is operand
		len1 = len2 = 0;                       // ���� ǥ����� ���̰� 1(�ǿ����ڸ� ����)

	return len1 + len2 + 1;
}