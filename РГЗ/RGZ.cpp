#include<stdio.h>
#include<math.h>
#include<windows.h>

// основная функция программы
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

//ф-ия, обрабатывающая некорректные входные данные 
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
			if (((num[i + 1] == 'V' && num[i - 1] != 'V') || (num[i + 1] == 'X' && num[i - 1] != 'X')) && num[i - 1] != 'I') i++;
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

//ф-ия, реализующая основной интерфейс пользователя
void user_interface() {

	char firstRomanNumeral[16], secondRomanNumeral[16], sumOfRomanNumeral[28];
	bool flag = false; //корректно ли введено число
	bool range = false; // не превышает ли число допустимый диапазон

	// Ввод и проверка первого числа
	do {
		printf("Введите первое римское число : ");
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

	plus_num(firstRomanNumeral, secondRomanNumeral, sumOfRomanNumeral);

	printf("Результат суммирования в римской системе счисления: %s\n", sumOfRomanNumeral);
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Сложение двух натуральных чисел в римской системе счисления\n");
	printf("Вводите числа, входящие в диапазон от 0 до 10тыс.\n");

	user_interface();

	return 0;
}

/*TODO:
* -1) Проверка на правильность введенных данных
* 2) Мы должны работать со строками, значит придется реализовать сложение соответствующих между собой элементов (X + X, I + I, M + M etc.)
* 3) Т.к переводить в 10-чную нельзя, придется написать функцию, переводящую всякие IIII = IV для примера, если мы сложим II + II
* -4) Опять же, у нас нету диапазона входных данных, но скорее всего от (0; 10K), надеемся, что отрицательные не нужны СДЕЛАНО
* -5) Т.к Лау пидараска, и не указала, какой диапазон входных данных, может получиться, что сумма выйдет за допустимый диапазон - опять траблы СДЕЛАНО
* -6) Опять же, отрицательные числа не должны быть, т.к. тогда, для примера, -X + VI <=> VI - X =>> Что уже вычитание, что не наш профиль и вариант
* -7) Придётся реализовать интерфейс, намекающий пользователю, что он долбоеб и вводит неккоректные данные\
* -8) Для 7 пункта, пока что, необязательно наличие самой функции, для проверки правильности ввода
* 9) Так как, что кстати, очевидно, функций будет немного, так и их функционал будет занимать не мало места(эхх, щас бы классы), то придется разбивать их функционал на отдельные методы
* 10) Насчёт блок-схем: тут всё +- понятно, накидываем код и после всего этого гейства только блок-схемы
* 11) Тестовые данные - это первое, что мы должны сделать, чтоб потом проверять работу кода и подгонять его под ТД
* 12) Связанность модулей и их сцепления последнее, что должно нас волновать
* 13) В анализе результатов надо наныть, что большую часть времени заняла разработка блок-схем.
* 14) Ебучие фигурные скобки должны быть на некст строке
* 15) Всё, что в 1 строчку записывается без фигурных скобок
* 16) Про пидорство с '\0' в конце строки не забываем
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