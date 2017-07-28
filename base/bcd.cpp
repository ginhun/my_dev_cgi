#include <string.h>
#include "bcd.h"

void my_strupr(char *p) {
	char c;
	while ((c = *p)) {
		if (c >= 'a'&&c <= 'z') {
			*p -= ('a'-'A');
		}
		p++;
	}
}

int BCD_Encode(const unsigned char *source, int sourceLength, 
		char *dest, int maxDestLength, int *resultLength) {
	int i, pos, g, l;
	int result = -99;
	const static char *ctable = "0123456789ABCDEF";

	if (resultLength == NULL || maxDestLength <= 0
		|| sourceLength <= 0 || source == NULL || dest == NULL) {
		return -1;
	}
	dest[0] = 0;
	*resultLength = 0;
	pos = 0;
	i = 0;
	result = 0;
	while (i<sourceLength) {
		g = source[i] / 16;
		l = source[i] % 16;
		if (pos<maxDestLength-3) {
			dest[pos] = ctable[g];
			dest[pos+1] = ctable[l];
			pos += 2;
		} else {
			result = -2;
			break;
		}
		i++;
	}
	dest[pos] = 0;
	*resultLength = pos;
	return result;
}


int BCD_Decode(const char *source, int sourceLength, 
		unsigned char *dest, int maxDestLength, int *resultLength) {
	int i, pos;
	char bt[3];
	int g, l;
	int result = -99;

	if (resultLength == NULL || maxDestLength <= 0
		|| sourceLength <= 0 || source == NULL || dest == NULL) {
		return -1;
	}
	*resultLength = 0;
	pos = 0;
	i = 0;
	result = 0;
	while (i < sourceLength && source[i]) {
		bt[0] = source[i];
		bt[1] = source[i+1];
		bt[2] = 0;
		if (!(bt[1])) {
			result = -2;
			break;
		}
		my_strupr(bt);
		g = l = 0;
		if (bt[0] >= 'A' && bt[0] <= 'F') {
			g = 10 + (bt[0] - 'A');
		} else if (bt[0] >= '0' && bt[0] <= '9') {
			g = bt[0] - '0';
		} else{
			result = -3;
			break;
		}

		if (bt[1] >= 'A' && bt[1] <= 'F') {
			l = 10 + (bt[1] - 'A');
		} else if (bt[1] >= '0' && bt[1] <= '9') {
			l = bt[1] - '0';
		} else {
			result = -4;
			break;
		}

		if (pos<maxDestLength) {
			dest[pos] = (unsigned char)(g*16+l);
			pos ++;
		} else {
			result = -5;
			break;
		}
		i += 2;
	}
	*resultLength = pos;
	return result;
}
