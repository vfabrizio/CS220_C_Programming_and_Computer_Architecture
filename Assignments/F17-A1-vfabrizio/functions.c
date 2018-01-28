#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isFib(unsigned long i) {
	if (i >= 0 && i <= 1000000000) {
		if (i <= 1) {
			return i+1;
		}else {
			int first, second, next, result;
			first = 0;
			second = next = 1;
			result = 2;

			while (next < i) {
				next = first + second;
				if (next > i) return -1;
				first = second;
				second = next;
				result++;
			}
			return result;
		}
	} else {
		return -1;
	}
}

/*three helper functions for #2*/
void ones(int digit, char array[], int i) {
	if (i == 0) {
		if (digit == 1) {
			strcpy(array, "OnE");
		} else if (digit == 2) {
			strcpy(array, "twO");
		} else if (digit == 3) {
			strcpy(array, "thrEE");
		} else if (digit == 4) {
			strcpy(array,"fOUr");
		} else if (digit == 5) {
			strcpy(array, "fIvE");
		} else if (digit == 6) {
			strcpy(array, "sIx");
		} else if (digit == 7) {
			strcpy(array, "sEvEn");
		} else if (digit == 8) {
			strcpy(array, "EIght");
		} else if (digit == 9) {
			strcpy(array, "nInE");
		}
	}else {
		if (digit == 1) {
			strcat(array, "OnE");
		} else if (digit == 2) {
			strcat(array, "twO");
		} else if (digit == 3) {
			strcat(array, "thrEE");
		} else if (digit == 4) {
			strcat(array,"fOUr");
		} else if (digit == 5) {
			strcat(array, "fIvE");
		} else if (digit == 6) {
			strcat(array, "sIx");
		} else if (digit == 7) {
			strcat(array, "sEvEn");
		} else if (digit == 8) {
			strcat(array, "EIght");
		} else if (digit == 9) {
			strcat(array, "nInE");
		}
	}
}

void tens(int digit, char array[], int i) {
	if (i == 0) {
		if (digit == 1) {
			strcpy(array, "tEn");
		} else if (digit == 2) {
			strcpy(array, "twEnty");
		} else if (digit == 3) {
			strcpy(array, "thIrty");
		} else if (digit == 4) {
			strcpy(array, "fOrty");
		} else if (digit == 5) {
			strcpy(array, "fIvty");
		} else if (digit == 6) {
			strcpy(array, "sIxty");
		} else if (digit == 7) {
			strcpy(array, "sEvEnty");
		} else if (digit == 8) {
			strcpy(array, "EIghty");
		} else if (digit == 9) {
			strcpy(array, "nInEty");
		}
	}else {
		if (digit == 1) {
			strcat(array, "tEn");
		} else if (digit == 2) {
			strcat(array, "twEnty");
		} else if (digit == 3) {
			strcat(array, "thIrty");
		} else if (digit == 4) {
			strcat(array, "fOrty");
		} else if (digit == 5) {
			strcat(array, "fIvty");
		} else if (digit == 6) {
			strcat(array, "sIxty");
		} else if (digit == 7) {
			strcat(array, "sEvEnty");
		} else if (digit == 8) {
			strcat(array, "EIghty");
		} else if (digit == 9) {
			strcat(array, "nInEty");
		}
	}
}

void odds(int digit, char array[], int i) {
	if (i == 0) {
		if (digit == 10) {
			strcpy(array, "tEn");
		}else if (digit == 11) {
			strcpy(array, "ElEvEn");
		}else if (digit == 12) {
			strcpy(array, "twElvE");
		}else if (digit == 13) {
			strcpy(array, "thIrtEEn");
		}else if (digit == 14) {
			strcpy(array, "fOUrtEEn");
		}else if (digit == 15) {
			strcpy(array, "fIftEEn");
		}else if (digit == 16) {
			strcpy(array, "sIxtEEn");
		}else if (digit == 17) {
			strcpy(array, "sEvEntEEn");
		}else if (digit == 18) {
			strcpy(array, "EIghtEEn");
		}else if (digit == 19) {
			strcpy(array, "nInEtEEn");
		}
	}else {
		if (digit == 10) {
			strcat(array, "tEn");
		}else if (digit == 11) {
			strcat(array, "ElEvEn");
		}else if (digit == 12) {
			strcat(array, "twElvE");
		}else if (digit == 13) {
			strcat(array, "thIrtEEn");
		}else if (digit == 14) {
			strcat(array, "fOUrtEEn");
		}else if (digit == 15) {
			strcat(array, "fIftEEn");
		}else if (digit == 16) {
			strcat(array, "sIxtEEn");
		}else if (digit == 17) {
			strcat(array, "sEvEntEEn");
		}else if (digit == 18) {
			strcat(array, "EIghtEEn");
		}else if (digit == 19) {
			strcat(array, "nInEtEEn");
		}
	}
}

