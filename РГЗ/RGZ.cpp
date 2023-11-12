#include<stdio.h>
#include<math.h>
#include<windows.h>

// �������� ������� ���������
void plus_num(char num1[], char num2[], char sum[]) {
	int len1 = strlen(num1), len2 = strlen(num2);
	int k = len1 + len2;
	int s = 0, j = 0, i = 0;

	while (num1[i] == 'M' || num2[j] == 'M') {
		sum[s] = 'M';
		if (num1[i] == num2[j]) {
			s++;
			sum[s] = 'M';
			i++;
			j++;
		}
		else if (num1[i] == 'M') i++;
		else j++;
		s++;
	}

	while (num1[i] == 'C' || num2[j] == 'C') {
		sum[s] = 'C';
		if (num1[i] == num2[j]) {
			s++;
			sum[s] = 'C';
			i++;
			j++;
		}
		else if (num1[i] == 'C') i++;
		else j++;
		s++;
	}

	while (num1[i] == 'X' || num2[j] == 'X') {
		sum[s] = 'X';
		if (num1[i] == num2[j]) {
			s++;
			sum[s] = 'X';
			i++;
			j++;
		}
		else if (num1[i] == 'X') i++;
		else j++;
		s++;
	}

	while (num1[i] == 'I' || num2[j] == 'I') {
		sum[s] = 'I';
		if (num1[i] == num2[j]) {
			s++;
			sum[s] = 'I';
			i++;
			j++;
		}
		else if (num1[i] == 'I') i++;
		else j++;
		s++;
	}
	sum[len1 + len2] = '\0';
}

//�-��, �������������� ������������ ������� ������ 
void input_bug_catcher(char num[], bool* flag, bool* range) {

	int len_s = strlen(num); // ����������� ����� num
	int d_check = 1; // �������� ����� �� ���������� ���������� ����

	for (int i = 0; i < len_s; i++) {
		if (num[i] == 'M') {
			if (i == 9) {
				*range = true;
				break;
			}
			if (num[i + 1] == 'M') continue;
			i++;
		}
		if (num[i] == 'D') {
			if (num[i + 1] == 'D') break; //��� ����� ����� �������������� � ����� ������ 1 ���
			i++;
		}
		if (num[i] == 'C') {
			if (d_check > 3) break;
			if (((num[i + 1] == 'D' && num[i - 1] != 'D') || (num[i + 1] == 'M')) && num[i - 1] != 'C') i++;
			else if (num[i + 1] == 'C') {
				d_check++;
				continue;
			}
			i++;
			d_check = 1; //���������� �������

		}
		if (num[i] == 'L') {
			if (num[i + 1] == 'L') break; //��� ����� ����� �������������� � ����� ������ 1 ���
			i++;
		}
		if (num[i] == 'X') {
			if (d_check > 3) break;
			if (((num[i + 1] == 'L' && num[i - 1] != 'L') || (num[i + 1] == 'C')) && num[i - 1] != 'X') i++;
			else if (num[i + 1] == 'X') {
				d_check++;
				continue;
			}
			i++;
			d_check = 1; //���������� �������

		}
		if (num[i] == 'V') {
			if (num[i + 1] == 'V') break; //��� ����� ����� �������������� � ����� ������ 1 ���
			i++;
		}
		if (num[i] == 'I') {
			if (d_check > 3) break;
			if (((num[i + 1] == 'V' && num[i - 1] != 'V') || (num[i + 1] == 'X' && num[i - 1] != 'X')) && num[i - 1] != 'I') i++;
			else if (num[i + 1] == 'I') {
				d_check++;
				continue;
			}
			i++;
		}
		if (i < len_s) break;
		*flag = false; // ������ � ����� �� ����������
		return;
	}
	*flag = true; //�������� ������ � �����

}

