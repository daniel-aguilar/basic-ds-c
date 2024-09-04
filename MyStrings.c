#include "MyStrings.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *makeCopy(char *origin) {
	char *copy;
	// Make sure to use AddressSanitizer (ASan) to prevent common pitfals
	copy = (char*) malloc(strlen(origin) + 1);
	strcpy(copy, origin);
	return copy;
}

void runExample() {
	char *res = makeCopy("hello");
	res = realloc(res, 10 + 1);
	
	strcat(res, "world");
	printf("%s\n", res);
	free(res);
}