unsigned int count_vowels(unsigned long num) {
	if (num >= 0 && num <= 1000000000) {
		char word[200];
		int digit, twodig, i, temp1, temp2, numVowels = 0;
		int count = 0;
		memset(word, '\0', sizeof(word));
		if (num == 0) {
			strcpy(word, "zErO");
		} else if (num == 1000000000) {
			strcpy(word, "OnE bIllIOn");
		}else {
			while (num > 0) {
				digit = num % 10;
				count++;
				num = num / 10;
				if (count == 1) {
					temp1 = digit;
					digit = num % 10;
					if (digit == 1) {
						count++;
						num = num / 10;
						digit = digit*10 + temp1;
						odds(digit, word, 0);
					} else {
						ones(temp1, word, 0);
					}
				} else if (count == 2) {
					tens(digit, word, 1);
				} else if (count == 3) {
					ones(digit, word, 1);
					if (digit != 0) {
						strcat(word, "hUndrEd");
					}
				} else if (count == 4) {
					temp1 = digit;
					digit = num % 10;
					if (digit == 1) {
						count++;
						num = num / 10;
						digit = digit*10 + temp1;
						odds(digit, word, 1);
					} else {
						ones(temp1, word, 1);
					}
					temp2 = digit;
					digit = temp2 % 10;
					if (temp1 != 0 || temp2 != 0 || digit != 0) {
						strcat(word, "thOUsAnd");
					}
				} else if (count == 5) {
					tens(digit, word, 1);
				} else if (count == 6) {
					ones(digit, word, 1);
					if (digit != 0) {
						strcat(word, "hUndrEd");
					}
				} else if (count == 7) {
					temp1 = digit;
					digit = num % 10;
					if (digit == 1) {
						count++;
						num = num / 10;
						digit = digit*10 + temp1;
						odds(digit, word, 1);
					} else {
						ones(temp1, word, 1);
					}
					temp2 = digit;
					digit = temp2 % 10;
					if (temp1 != 0 || temp2 != 0 || digit != 0) {
						strcat(word, "mIllIOn");
					}
				} else if (count == 8) {
					tens(digit, word, 1);
				} else if (count == 9) {
					ones(digit, word, 1);
					if (digit != 0) {
						strcat(word, "hUndrEd");
					}
				}
			}
		}
		for (i = 0; i < 200; i++) {
			if (word[i] == 'A' | word[i] == 'E' | word[i] == 'I' | word[i] == 'O' | word[i] == 'U') {
				numVowels++;
			}
		}

		printf("word: %s\n", word);
		return numVowels;
		
	}else {
		return 0;
	}
}

unsigned int count_ones(long n) {
	int count, mod, neg, cycles, i, j = 0;
	int add = 1;
	int array[64];
	int flip[64];
	count = 0;
	cycles = 0;
	if (n < 0) {
		n = labs(n);
		neg = 1;
	}
	for (i = 0; i < 64; i++) {
		array[i] = 123;
	}
	while (n > 0) {
		mod = n % 2;
		array[cycles] = mod;
		cycles++; /*counts number of bits*/
		if (mod == 1) {
			count++;
		}
		n = n / 2;
	}
	if (neg == 1) {
		count = 0;
		for (i=0, j=63; j >= 0; i++, j--) {
			flip[i] = array[j];
		}
		/*flip the bits*/
		for (i = 0; i < 64; i++) {
			if (flip[i] == 0) {
				flip[i] = 1;
			}else if (flip[i] == 1) {
				flip[i] = 0;
			}
		}
		/*add 1*/
		for (i = 63; i >= 0; i--) {
			if (add == 1) {
				if(flip[i] == 1) {
					flip[i] = 0;
					add = 1;
				}else {
					flip[i] = 1;
					add = 0;
				}
			}
		}
		for (i = 0; i < 64; i++) {
			if (flip[i] == 123) {
				flip[i] = 1;
			}
		}
		for (i = 0; i < 64; i++) {
			if (flip[i] == 1) {
				count++;
			}
		}		
	}
	return count;
}

unsigned long swap_bytes(unsigned long n) {
	long array[8];
	long ret[8];
	int i, j;
	unsigned long ans;
	for (i = 0, j = 0; i < 8; i++, j+=8) {
		array[i] = (n >> j) & 0xff;
	}
	/*for (i = 0; i < 8; i++) {
		printf("array[%d]: %#lx\n", i, array[i]);
	}*/
	for (i = 0, j = 7; j >= 0; i+=2, j-=2) {
		ret[i] = array[j-1];
		ret[i+1] = array[j];
	}
	/*for (i = 0; i < 8; i++) {
		printf("ret[%d]: %#lx\n", i, ret[i]);
	}
	for (i = 8, j = 64; i >= 0; i-=2, j-=16) {
		ans = (ret[i] << j) | (ret[i-1] << (j-8));
	}*/
	ans = (ret[0]<<56) | (ret[1]<<48) | (ret[2]<<40) | (ret[3]<<32) | (ret[4]<<24) | (ret[5]<<16) | (ret[6]<<8) | ret[7];
	return ans;
	
}

long a4_minus_b4(int a, int b) {
	if (a >= -100 && a <= 100 && b >= -100 && b <= 100) {
		long a4, b4;
		a4 = a * a * a * a;
		b4 = b * b * b * b;
		return a4 - b4;
	}else {
		return -1;
	}
}
