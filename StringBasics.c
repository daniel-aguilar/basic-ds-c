#include "StringBasics.h"

void runBasics() {
	// In C, string are an array of char, with a NUL at the end.
	// The contents of myString are in memory and can be changed
	char myString[] = "Dhis is a string literal, null terminated\n";
	myString[0] = 'T';

	// This is a constant, you may not change the contents of memory here.
	// This is essentially a constant
	char* pointingToStringLiteral = "This is also a null terminated string literal\n";

	char mysteriousString[25]; // String filled with garbage, we did not assign any values here.
	mysteriousString[24] = '\0'; // Try commenting out this line

	printf("%s%s", myString, pointingToStringLiteral);
	printf("Mysterious string: %s\n", mysteriousString);

	char tight[]/*[5]*/ = "hello"; // Not enough space for null char? stack buffer overflow
	printf("%d\n", strlen(tight));

	/* Useful reading material :
	* Basic definitions, compiler behaviour:
	* https://stackoverflow.com/a/72436705
	* https://softwareengineering.stackexchange.com/a/181509
	*
	* string arrays vs pointers to strings
	* https://stackoverflow.com/a/3207555
	*
	* When does the 'compiler' stop reading a string?
	* https://stackoverflow.com/a/58173248
	*
	*
	* Pointers: asterisk on the left or right side?
	* https://stackoverflow.com/a/2660818
	*/
}
