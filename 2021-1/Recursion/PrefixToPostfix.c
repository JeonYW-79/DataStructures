/*
Convert prefix to postfix expression.
	Written by: wowo0709
	Date: 2021-03-11
*/
// 표기식 바꾸기 문제를 재귀적으로 푸는 코드입니다. 표기식을 저장하는 자료구조로는 트리가 사용됩니다. 
// 전위 표기식으로 되어 있는 수식을 두개로 쪼개어 앞뒤 표기식을 각각 후위 표기식으로 변환한 뒤 다시 이어붙이는 분할정복 문제입니다. 
#include <stdio.h>
#include <string.h>

#define OPERATORS "+-*/" // 연산 종류

// Prototype Declarations
void preToPostFix(char* preFixIn, char* exprOut);
int findExprLen(char* exprIn);

int main(void)
{
	// Local Definitions
	char preFixExpr[256] = "-+*ABC/EF"; // prefix 표현식
	char postFixExpr[256] = "";         // postfix로 변환된 표현식이 저장될 빈 문자열

	// Statements
	printf("Begin prefix to postfix conversion\n\n");

	preToPostFix(preFixExpr, postFixExpr);
	printf("Prefix expr: %-s\n", preFixExpr);
	printf("Postfix expr: %-s\n", postFixExpr);

	printf("\nEnd prefix to postfix conversion\n");
	return 0;
}

/* 인수1로 전달받은 prefix 수식을 인수2로 전달받은 postfix 수식으로 변환 */
void preToPostFix(char* preFixIn, char* postFix) // 재귀 구조
{
	// Local Definitions
	char operator[2];
	char postFix1[256]; // 첫번째 prefix 수식을 postfix 로 변환한 수식
	char postFix2[256]; // 두번째 prefix 수식을 postfix 로 변환한 수식
	char temp[256];
	int lenPreFix;      // 수식의 길이

	// Statements
	if (strlen(preFixIn) == 1) // preFixIn의 길이가 1이다 == 문자열에 남은 것이 피연산자이다
	{
		*postFix = *preFixIn;  // postfix 식에 저장
		*(postFix + 1) = '\0'; // EOS
		return;
	} // if only operand

	*operator = *preFixIn; // 맨 앞 문자(연산자) 저장
	*(operator+1) = '\0';  // EOS

	// Find first expression
	lenPreFix = findExprLen(preFixIn + 1);
	strncpy(temp, preFixIn + 1, lenPreFix); // temp에 첫번째 수식 저장
	*(temp + lenPreFix) = '\0';             // EOS
	preToPostFix(temp, postFix1);           // 첫번째 수식에 대해 다시 수행

	// Find second expression
	strcpy(temp, preFixIn + 1 + lenPreFix); // temp에 두번째 수식 저장
	preToPostFix(temp, postFix2);           // 두번째 수식에 대해 다시 수행

	// Concatenate to postFix
	strcpy(postFix, postFix1); // postFix에 첫번째 prefix 수식을 postfix로 변환한 수식 copy
	strcat(postFix, postFix2); // postFix에 두번째 prefix 수식을 postfix로 변환한 수식 concatenate
	strcat(postFix, operator); // postFix의 마지막에 연산자 concatenate

	return;
}
/* 전달받은 prefix 수식에서 맨 앞에서 가장 작은 단위의 prefix 수식의 길이를 반환 */
int findExprLen(char* exprIn) // 인수: prefix로 표현된 수식, 리턴값: 현재 위치에서 가장 작은 단위의 전위 표기식의 길이
{
	// Local Definitions
	int len1; // 전위 표기식의 시작 위치
	int len2; // 전위 표기식의 끝 위치

	// Statements
	if (strcspn(exprIn, OPERATORS) == 0) // 수식의 맨 앞 문자가 '연산자'라면,
		// General Case: First character is operator
		// Find length of first expression
	{
		len1 = findExprLen(exprIn + 1);        // 수식의 다음 문자 검사
		// Find length of second expression
		len2 = findExprLen(exprIn + 1 + len1); // len1 + 1 위치의 문자 검사
	}
	else                                 // 수식의 맨 앞 문자가 '피연산자'라면.
		// Base case: First char is operand
		len1 = len2 = 0;                       // 전위 표기식의 길이가 1(피연산자만 존재)

	return len1 + len2 + 1;
}