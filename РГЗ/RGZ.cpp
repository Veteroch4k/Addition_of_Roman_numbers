#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<windows.h>


// Сложение двух римских чисел
void plus_num(char num1[], char num2[], char sum[]) {
	int j = 0, i = 0;
	_strrev(num1);
	_strrev(num2);
	int c = 0, count1 = 0, count2 = 0;
	/*Это десяточки*/
	/**/
	if (strstr(num1, "XI") != NULL) { 
		if (strstr(num2, "XI") != NULL) strcat(sum, "IIIVX");
		else if (strstr(num2, "IIIV") != NULL) strcat(sum, "IIVX");
		else if (strstr(num2, "IIV") != NULL) strcat(sum, "IVX");
		else if (strstr(num2, "VI") != NULL) strcat(sum, "IIIX");
		else if (strstr(num2, "IV") != NULL) strcat(sum, "VX");
		else if (strstr(num2, "V") != NULL) strcat(sum, "VIX");
		else if (strstr(num2, "III") != NULL) strcat(sum, "IIX");
		else if (strstr(num2, "II") != NULL) strcat(sum, "IX");
		else if (strstr(num2, "I") != NULL) strcat(sum, "X");
		
	} else if (strstr(num2, "XI") != NULL) {
		if (strstr(num1, "XI") != NULL) strcat(sum, "IIIVX");
		else if (strstr(num1, "IIIV") != NULL) strcat(sum, "IIVX");
		else if (strstr(num1, "IIV") != NULL) strcat(sum, "IVX");
		else if (strstr(num1, "VI") != NULL) strcat(sum, "IIIX");
		else if (strstr(num1, "IV") != NULL) strcat(sum, "VX");
		else if (strstr(num1, "V") != NULL) strcat(sum, "VIX");
		else if (strstr(num1, "III") != NULL) strcat(sum, "IIX");
		else if (strstr(num1, "II") != NULL) strcat(sum, "IX");
		else if (strstr(num1, "I") != NULL) strcat(sum, "X");

	}
	/**/
	else if (strstr(num1, "VI") != NULL) {
		if (strstr(num2, "XI") != NULL) strcat(sum, "IIIX");
		else if (strstr(num2, "IIIV") != NULL) strcat(sum, "IIX");
		else if (strstr(num2, "IIV") != NULL) strcat(sum, "IX");
		else if (strstr(num2, "IV") != NULL) strcat(sum, "X");
		else if (strstr(num2, "VI") != NULL) strcat(sum, "IIIV");
		else if (strstr(num2, "V") != NULL) strcat(sum, "XI");
		else if (strstr(num2, "III") != NULL) strcat(sum, "IIV");
		else if (strstr(num2, "II") != NULL) strcat(sum, "IV");
		else if (strstr(num2, "I") != NULL) strcat(sum, "V");

		
	} else if (strstr(num2, "VI") != NULL) {
		if (strstr(num1, "XI") != NULL) strcat(sum, "IIIX");
		else if (strstr(num1, "IIIV") != NULL) strcat(sum, "IIX");
		else if (strstr(num1, "IIV") != NULL) strcat(sum, "IX");
		else if (strstr(num1, "IV") != NULL) strcat(sum, "X");
		else if (strstr(num1, "VI") != NULL) strcat(sum, "IIIV");
		else if (strstr(num1, "V") != NULL) strcat(sum, "XI");
		else if (strstr(num1, "III") != NULL) strcat(sum, "IIV");
		else if (strstr(num1, "II") != NULL) strcat(sum, "IV");
		else if (strstr(num1, "I") != NULL) strcat(sum, "V");


	}
	/**/
	else {
		if (strstr(num1, "V") != NULL) {
			if (strstr(num2, "V") != NULL) strcat(sum, "X");
		}
		else if (strstr(num2, "V") != NULL) {
			if (strstr(num1, "V") != NULL) strcat(sum, "X");
		}
		/**/
		if (strstr(num1, "I") != NULL || strstr(num2, "I") != NULL) {
			for (int i = 0; num1[i] == 'I'; i++) count1++;
			for (int i = 0; num2[i] == 'I'; i++) count2++;
			c = count1 + count2;
			if (c == 6) strcat(sum, "VI");
			if (c == 5) strcat(sum, "V");
			if (c == 4) strcat(sum, "IV");
			if (c == 3) strcat(sum, "III");
			if (c == 2) strcat(sum, "II");
			if (c == 1) strcat(sum, "I");

			_strrev(sum); 

		}
	}
	/*Теперь до сотен*/
	count1 = 0;
	count2 = 0;
	c = 0;

	if (strstr(num1, "CX") != NULL) {
		if (strstr(num2, "CX") != NULL) strcat(sum, "XXXLC");
		else if (strstr(num2, "XXXL") != NULL) strcat(sum, "XXLC");
		else if (strstr(num2, "XXL") != NULL) strcat(sum, "XLC");
		else if (strstr(num2, "LX") != NULL) strcat(sum, "XXXC");
		else if (strstr(num2, "XL") != NULL) strcat(sum, "LC");
		else if (strstr(num2, "L") != NULL) strcat(sum, "LXC");
		else if (strstr(num2, "XXX") != NULL) strcat(sum, "XXC");
		else if (strstr(num2, "XX") != NULL) strcat(sum, "XC");
		else if (strstr(num2, "X") != NULL) strcat(sum, "C");

	}
	else if (strstr(num2, "CX") != NULL) {
		if (strstr(num1, "CX") != NULL) strcat(sum, "XXXLC");
		else if (strstr(num1, "XXXL") != NULL) strcat(sum, "XXLC");
		else if (strstr(num1, "XXL") != NULL) strcat(sum, "XLC");
		else if (strstr(num1, "LX") != NULL) strcat(sum, "XXXC");
		else if (strstr(num1, "XL") != NULL) strcat(sum, "LC");
		else if (strstr(num1, "L") != NULL) strcat(sum, "LXC");
		else if (strstr(num1, "XXX") != NULL) strcat(sum, "XXC");
		else if (strstr(num1, "XX") != NULL) strcat(sum, "XC");
		else if (strstr(num1, "X") != NULL) strcat(sum, "C");

	}
	/**/
	else if (strstr(num1, "LX") != NULL) {
		if (strstr(num2, "CX") != NULL) strcat(sum, "XXXC");
		else if (strstr(num2, "XXXL") != NULL) strcat(sum, "XXC");
		else if (strstr(num2, "XXL") != NULL) strcat(sum, "XC");
		else if (strstr(num2, "XL") != NULL) strcat(sum, "C");
		else if (strstr(num2, "LX") != NULL) strcat(sum, "XXXL");
		else if (strstr(num2, "L") != NULL) strcat(sum, "CX");
		else if (strstr(num2, "XXX") != NULL) strcat(sum, "XXL");
		else if (strstr(num2, "XX") != NULL) strcat(sum, "XL");
		else if (strstr(num2, "X") != NULL) strcat(sum, "L");


	}
	else if (strstr(num2, "LX") != NULL) {
		if (strstr(num1, "CX") != NULL) strcat(sum, "XXXC");
		else if (strstr(num1, "XXXL") != NULL) strcat(sum, "XXC");
		else if (strstr(num1, "XXL") != NULL) strcat(sum, "XC");
		else if (strstr(num1, "XL") != NULL) strcat(sum, "C");
		else if (strstr(num1, "LX") != NULL) strcat(sum, "XXXL");
		else if (strstr(num1, "L") != NULL) strcat(sum, "CX");
		else if (strstr(num1, "XXX") != NULL) strcat(sum, "XXL");
		else if (strstr(num1, "XX") != NULL) strcat(sum, "XL");
		else if (strstr(num1, "X") != NULL) strcat(sum, "L");
	}
	/**/
	else {
		if (strstr(num1, "L") != NULL) {
			if (strstr(num2, "L") != NULL) strcat(sum, "C");
		}
		else if (strstr(num2, "L") != NULL) {
			if (strstr(num1, "L") != NULL) strcat(sum, "C");
		}
		/**/
		if (strstr(num1, "X") != NULL || strstr(num2, "X") != NULL) {
			char podItog[3]{}; // Считаем отдельно

			// вернули обратно для подсчёта
			_strrev(num1); 
			_strrev(num2);
			/**/

			for (int i = strstr(num1, "X") - num1; num1[i] == 'X'; i++) count1++;
			for (int i = strstr(num2, "X") - num2; num2[i] == 'X'; i++) count2++;

			int c = count1 + count2;
			if (strstr(sum, "X") != NULL) {
				sum[strlen(sum) - 1] = '\0';
				c++;
			}

			if (c == 6) strcat(podItog, "LX");
			if (c == 5) strcat(podItog, "L");
			if (c == 4) strcat(podItog, "XL");
			if (c == 3) strcat(podItog, "XXX");
			if (c == 2) strcat(podItog, "XX");
			if (c == 1) strcat(podItog, "X");

			_strrev(podItog); 
			strcat(sum, podItog);

			// вернули обратно для подсчёта
			_strrev(num1);
			_strrev(num2);
			/**/

		}
	}
	/*Теперь до тысяч*/
	count1 = 0;
	count2 = 0;
	c = 0;

	if (strstr(num1, "MC") != NULL) {
		if (strstr(num2, "MC") != NULL) strcat(sum, "CCCDM");
		else if (strstr(num2, "CCCD") != NULL) strcat(sum, "CCDM");
		else if (strstr(num2, "CCD") != NULL) strcat(sum, "CDM");
		else if (strstr(num2, "DC") != NULL) strcat(sum, "CCCM");
		else if (strstr(num2, "CD") != NULL) strcat(sum, "DM");
		else if (strstr(num2, "D") != NULL) strcat(sum, "DCM");
		else if (strstr(num2, "CCC") != NULL) strcat(sum, "CCM");
		else if (strstr(num2, "CC") != NULL) strcat(sum, "CM");
		else if (strstr(num2, "C") != NULL) strcat(sum, "M");

	}
	else if (strstr(num2, "MC") != NULL) {
		if (strstr(num1, "MC") != NULL) strcat(sum, "CCCDM");
		else if (strstr(num1, "CCCD") != NULL) strcat(sum, "CCDM");
		else if (strstr(num1, "CCD") != NULL) strcat(sum, "CDM");
		else if (strstr(num1, "DC") != NULL) strcat(sum, "CCCM");
		else if (strstr(num1, "CD") != NULL) strcat(sum, "DM");
		else if (strstr(num1, "D") != NULL) strcat(sum, "DCM");
		else if (strstr(num1, "CCC") != NULL) strcat(sum, "CCM");
		else if (strstr(num1, "CC") != NULL) strcat(sum, "CM");
		else if (strstr(num1, "C") != NULL) strcat(sum, "M");

	}
	/**/
	else if (strstr(num1, "DC") != NULL) {
		if (strstr(num2, "MC") != NULL) strcat(sum, "CCCM");
		else if (strstr(num2, "CCCD") != NULL) strcat(sum, "CCM");
		else if (strstr(num2, "CCD") != NULL) strcat(sum, "CM");
		else if (strstr(num2, "CD") != NULL) strcat(sum, "M");
		else if (strstr(num2, "DC") != NULL) strcat(sum, "CCCD");
		else if (strstr(num2, "D") != NULL) strcat(sum, "MC");
		else if (strstr(num2, "CCC") != NULL) strcat(sum, "CCD");
		else if (strstr(num2, "CC") != NULL) strcat(sum, "CD");
		else if (strstr(num2, "C") != NULL) strcat(sum, "D");


	}
	else if (strstr(num2, "DC") != NULL) {
		if (strstr(num1, "MC") != NULL) strcat(sum, "CCCM");
		else if (strstr(num1, "CCCD") != NULL) strcat(sum, "CCM");
		else if (strstr(num1, "CCD") != NULL) strcat(sum, "CM");
		else if (strstr(num1, "CD") != NULL) strcat(sum, "M");
		else if (strstr(num1, "DC") != NULL) strcat(sum, "CCCD");
		else if (strstr(num1, "D") != NULL) strcat(sum, "MC");
		else if (strstr(num1, "CCC") != NULL) strcat(sum, "CCD");
		else if (strstr(num1, "CC") != NULL) strcat(sum, "CD");
		else if (strstr(num1, "C") != NULL) strcat(sum, "D");


	}
	/**/
	else {
		if (strstr(num1, "D") != NULL) {
			if (strstr(num2, "D") != NULL) strcat(sum, "M");
		}
		else if (strstr(num2, "D") != NULL) {
			if (strstr(num1, "D") != NULL) strcat(sum, "M");
		}
		/**/
		if (strstr(num1, "C") != NULL || strstr(num2, "C") != NULL) {
			char podItog[3]{}; // Считаем отдельно


			// вернули обратно для подсчёта
			_strrev(num1);
			_strrev(num2);
			/**/

			for (int i = strstr(num1, "C") - num1; num1[i] == 'C'; i++) count1++;
			for (int i = strstr(num2, "C") - num2; num2[i] == 'C'; i++) count2++;

			int c = count1 + count2;
			if (strstr(sum, "C") != NULL) {
				sum[strlen(sum) - 1] = '\0';
				c++;
			}

			if (c == 6) strcat(sum, "DC");
			if (c == 5) strcat(sum, "D");
			if (c == 4) strcat(sum, "CD");
			if (c == 3) strcat(sum, "CCC");
			if (c == 2) strcat(sum, "CC");
			if (c == 1) strcat(sum, "C");

			_strrev(podItog);
			strcat(sum, podItog);

		}
	}

	/*Более тысячи*/
	count1 = 0;
	count1 = 0;
	c = 0;
	if (strstr(num1, "M") != NULL || strstr(num2, "M") != NULL) {

		for (int i = 0; num1[i] == 'M'; i++) count1++;
		for (int i = 0; num2[i] == 'M'; i++) count2++;
		c = count1 + count2;
		if (c == 3) strcat(sum, "MMM");
		if (c == 2) strcat(sum, "MM");
		if (c == 1) strcat(sum, "M");

	}

	_strrev(sum);
	printf("%s", sum);

}

