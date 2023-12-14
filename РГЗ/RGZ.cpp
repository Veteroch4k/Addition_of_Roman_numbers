#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<locale.h>
#define N 33

// исправление неккоректного римского числа
char* fix_invalid_roman(char sum[], bool* flag_skobk) {
	
	int  len1 = strlen(sum);
	char itog[228]{};
	char poditog[228]{};

	int i = 0, j = 0;
	
	_strrev(sum);
	/*Работаем с перевернутыми строками*/


	if (sum[0] == '(' || (sum[0] == 'M' && sum[1] != 'C')) {
		i = 1;
		if (*flag_skobk) {
			poditog[j] = 'I';
			j = 1;
		}
	}

	for (; i <= len1; i++) {
		if (sum[i] == 'I' || sum[i] == 'V' || (sum[i] == 'X' && sum[i + 1] == 'I')) {
			poditog[j] = sum[i];
			j++;
		}
		else {
			if (strcmp(poditog, "VIIV") == 0 || strcmp(poditog, "IVIV") == 0) strcat(itog, "X");
			else if (strcmp(poditog, "VIV") == 0) strcat(itog, "XI");
			else if (strcmp(poditog, "VIVI") == 0) strcat(itog, "IIIV");
			else if (strcmp(poditog, "XIXI") == 0) strcat(itog, "IIIVX");
			else if (strcmp(poditog, "XIV") == 0) strcat(itog, "VIX"); 
			else if (strcmp(poditog, "XIVI") == 0 || strcmp(poditog, "VIXI") == 0) strcat(itog, "IIIX");
			else if (strcmp(poditog, "IIIIIIV") == 0) strcat(itog, "IX");
			else if (strcmp(poditog, "IIIIIV") == 0) strcat(itog, "X");
			else if (strcmp(poditog, "IIIIV") == 0) strcat(itog, "XI");
			else if (strcmp(poditog, "IIIIIII") == 0) strcat(itog, "IIV");
			else if (strcmp(poditog, "IIIIII") == 0) strcat(itog, "IV");
			else if (strcmp(poditog, "IIIII") == 0) strcat(itog, "V");
			else if (strcmp(poditog, "IIII") == 0) strcat(itog, "VI");
			/**/
			else if (strcmp(poditog, "IIVII") == 0 || strcmp(poditog, "IIIVI") == 0) strcat(itog, "IIV");
			else if (strcmp(poditog, "IVII") == 0 || strcmp(poditog, "IIVI") == 0) strcat(itog, "IV");
			else if (strcmp(poditog, "IVI") == 0 || strcmp(poditog, "VII") == 0) strcat(itog, "V");
			/*    */
			else if (strcmp(poditog, "IIIVIV") == 0 || strcmp(poditog, "IIVIIV") == 0) strcat(itog, "IIX");
			else if (strcmp(poditog, "IIVIV") == 0 || strcmp(poditog, "IVIIV") == 0) strcat(itog, "IX");
			/*    */
			else if (strcmp(poditog, "IIXII") == 0 || strcmp(poditog, "IIIXI") == 0) strcat(itog, "IIX");
			else if (strcmp(poditog, "IXII") == 0 || strcmp(poditog, "IIXI") == 0) strcat(itog, "IX");
			else if (strcmp(poditog, "IXI") == 0 || strcmp(poditog, "XII") == 0) strcat(itog, "X");
			/**/
			else if (strcmp(poditog, "IXIV") == 0 || strcmp(poditog, "XIIV") == 0) strcat(itog, "VX");
			else if (strcmp(poditog, "IIXIV") == 0 || strcmp(poditog, "IXIIV") == 0) strcat(itog, "IVX");
			else if (strcmp(poditog, "IIIXIV") == 0 || strcmp(poditog, "IIXIIV") == 0) strcat(itog, "IIVX");
			else strcat(itog, poditog);
			break;

		}
	}
	/*до сотен*/
	memset(poditog, 0, strlen(poditog));
	bool flag = false;
	if (itog[strlen(itog) - 1] == 'X' && i != len1) {
		itog[strlen(itog) - 1] = '\0';
		flag = true;
	}

	j = 0;

	for(; i <= len1; i ++) {

		if (sum[i] == 'X' || sum[i] == 'L' || (sum[i] == 'C' && sum[i + 1] == 'X')) {
			poditog[j] = sum[i];
			j++;
		}
		else {
			if (!flag) {
				if (strcmp(poditog, "LXXL") == 0 || strcmp(poditog, "XLXL") == 0) strcat(itog, "C");
				else if (strcmp(poditog, "LXL") == 0) strcat(itog, "CX");
				else if (strcmp(poditog, "LXLX") == 0) strcat(itog, "XXXL");
				else if (strcmp(poditog, "XCXCX") == 0) strcat(itog, "CXC");//CCXCX //XLXLX
				else if (strcmp(poditog, "XLXLX") == 0) strcat(itog, "CX");//CCXCX //XLXLX
				/**/
				else if (strcmp(poditog, "CXCX") == 0) strcat(itog, "XXXLC");
				else if (strcmp(poditog, "CXL") == 0) strcat(itog, "LXC");
				else if (strcmp(poditog, "CXLX") == 0 || strcmp(poditog, "LXCX") == 0) strcat(itog, "XXXC");
				else if (strcmp(poditog, "XXXXXXL") == 0) strcat(itog, "XC");
				else if (strcmp(poditog, "XXXXXL") == 0) strcat(itog, "C");
				else if (strcmp(poditog, "XXXXL") == 0) strcat(itog, "CX");
				else if (strcmp(poditog, "XXXXXX") == 0) strcat(itog, "XL");
				else if (strcmp(poditog, "XXXXX") == 0) strcat(itog, "L");
				else if (strcmp(poditog, "XXXX") == 0) strcat(itog, "LX");
				/**/
				else if (strcmp(poditog, "XXLXX") == 0 || strcmp(poditog, "XXXLX") == 0) strcat(itog, "XXL");
				else if (strcmp(poditog, "XLXX") == 0 || strcmp(poditog, "XXLX") == 0) strcat(itog, "XL");
				else if (strcmp(poditog, "XLX") == 0 || strcmp(poditog, "LXX") == 0) strcat(itog, "L");
				/*    */
				else if (strcmp(poditog, "XXXLXL") == 0 || strcmp(poditog, "XXLXXL") == 0) strcat(itog, "XXC");
				else if (strcmp(poditog, "XXLXL") == 0 || strcmp(poditog, "XLXXL") == 0) strcat(itog, "XC");
				/*    */
				else if (strcmp(poditog, "XXCXX") == 0 || strcmp(poditog, "XXXCX") == 0) strcat(itog, "XXC");
				else if (strcmp(poditog, "XCXX") == 0 || strcmp(poditog, "XXC") == 0) strcat(itog, "XC");
				else if (strcmp(poditog, "XCX") == 0 || strcmp(poditog, "CXX") == 0) strcat(itog, "C");
				/**/
				else if (strcmp(poditog, "XCXL") == 0 || strcmp(poditog, "CXXL") == 0) strcat(itog, "LC");
				else if (strcmp(poditog, "XXCXL") == 0 || strcmp(poditog, "XCXXL") == 0) strcat(itog, "XLC");
				else if (strcmp(poditog, "XXXCXL") == 0 || strcmp(poditog, "XXCXXL") == 0) strcat(itog, "XXLC");
				else strcat(itog, poditog);
				break;
			}
			else {
				if (strcmp(poditog, "LXXL") == 0 || strcmp(poditog, "XLXL") == 0) strcat(itog, "XC");
				else if (strcmp(poditog, "LXL") == 0) strcat(itog, "C");
				else if (strcmp(poditog, "LXLX") == 0) strcat(itog, "CX");
				else if (strcmp(poditog, "CXCX") == 0) strcat(itog, "CXC");
				else if (strcmp(poditog, "CX") == 0) strcat(itog, "C");
				else if (strcmp(poditog, "CXL") == 0) strcat(itog, "LC");
				else if (strcmp(poditog, "CXLX") == 0 || strcmp(poditog, "LXCX") == 0) strcat(itog, "LXC");
				else if (strcmp(poditog, "XXXXXXL") == 0) strcat(itog, "XXC");
				else if (strcmp(poditog, "XXXXXL") == 0) strcat(itog, "XC"); 
				else if (strcmp(poditog, "XXXXL") == 0) strcat(itog, "C");
				else if (strcmp(poditog, "XXXXXX") == 0) strcat(itog, "CCL");
				else if (strcmp(poditog, "XXXXX") == 0) strcat(itog, "XL");
				else if (strcmp(poditog, "XXXX") == 0) strcat(itog, "L");
				else if (strcmp(poditog, "XXX") == 0) strcat(itog, "LX");
				/**/
				else if (strcmp(poditog, "XXLXX") == 0 || strcmp(poditog, "XXXLX") == 0) strcat(itog, "XXXL");
				else if (strcmp(poditog, "XLXX") == 0 || strcmp(poditog, "XXLX") == 0) strcat(itog, "XXL");
				else if (strcmp(poditog, "XLX") == 0 || strcmp(poditog, "LXX") == 0) strcat(itog, "XL");
				/*    */
				else if (strcmp(poditog, "XXXLXL") == 0 || strcmp(poditog, "XXLXXL") == 0) strcat(itog, "XXXC");
				else if (strcmp(poditog, "XXLXL") == 0 || strcmp(poditog, "XLXXL") == 0) strcat(itog, "XXC");
				/*    */
				else if (strcmp(poditog, "XXCXX") == 0 || strcmp(poditog, "XXXCX") == 0) strcat(itog, "XXXC");
				else if (strcmp(poditog, "XCXX") == 0 || strcmp(poditog, "XXC") == 0) strcat(itog, "XXC");
				else if (strcmp(poditog, "XCX") == 0 || strcmp(poditog, "CXX") == 0) strcat(itog, "XC");
				/**/
				else if (strcmp(poditog, "XCXL") == 0 || strcmp(poditog, "CXXL") == 0) strcat(itog, "XLC");
				else if (strcmp(poditog, "XXCXL") == 0 || strcmp(poditog, "XCXXL") == 0) strcat(itog, "XXLC");
				else if (strcmp(poditog, "XXXCXL") == 0 || strcmp(poditog, "XXCXXL") == 0) strcat(itog, "XXXLC");
				else {
					strcat(itog, "X");
					strcat(itog, poditog);
				}
				break;
			}
		}
		
	} 
	/*до тысяч*/
	memset(poditog, 0, strlen(poditog));
	flag = false;
	if (itog[strlen(itog) - 1] == 'C') {
		itog[strlen(itog) - 1] = '\0';
		flag = true;
	}

 	j = 0;

	for (; i <= len1; i++) {

		if (sum[i] == 'C' || sum[i] == 'D' || (sum[i] == 'M' && sum[i + 1] == 'C')) {
			poditog[j] = sum[i];
			j++;
		}
		else {
			if (!flag) {
				if (strcmp(poditog, "DCCD") == 0 || strcmp(poditog, "CDCD") == 0) strcat(itog, "M");
				else if (strcmp(poditog, "DCD") == 0) strcat(itog, "MC");
				else if (strcmp(poditog, "DCDC") == 0) strcat(itog, "CCCD");
				else if (strcmp(poditog, "MCMC") == 0) strcat(itog, "CCCDM");
				else if (strcmp(poditog, "CMCMC") == 0) strcat(itog, "MCM");//CCXCX
				else if (strcmp(poditog, "CDCDC") == 0) strcat(itog, "MC");//CCXCX //XLXLX
				/**/
				else if (strcmp(poditog, "MCD") == 0) strcat(itog, "DCM");
				else if (strcmp(poditog, "MCDC") == 0 || strcmp(poditog, "DCMC") == 0) strcat(itog, "CCCM");
				else if (strcmp(poditog, "CCCCCCD") == 0) strcat(itog, "CM");
				else if (strcmp(poditog, "CCCCCD") == 0) strcat(itog, "M");
				else if (strcmp(poditog, "CCCCD") == 0) strcat(itog, "MC");
				else if (strcmp(poditog, "CCCCCC") == 0) strcat(itog, "CD");
				else if (strcmp(poditog, "CCCCC") == 0) strcat(itog, "D");
				else if (strcmp(poditog, "CCCC") == 0) strcat(itog, "DC");
				/**/
				else if (strcmp(poditog, "CCDCC") == 0 || strcmp(poditog, "CCCDC") == 0) strcat(itog, "CCD");
				else if (strcmp(poditog, "CDCC") == 0 || strcmp(poditog, "CCDC") == 0) strcat(itog, "CD");
				else if (strcmp(poditog, "CDC") == 0 || strcmp(poditog, "DCC") == 0) strcat(itog, "D");
				/*    */
				else if (strcmp(poditog, "CCCDCD") == 0 || strcmp(poditog, "CCDCCD") == 0) strcat(itog, "CCM");
				else if (strcmp(poditog, "CCDCD") == 0 || strcmp(poditog, "CDCCD") == 0) strcat(itog, "CM");
				/*    */
				else if (strcmp(poditog, "CCMCC") == 0 || strcmp(poditog, "CCCMC") == 0) strcat(itog, "CCM");
				else if (strcmp(poditog, "CMCC") == 0 || strcmp(poditog, "CCM") == 0) strcat(itog, "CM");
				else if (strcmp(poditog, "CMC") == 0 || strcmp(poditog, "MCC") == 0) strcat(itog, "M");
				/**/
				else if (strcmp(poditog, "CMCD") == 0 || strcmp(poditog, "MCCD") == 0) strcat(itog, "DM");
				else if (strcmp(poditog, "CCMCD") == 0 || strcmp(poditog, "CMCCD") == 0) strcat(itog, "CDM");
				else if (strcmp(poditog, "CCCMCD") == 0 || strcmp(poditog, "CCDCCD") == 0) strcat(itog, "CCDM");
				else strcat(itog, poditog);
				break;
			}
			else {
				if (strcmp(poditog, "DCCD") == 0 || strcmp(poditog, "CDCD") == 0) strcat(itog, "CM");
				else if (strcmp(poditog, "DCD") == 0) strcat(itog, "M");
				else if (strcmp(poditog, "DCDC") == 0) strcat(itog, "MC");
				else if (strcmp(poditog, "MCMC") == 0) strcat(itog, "MCM");
				else if (strcmp(poditog, "MC") == 0) strcat(itog, "M");
				else if (strcmp(poditog, "MCD") == 0) strcat(itog, "DM");
				else if (strcmp(poditog, "MCDC") == 0 || strcmp(poditog, "DCMC") == 0) strcat(itog, "DC");
				else if (strcmp(poditog, "CCCCCCD") == 0) strcat(itog, "CCM"); //
				else if (strcmp(poditog, "CCCCCD") == 0) strcat(itog, "CM");
				else if (strcmp(poditog, "CCCCD") == 0) strcat(itog, "M");
				else if (strcmp(poditog, "CCCCCC") == 0) strcat(itog, "CCD");
				else if (strcmp(poditog, "CCCCC") == 0) strcat(itog, "CD");
				else if (strcmp(poditog, "CCCC") == 0) strcat(itog, "D");
				else if (strcmp(poditog, "CCC") == 0) strcat(itog, "DC");
				/**/
				else if (strcmp(poditog, "CCDCC") == 0 || strcmp(poditog, "CCCDC") == 0) strcat(itog, "CCCD");
				else if (strcmp(poditog, "CDCC") == 0 || strcmp(poditog, "CCDC") == 0) strcat(itog, "CCD");
				else if (strcmp(poditog, "CDC") == 0 || strcmp(poditog, "DCC") == 0) strcat(itog, "CD");
				/*    */
				else if (strcmp(poditog, "CCCDCD") == 0 || strcmp(poditog, "CCDCCD") == 0) strcat(itog, "CCCM");
				else if (strcmp(poditog, "CCDCD") == 0 || strcmp(poditog, "CDCCD") == 0) strcat(itog, "CCM");
				/*    */
				else if (strcmp(poditog, "CCMCC") == 0 || strcmp(poditog, "CCCMC") == 0) strcat(itog, "CCCM");
				else if (strcmp(poditog, "CMCC") == 0 || strcmp(poditog, "CCM") == 0) strcat(itog, "CCM");
				else if (strcmp(poditog, "CMC") == 0 || strcmp(poditog, "MCC") == 0) strcat(itog, "CM");
				/**/
				else if (strcmp(poditog, "CMCD") == 0 || strcmp(poditog, "MCCD") == 0) strcat(itog, "CDM");
				else if (strcmp(poditog, "CCMCD") == 0 || strcmp(poditog, "CMCCD") == 0) strcat(itog, "CCDM");
				else if (strcmp(poditog, "CCCMCD") == 0 || strcmp(poditog, "CCDCCD") == 0) strcat(itog, "CCCDM");
				else {
					strcat(itog, "C");
					strcat(itog, poditog);
				}
				break;
			}
		}

	}

	if (sum[0] == '(') {
		for (; i <= len1; i++) {
			if (sum[i] == 'M') strcat(itog, "M");
		}
	}
	else if ((itog[strlen(itog) - 1] == 'M') || (strstr(sum, "M") && !strstr(sum, "M("))) { 	/*Если нету скобок*/

		if (strstr(itog, "M")) itog[strlen(itog) - 1] = '\0';
		*flag_skobk = true;
	}
	return itog;
}
// исправление числа
void fix_controller(char sum[], bool skobka) {
	char sigma[228]{};
	char zalupa[228]{};
	char* penis;
	bool flag_skobk = false;
	strcpy(sigma, fix_invalid_roman(sum, &flag_skobk));
	if (!skobka) {
		if(flag_skobk) strcat(sigma, ")I(");
		_strrev(sigma);
		puts(sigma);
		return;
	}
	/**/
	_strrev(sum);
	int i = 1;
	zalupa[0] = ')';
	while (sum[i] != ')') {
		zalupa[i] = sum[i];
		i++;
	}
	zalupa[i] = '(';
	/**/
	strcat(sigma, ")");
	penis = fix_invalid_roman(zalupa, &flag_skobk);
	strcat(sigma, penis);
	strcat(sigma, "(");
	_strrev(sigma);
	puts(sigma);
}

