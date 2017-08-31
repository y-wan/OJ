#include <stdio.h>
#include <string.h>
void dec2bin(int n, char res[]) {
	memset(res, '\0', sizeof(res));
	for (int i = 0; i < 8; i++) {
		res[7 - i] = n % 2 + '0';
		n >>= 1;
	}
	res[8] = '\0';
}

void convert(char s[20], char res[]) {
	char bin[9];
	memset(res, '\0', sizeof(res));
	int a[4];
	sscanf(s, "%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
	for (int i = 0; i < 4; i++) {
		memset(bin, '\0', sizeof(bin));
		dec2bin(a[i], bin);
		strcat(res, bin);
	}
}

void bin2dec(char bin[], char res[]) {
	int a[4] = { 0, 0, 0, 0 };
	memset(res, '\0', sizeof(res));
	for (int i = 0; i < 4; i++) {
		int base = 1;
		for (int j = 0; j < 8; j++) {
			a[i] += (bin[i * 8 + 7 - j] - '0') * base;
			base <<= 1;
		}
		sprintf(res, "%d.%d.%d.%d", a[0], a[1], a[2], a[3]);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int num;
	while (scanf("%d", &num) == 1) {
		int same = 32;
		char s[20], s1[20], bin[33], bin1[33], ziwang[33];
		memset(ziwang, '1', sizeof(char) * 32);
		ziwang[32] = '\0';
		scanf("%s", s);
		convert(s, bin);
		if (num == 1) {
			printf("%s\n255.255.255.255\n", s);
			continue;
		}
		for (int i = 0; i < num - 1; i++) {
			scanf("%s", s1);
			memset(bin1, '\0', sizeof(bin1));
			convert(s1, bin1);
			for (int j = 0; j < 32 && j < same; j++) {
				if (bin[j] != bin1[j]) {
					same = same < j ? same : j;
					break;
				}
			}
		}
		for (int i = 0; i < 32 - same; i++) {
			bin[31 - i] = '0';
			ziwang[31 - i] = '0';
		}
		char s_dec[20], ziwang_dec[20];
		bin2dec(bin, s_dec);
		bin2dec(ziwang, ziwang_dec);
		printf("%s\n%s\n", s_dec, ziwang_dec);
	}
	return 0;
}