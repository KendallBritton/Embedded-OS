#include <stdio.h>
#include <string.h>

typedef unsigned char* byte_pointer;


int strlongerBase(const char* s, const char* t) {
	return strlen(s) - strlen(t) > 0;
}

int strlongerNew(const char* s, const char* t) {
	return strlen(s) > strlen(t);
}


int main() {

	
	const char* char1;
	const char* char2;

	char1 = "abcdef";
	char2 = "abcdefgh";



	int ans = strlongerBase(char1, char2);
	printf("Original Function: %u\n", ans);
		
	ans = strlongerNew(char1, char2);
	printf("Fixed Function: %u\n", ans);

}