// основная функция программы
void plus_num(char num1[], char num2[], char sum[]) {
	int len1 = strlen(num1), len2 = strlen(num2);
	int k = len1 + len2;
	int s = 0, j = 0, i = 0;

	bool flag = false;
	bool skobka = false;
	for (int t = 0; t < 2; t++) {
		if (num1[i] == '(' && num2[j] == '(') {
			flag = true;
			skobka = true;
			sum[s] = '(';
			s++;
			i++;
			j++;

		}
		else if (num1[i] == '(') {
			t++;
			i++;
			skobka = true;
			sum[s++] = '(';
			while (num1[i] != ')') {
				sum[s] = num1[i];
				s++;
				i++;
			}
			sum[s++] = ')';
			i++;
		}
		else if (num2[j] == '(') {
			t++;
			skobka = true;
			sum[s++] = '(';
			while (num2[j] != ')') {
				sum[s] = num2[j];
				s++;
				j++;
			}
			sum[s++] = ')';
			j++;
		}
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
		if (num1[i] == 'D' || num2[j] == 'D') {
			if (num1[i] == 'D' && num2[j] == 'D') {
				sum[s] = 'M';
				i++;
				j++;
				s++;
			}
			else {
				if (num1[i] == 'D') {
					sum[s] = 'D';
					i++;
					s++;
				}
				if (num2[j] == 'D') {
					sum[s] = 'D';
					j++;
					s++;
				}
			}
		}
		while (num1[i] == 'C' || num2[j] == 'C') {
			if (num1[i] == 'C') {
				sum[s] = 'C';
				i++;
				if (num1[i] == 'M' || num1[i] == 'D') {
					sum[++s] = num1[i];
					i++;
				}
				s++;
			}
			if (num2[j] == 'C') {
				sum[s] = 'C';
				j++;
				if (num2[j] == 'M' || num2[j] == 'D') {
					sum[++s] = num2[j];
					j++;
				}
				s++;
			}
		}
		while (num1[i] == 'L' || num2[j] == 'L') {
			if (num1[i] == 'L' && num2[j] == 'L') {
				sum[s] = 'C';
				i++;
				j++;
				s++;
			}
			else {
				if (num1[i] == 'L') {
					sum[s] = 'L';
					i++;
					s++;
				}
				if (num2[j] == 'L') {
					sum[s] = 'L';
					j++;
					s++;
				}
			}
		}
		while (num1[i] == 'X' || num2[j] == 'X') {
			if (num1[i] == 'X') {
				sum[s] = 'X';
				i++;
				if (num1[i] == 'C' || num1[i] == 'L') {
					sum[++s] = num1[i];
					i++;
				}
				s++;
			}
			if (num2[j] == 'X') {
				sum[s] = 'X';
				j++;
				if (num2[j] == 'C' || num2[j] == 'L') {
					sum[++s] = num2[j];
					j++;
				}
				s++;
			}
		}
		if (num1[i] == 'V' || num2[j] == 'V') {
			if (num1[i] == 'V' && num2[j] == 'V') {
				sum[s] = 'X';
				i++;
				j++;
				s++;
			}
			else {
				if (num1[i] == 'V') {
					sum[s] = 'V';
					i++;
					s++;
				}
				if (num2[j] == 'V') {
					sum[s] = 'V';
					j++;
					s++;
				}
			}
		}
		while (num1[i] == 'I' || num2[j] == 'I') {
			if (num1[i] == 'I') {
				sum[s] = 'I';
				i++;
				if (num1[i] == 'X' || num1[i] == 'V') {
					sum[++s] = num1[i];
					i++;
				}
				s++;
			}
			if (num2[j] == 'I') {
				sum[s] = 'I';
				j++;
				if (num2[j] == 'X' || num2[j] == 'V') {
					sum[++s] = num2[j];
					j++;
				}
				s++;
			}
		}
		if (flag) {
			i++;
			j++;
			sum[s] = ')';
			s++;
			flag = false;
		}
	}
	sum[len1 + len2] = '\0';
	printf("Пробный рез: %s\n", sum);
	fix_controller(sum, skobka);

}

