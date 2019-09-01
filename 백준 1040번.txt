#include <stdio.h>
#include <string.h>
int check[10] = { 0,0,0,0,0,0,0,0,0,0 }; // 자릿수 체크하는 용도
int K; // 몇개로 이루어졌는지 정하는 변수
char N[20]; // 자연수를 입력받을 문자열
int Number[20]; // 입력받은 자연수를 자릿수별로 저장.
void ArrayNumber(int len);  // 입력된 자연수를 배열로 넣는 역할.
void Answer1(int len, int tmplen, int index); // Count > K의 경우를 찾은 경우 정답을 출력하는 함수.
void Answer2(int len, int tmplen, int temp, int index); // Count < K의 경우를 찾은 경우 정답을 출력하는 함수.
int ReturnNumber(int len); // 현재 자연수가 몇개의 숫자로 이루어졌는지 반환.
void PrintAnswer(int len); // 정답 출력.
int main(void)
{
	int len, tmplen, Count;
	scanf("%s %d", N, &K);
	len = strlen(N); // 자연수의 길이
	tmplen = len - 1; // 고정시킨 자릿수를 제외한 자릿수를 가리키는 인덱스
	ArrayNumber(len); // 자연수의 각 자릿수를 정수배열에 넣는다.
	Count = ReturnNumber(len);
	if (len < K) {
		// 입력받은 자연수의 길이보다 원하는 숫자의 갯수가 큰 경우.
		// 무조건 10234...789 형태로 나올수 밖에 없다.
		int ex[10] = { 1,0,2,3,4,5,6,7,8,9 };
		for (int i = 0; i < K; i++) {
			printf("%d", ex[i]);
		}
		//printf("\n");
		return 0;
	}
	if (Count == K) {
		PrintAnswer(len);
		return 0;
	}
	// 입력받은 자연수를 이루는 숫자의 갯수가 원하는 갯수보다 많을 경우.
	else if (Count > K) {
		int temp;
		while (tmplen >= 0) {
			while (Number[tmplen] < 10) {
				// 되는 경우를 찾을 시 정답을 출력하고 종료.
				Number[tmplen]++;
				if (Number[tmplen] < 10) {
					temp = ReturnNumber(tmplen + 1);
					if (temp <= K) {
						Answer1(len, tmplen, K - temp);
						return 0;
					}
				}
			}
			tmplen--;
		}
	}
	// 입력받은 자연수를 이루는 숫자의 갯수가 원하는 갯수보다 적을 경우.
	else if (Count < K) {
		// 작성해야할 곳(문제가 생긴곳)
		int index = 0, temp; // index = 추가 되어야하는 숫자의 갯수
		while (tmplen >= 0) {
			while (Number[tmplen] < 10) {
				// 되는 경우를 찾을 시 정답을 출력하고 종료.
				Number[tmplen]++;
				if (Number[tmplen] < 10) {
					temp = ReturnNumber(tmplen + 1); // 현재 자릿수까지 이루어진 숫자의 갯수
					if (index >= K - temp) {
						Answer2(len, tmplen, temp, index);
						return 0;
					}
				}
			}
			tmplen--;
			index++;
		}
	}
	// 어떤 경우도 찾지 못한 경우 1000..234....789 형태로 나올수 밖에 없다.
	int tmp = 2;
	for (int i = 1; i < len - K + 2; i++) {
		Number[i] = 0;
	}
	for (int i = len - K + 2; i < len; i++) {
		Number[i] = tmp++;
	}
	PrintAnswer(len);
	return 0;
}
void Answer1(int len, int tmplen, int index)
{
	int min;
	if (index != 0) {
		// 체크 안 되어있는 숫자중 가장 작은 수 구한다.
		for (int i = 0; i < 10; i++) {
			if (check[i] == 0) {
				min = i;
				break;
			}
		}
		for (int i = tmplen + 1; i < len - 1; i++) {
			Number[i] = 0;
		}
		Number[len - 1] = min;
	}
	else {
		// 체크 되어있는 숫자중 가장 작은 수 구한다.
		for (int i = 0; i < 10; i++) {
			if (check[i] == 1) {
				min = i;
				break;
			}
		}
		for (int i = tmplen + 1; i < len; i++) {
			Number[i] = min;
		}
	}
	PrintAnswer(len);
}
void Answer2(int len, int tmplen, int temp, int index)
{
	if (temp == K) {
		int min;
		for (int i = 0; i < 10; i++) {
			if (check[i] == 1) {
				min = i;
				break;
			}
		}
		for (int i = tmplen + 1; i < len; i++) {
			Number[i] = min;
		}
	}
	else {
		// 자리의 숫자가 9일 때 올림이 발생하는 경우. 전 자릿수를 증가시키고 그 자리는 0이 된다.
		for (int i = tmplen + 1; i < tmplen + 1 + (index - (K - temp)); i++) {
			Number[i] = 0;
		}
		// 체크되지 않은 숫자를 작은 수부터 배열에 넣는다.
		for (int i = tmplen + 1 + (index - (K - temp)); i < len; i++) {
			for (int j = 0; j < 10; j++) {
				if (check[j] == 0) {
					Number[i] = j;
					check[j] = 1;
					break;
				}
			}
		}
	}
	PrintAnswer(len);
}
int ReturnNumber(int len)
{
	int count = 0;
	//체크배열 초기화.
	for (int i = 0; i < 10; i++) {
		check[i] = 0;
	}
	for (int i = 0; i < len; i++) {
		check[Number[i]] = 1;
	}
	for (int i = 0; i < 10; i++) {
		if (check[i] == 1)
			count++;
	}
	return count;
}
void ArrayNumber(int len)
{
	for (int i = 0; i < len; i++) {
		Number[i] = N[i] - '0';
	}
}
void PrintAnswer(int len)
{
	for (int i = 0; i < len; i++) {
		printf("%d", Number[i]);
	}
	//printf("\n");
}