//�-��, ����������� �������� ��������� ������������
void user_interface() {

	char firstRomanNumeral[16], secondRomanNumeral[16], sumOfRomanNumeral[28];
	bool flag = false; //��������� �� ������� �����
	bool range = false; // �� ��������� �� ����� ���������� ��������

	// ���� � �������� ������� �����
	do {
		printf("������� ������ ������� ����� : ");
		gets_s(firstRomanNumeral);
		input_bug_catcher(firstRomanNumeral, &flag, &range);

		if (range) printf("�� ����� �����, ��������� �� ���������� ��������. ������� ����� ������.\n");
		else if (flag) printf("�� ����� ������������ �����. ������� ����� ������.\n");

	} while (flag);

	// ���� � �������� ������� �����
	do {
		printf("������� ������ ������� �����: ");
		gets_s(secondRomanNumeral);
		input_bug_catcher(secondRomanNumeral, &flag, &range);

		if (range) printf("�� ����� �����, ��������� �� ���������� ��������. ������� ����� ������.\n");
		else if (flag) printf("�� ����� ������������ �����. ������� ����� ������.\n");

	} while (flag);

	plus_num(firstRomanNumeral, secondRomanNumeral, sumOfRomanNumeral);

	printf("��������� ������������ � ������� ������� ���������: %s\n", sumOfRomanNumeral);
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("�������� ���� ����������� ����� � ������� ������� ���������\n");
	printf("������� �����, �������� � �������� �� 0 �� 10���.\n");

	user_interface();

	return 0;
}

/*TODO:
* -1) �������� �� ������������ ��������� ������
* 2) �� ������ �������� �� ��������, ������ �������� ����������� �������� ��������������� ����� ����� ��������� (X + X, I + I, M + M etc.)
* 3) �.� ���������� � 10-���� ������, �������� �������� �������, ����������� ������ IIII = IV ��� �������, ���� �� ������ II + II
* -4) ����� ��, � ��� ���� ��������� ������� ������, �� ������ ����� �� (0; 10K), ��������, ��� ������������� �� ����� �������
* -5) �.� ��� ���������, � �� �������, ����� �������� ������� ������, ����� ����������, ��� ����� ������ �� ���������� �������� - ����� ������ �������
* -6) ����� ��, ������������� ����� �� ������ ����, �.�. �����, ��� �������, -X + VI <=> VI - X =>> ��� ��� ���������, ��� �� ��� ������� � �������
* -7) ������� ����������� ���������, ���������� ������������, ��� �� ������� � ������ ������������ ������\
* -8) ��� 7 ������, ���� ���, ������������� ������� ����� �������, ��� �������� ������������ �����
* 9) ��� ���, ��� ������, ��������, ������� ����� �������, ��� � �� ���������� ����� �������� �� ���� �����(���, ��� �� ������), �� �������� ��������� �� ���������� �� ��������� ������
* 10) ������ ����-����: ��� �� +- �������, ���������� ��� � ����� ����� ����� ������� ������ ����-�����
* 11) �������� ������ - ��� ������, ��� �� ������ �������, ���� ����� ��������� ������ ���� � ��������� ��� ��� ��
* 12) ����������� ������� � �� ��������� ���������, ��� ������ ��� ���������
* 13) � ������� ����������� ���� ������, ��� ������� ����� ������� ������ ���������� ����-����.
* 14) ������ �������� ������ ������ ���� �� ����� ������
* 15) ��, ��� � 1 ������� ������������ ��� �������� ������
* 16) ��� ��������� � '\0' � ����� ������ �� ��������
*/

/*int valueOfRomanDigit(char digit) {
	switch(digit) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
	}
}

int romanToDecimal(char* romanNumeral) {
	int decimal = 0;
	int i;

	for(i = 0; romanNumeral[i] != '\0'; i++) {
		if(valueOfRomanDigit(romanNumeral[i]) < valueOfRomanDigit(romanNumeral[i+1])) {
			decimal -= valueOfRomanDigit(romanNumeral[i]);
		} else {
			decimal += valueOfRomanDigit(romanNumeral[i]);
		}
	}

	return decimal;
}

void decimalToRoman(int number) {



	int decimalValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	//char* romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

	char romanNumeral[20];
	romanNumeral[0] = '\0';

	int i;

	for(i = 0; i < 13; i++) {
		while(number >= decimalValues[i]) {
			//strcat(romanNumeral, romanSymbols[i]);
			number -= decimalValues[i];
		}
	}

	printf("Result in Roman numerals: %s\n", romanNumeral);
}*/