// Обработка некорректно введённого числа пользователем
void input_bug_catcher(char num[], bool* flag, bool* range) {

	int len_s = strlen(num); // разрядность числа num
	int d_check = 1; // проверка числа на допустимое количество цифр

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
			if (num[i + 1] == 'D') break; //это цифра может использоваться в числе только 1 раз
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
			d_check = 1; //сбрасываем счетчик

		}
		if (num[i] == 'L') {
			if (num[i + 1] == 'L') break; //это цифра может использоваться в числе только 1 раз
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
			d_check = 1; //сбрасываем счетчик

		}
		if (num[i] == 'V') {
			if (num[i + 1] == 'V') break; //это цифра может использоваться в числе только 1 раз
			i++;
		}
		if (num[i] == 'I') {
			if (d_check > 3) break;
			if ((num[i + 1] == 'V' && num[i - 1] != 'V') || (num[i + 1] == 'X') && num[i - 1] != 'I') i++;
			else if (num[i + 1] == 'I') {
				d_check++;
				continue;
			}
			i++;
		}
		if (i < len_s) break;
		*flag = false; // Ошибок в вводе не обнаружено
		return;
	}
	*flag = true; //Допущены ошибки в вводе

}

// Основной интерфейс пользователя
void user_interface() {

	char firstRomanNumeral[16], secondRomanNumeral[16], sumOfRomanNumeral[28]{};
	bool flag = false; //корректно ли введено число
	bool range = false; // не превышает ли число допустимый диапазон

	// Ввод и проверка первого числа
	do {
		printf("Введите первое римское число: ");
		gets_s(firstRomanNumeral);
		input_bug_catcher(firstRomanNumeral, &flag, &range);

		if (range) printf("Вы ввели число, выходящее за допустимый диапазон. Введите число заново.\n");
		else if (flag) printf("Вы ввели некорректное число. Введите число заново.\n");

	} while (flag);

	// Ввод и проверка второго числа
	do {
		printf("Введите второе римское число: ");
		gets_s(secondRomanNumeral);
		input_bug_catcher(secondRomanNumeral, &flag, &range);

		if (range) printf("Вы ввели число, выходящее за допустимый диапазон. Введите число заново.\n");
		else if (flag) printf("Вы ввели некорректное число. Введите число заново.\n");

	} while (flag);
	printf("Результат суммирования в римской системе счисления: ");
	plus_num(firstRomanNumeral, secondRomanNumeral, sumOfRomanNumeral);

}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Сложение двух натуральных чисел в римской системе счисления\n");
	printf("Вводите числа, входящие в диапазон от 0 до 10мил.\n");

	user_interface();

	return 0;
}