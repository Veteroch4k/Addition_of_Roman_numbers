#include<stdio.h>
#include<math.h>
#include<windows.h>


//�-��, ����������� ������������ � �������������� �������� �� ������
void input_error() {
    printf("�� ��������� ������\n");

}


//�-��, �������������� ������������ ������� ������ 
void input_bug_catcher(char num[]) {

    int len_s = strlen(num); // ����������� ����� num
    int d_check = 1; // �������� ����� �� ���������� ���������� ����

    for (int i = 0; i < len_s; i++) {
        if (num[i] == 'M') {
            if (i == 9) {
                input_error();
                break;
            }
            if (num[i + 1] == 'M') continue;
            i++;
        }
        if (num[i] == 'D') {
            if (num[i + 1] == 'D') {
                input_error();
                break;
            }
            i++;
        }
        if (num[i] == 'C') {
            if (d_check > 4) {
                input_error();
                break;
            }
            if ((num[i + 1] == 'D' && num[i - 1] != 'D') || (num[i + 1] == 'M' && num[i - 1] != 'M')) i++;
            else if (num[i + 1] == '�') {
                d_check++;
                continue;
            }
            i++;
            d_check = 0; //�������� �������

        }
        if (num[i] == 'L') {
            if (num[i + 1] == 'L') {
                input_error();
                break;
            }
            i++;
        }
        if (num[i] == 'X') {
            if (d_check > 4) {
                input_error();
                break;
            }
            if ((num[i + 1] == 'L' && num[i - 1] != 'L') || (num[i + 1] == 'C' && num[i - 1] != 'C' && num[i - 1] != 'D')) i++;
            else if (num[i + 1] == 'X') {
                d_check++;
                continue;
            }
            i++;
            d_check = 0;

        }
        if (num[i] == 'V') {
            if (num[i + 1] == 'V') {
                input_error();
                break;
            }
            i++;
        }
        d_check = 0; //�������� �������
        if (num[i] == 'I') {
            if (d_check > 4) {
                input_error();
                break;
            }
            if ((num[i + 1] == 'V' && num[i - 1] != 'V') || (num[i + 1] == 'X' && num[i - 1] != 'X')) i++;
            else if (num[i + 1] == 'I') {
                d_check++;
                continue;
            }
            i++;
        } 
        if(i < len_s) {
            input_error();
        }
        break;
    }

}


//�-��, ����������� �������� ��������� ������������
void user_interface() {

    // ('\0')
    //MMMMMMMMMCMXCIX = 9999 ����� ������� � ����� ������� ��������� �����, MMMMMMMMMMMMMMMMMMMCMXCVIII = 19998 ����� ������� ��������� ����� 
    char firstRomanNumeral[16], secondRomanNumeral[16], sumOfRomanNumeral[28];

    printf("�������� ����� � ������� ������� ��������� \n������� ������ ������� �����: ");
    gets_s(firstRomanNumeral); //���� ������� �����
    input_bug_catcher(firstRomanNumeral); //�������� �� ������������ �������� ������

    printf("������� ������ ������� �����: ");
    gets_s(secondRomanNumeral); //���� ������� �����
    input_bug_catcher(secondRomanNumeral); //�������� �� ������������ �������� ������



    //printf("��������� ������������ � ������� ������� ���������: %d\n", sumOfRomanNumeral);
    //decimalToRoman(sum);

}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    user_interface();

    return 0;
}

/*TODO:
* 1) �������� �� ������������ ��������� ������
* 2) �� ������ �������� �� ��������, ������ �������� ����������� �������� ��������������� ����� ����� ��������� (X + X, I + I, M + M etc.)
* 3) �.� ���������� � 10-���� ������, �������� �������� �������, ����������� ������ IIII = IV ��� �������, ���� �� ������ II + II
* -4) ����� ��, � ��� ���� ��������� ������� ������, �� ������ ����� �� (0; 10K), ��������, ��� ������������� �� ����� �������
* -5) �.� ��� ���������, � �� �������, ����� �������� ������� ������, ����� ����������, ��� ����� ������ �� ���������� �������� - ����� ������ �������
* 6) ����� ��, ������������� ����� �� ������ ����, �.�. �����, ��� �������, -X + VI <=> VI - X =>> ��� ��� ���������, ��� �� ��� ������� � �������
* 7) ������� ����������� ���������, ���������� ������������, ��� �� ������� � ������ ������������ ������\
* 8) ��� 7 ������, ���� ���, ������������� ������� ����� �������, ��� �������� ������������ �����
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