// Обработка некорректно введённого числа пользователем
void input_bug_catcher(char num[], bool* flag, bool* range) {

	int len_s = strlen(num); // разрядность числа num
	int d_check = 1; // проверка числа на допустимое количество цифр

	bool skobka = false;
	bool close_skobka = false;

	for (int i = 0; i < len_s; i++) {
		if (num[i] == '(') {
			if (close_skobka) break;
			skobka = true;
			i++;
		}
		if (num[i] == 'M') {
			if (close_skobka) break;
			if (skobka && d_check > 3) {
				*range = true;
				break;
			}
			if (d_check > 3) break;
			if (num[i + 1] == 'M') {
				d_check++;
				continue;
			}
			i++;
			d_check = 1; //сбрасываем счетчик
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
			d_check = 1; //сбрасываем счетчик
		}
		if (skobka && num[i] == ')' && i != len_s - 1) {
			if (close_skobka) break;
			close_skobka = true;
			continue;
		}
		if (num[i] == ')') {
			i++;
		}
		if (i < len_s) break;
		*flag = false; // Ошибок в вводе не обнаружено
		return;
	}
	*flag = true; //Допущены ошибки в вводе

}

// Интерфейс пользователя
void user_interface() {

	char firstRomanNumeral[N], secondRomanNumeral[N], sumOfRomanNumeral[39]{}; //15 + 15 +( +) + \0 ->> 33 //18 + 18 + ( + ) + \0 = 
	bool flag = false; //корректно ли введено число
	bool range = false; // не превышает ли число допустимый диапазон // диапазон увеличиться

	// Ввод и проверка первого числа
	do {
		printf("Введите первое римское число: ");
		gets_s(firstRomanNumeral);
		input_bug_catcher(firstRomanNumeral, &flag, &range);

		if (range) printf("Вы ввели число, выходящее за допустимый диапазон. Введите число заново.\n");
		else if (flag) printf("Вы ввели некорректное число. Введите число заново.\n");

	} while (flag);

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
	setlocale(0, "");

	printf("Сложение двух натуральных чисел в римской системе счисления\n");
	printf("Вводите числа, входящие в диапазон от 0 до 10мил.\n");

	user_interface();

	return 0;
}