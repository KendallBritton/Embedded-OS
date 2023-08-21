#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
	int i;
	printf("0x");
	for (i = len - 1; i >= 0; i--) {		// Prints it as normal representation
		printf("%.2x", start[i]);
	}
}

int fun1(unsigned word) {
	return (int)((word << 24) >> 24);
}

int fun2(unsigned word) {
	return ((int)word << 24) >> 24;
}

int main() {

	int A, B, C, D, ans1, ans2;
	byte_pointer Apointer = (byte_pointer)&A;
	byte_pointer Bpointer = (byte_pointer)&B;
	byte_pointer Cpointer = (byte_pointer)&C;
	byte_pointer Dpointer = (byte_pointer)&D;

	byte_pointer Ans1Pointer = (byte_pointer)&ans1;
	byte_pointer Ans2Pointer = (byte_pointer)&ans2;

	A = 0x00000076;
	B = 0x87654321;
	C = 0x000000C9;
	D = 0xEDCBA987;

	/* Solution to Part A */
	ans1 = fun1(A);
	ans2 = fun2(A);
	printf("W             fun1(w)       fun2(w)\n");
	show_bytes(Apointer, 4);
	printf("    ");
	show_bytes(Ans1Pointer, 4);
	printf("    ");
	show_bytes(Ans2Pointer, 4);
	printf("\n");

	/* Solution to Part B */
	ans1 = fun1(B);
	ans2 = fun2(B);
	show_bytes(Bpointer, 4);
	printf("    ");
	show_bytes(Ans1Pointer, 4);
	printf("    ");
	show_bytes(Ans2Pointer, 4);
	printf("\n");

	/* Solution to Part C */
	ans1 = fun1(C);
	ans2 = fun2(C);
	show_bytes(Cpointer, 4);
	printf("    ");
	show_bytes(Ans1Pointer, 4);
	printf("    ");
	show_bytes(Ans2Pointer, 4);
	printf("\n");

	/* Solution to Part D */
	ans1 = fun1(D);
	ans2 = fun2(D);
	show_bytes(Dpointer, 4);
	printf("    ");
	show_bytes(Ans1Pointer, 4);
	printf("    ");
	show_bytes(Ans2Pointer, 4);
	printf("\n");




}

