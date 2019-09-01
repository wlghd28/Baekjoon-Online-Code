#include <stdio.h>
#include <string.h>
int check[10] = { 0,0,0,0,0,0,0,0,0,0 }; // �ڸ��� üũ�ϴ� �뵵
int K; // ��� �̷�������� ���ϴ� ����
char N[20]; // �ڿ����� �Է¹��� ���ڿ�
int Number[20]; // �Է¹��� �ڿ����� �ڸ������� ����.
void ArrayNumber(int len);  // �Էµ� �ڿ����� �迭�� �ִ� ����.
void Answer1(int len, int tmplen, int index); // Count > K�� ��츦 ã�� ��� ������ ����ϴ� �Լ�.
void Answer2(int len, int tmplen, int temp, int index); // Count < K�� ��츦 ã�� ��� ������ ����ϴ� �Լ�.
int ReturnNumber(int len); // ���� �ڿ����� ��� ���ڷ� �̷�������� ��ȯ.
void PrintAnswer(int len); // ���� ���.
int main(void)
{
	int len, tmplen, Count;
	scanf("%s %d", N, &K);
	len = strlen(N); // �ڿ����� ����
	tmplen = len - 1; // ������Ų �ڸ����� ������ �ڸ����� ����Ű�� �ε���
	ArrayNumber(len); // �ڿ����� �� �ڸ����� �����迭�� �ִ´�.
	Count = ReturnNumber(len);
	if (len < K) {
		// �Է¹��� �ڿ����� ���̺��� ���ϴ� ������ ������ ū ���.
		// ������ 10234...789 ���·� ���ü� �ۿ� ����.
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
	// �Է¹��� �ڿ����� �̷�� ������ ������ ���ϴ� �������� ���� ���.
	else if (Count > K) {
		int temp;
		while (tmplen >= 0) {
			while (Number[tmplen] < 10) {
				// �Ǵ� ��츦 ã�� �� ������ ����ϰ� ����.
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
	// �Է¹��� �ڿ����� �̷�� ������ ������ ���ϴ� �������� ���� ���.
	else if (Count < K) {
		// �ۼ��ؾ��� ��(������ �����)
		int index = 0, temp; // index = �߰� �Ǿ���ϴ� ������ ����
		while (tmplen >= 0) {
			while (Number[tmplen] < 10) {
				// �Ǵ� ��츦 ã�� �� ������ ����ϰ� ����.
				Number[tmplen]++;
				if (Number[tmplen] < 10) {
					temp = ReturnNumber(tmplen + 1); // ���� �ڸ������� �̷���� ������ ����
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
	// � ��쵵 ã�� ���� ��� 1000..234....789 ���·� ���ü� �ۿ� ����.
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
		// üũ �� �Ǿ��ִ� ������ ���� ���� �� ���Ѵ�.
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
		// üũ �Ǿ��ִ� ������ ���� ���� �� ���Ѵ�.
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
		// �ڸ��� ���ڰ� 9�� �� �ø��� �߻��ϴ� ���. �� �ڸ����� ������Ű�� �� �ڸ��� 0�� �ȴ�.
		for (int i = tmplen + 1; i < tmplen + 1 + (index - (K - temp)); i++) {
			Number[i] = 0;
		}
		// üũ���� ���� ���ڸ� ���� ������ �迭�� �ִ´�.
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
	//üũ�迭 �ʱ�ȭ.
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