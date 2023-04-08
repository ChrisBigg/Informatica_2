
//#include "to_upper.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ToUpper(char* str) {

	size_t len = strlen(str);

	for (int i = 0; i < len; ++i) {
		if (*(str + i) >= 97 && *(str + i) <= 122) {
			*(str + i) = *(str + i) - 32;
		}

	}
}



