#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "uart_pl011.h"
#include <math.h>

#define UART0_ADDR 0x101F1000

char buf[64];
uint8_t buf_idx = 0u;

int num1Array[64];
int num2Array[64];
int i = 0;
int j = 0;
int num1 = 0;
int num2 = 0;
char operand = 0x0;

/* Calculates the number */
void cal(int num1, char oper, int num2) {
    int result;
    char buffer[64];

    if (oper == 0x2A){

	result = num1 * num2;
	itoa(result, buffer, 10);
	uart_write((const char *) buffer);
	uart_write("\n");

    } else if (oper == 0x2B){

	result = num1 + num2;
	itoa(result, buffer, 10);
	uart_write((const char *) buffer);
	uart_write("\n");

    } else if (oper == 0x2D){

	result = num1 - num2;
	itoa(result, buffer, 10);
	uart_write((const char *) buffer);
	uart_write("\n");

    } else if (oper == 0x2F){

	result = num1 / num2;
	itoa(result, buffer, 10);
	uart_write((const char *) buffer);
	uart_write("\n");

  }

}

void buildInteger(){		// Builds the integer from the array
	int index = 0;

	while(index < i){
		num1 = num1*10 + num1Array[index];
		index++;
	}

	index = 0;

	while(index < j){
		num2 = num2*10 + num2Array[index];
		index++;
	}


}

static void parse_cmd(void) {

    if (!strncmp("help\r", buf, strlen("help\r"))) {
        uart_write("Just type and see what happens!\n");
    } else if (!strncmp("uname\r", buf, strlen("uname\r"))) {
        uart_write("bare-metal arm 06_uart\n");
    } else if (!strncmp("calc\r", buf, strlen("calc")) || !strncmp("CALC\r", buf, strlen("CALC"))){
	buildInteger();
    	cal(num1, operand, num2);
    }
}



int main() {
        uart_config config = {
            .data_bits = 8,
            .stop_bits = 1,
            .parity = false,
            .baudrate = 9600
        };
        uart_configure(&config);

	

        uart_putchar('A');
        uart_putchar('B');
        uart_putchar('C');
        uart_putchar('\n');

        uart_write("I love drivers!\n");
        uart_write("Type below...\n");

        while (1) {
            char c;
            if (uart_getchar(&c) == UART_OK) {
		if ((c >= 0x30 && c <= 0x39) && operand == 0x0){	// Captures/assigns first number

			switch(c){
			case 0x30:
				num1Array[i] = 0x0;
				break;
			case 0x31:
				num1Array[i] = 0x1;
				break;
			case 0x32:
				num1Array[i] = 0x2;
				break;
			case 0x33:
				num1Array[i] = 0x3;
				break;
			case 0x34:
				num1Array[i] = 0x4;
				break;
			case 0x35:
				num1Array[i] = 0x5;
				break;
			case 0x36:
				num1Array[i] = 0x6;
				break;
			case 0x37:
				num1Array[i] = 0x7;
				break;
			case 0x38:
				num1Array[i] = 0x8;
				break;
			case 0x39:
				num1Array[i] = 0x9;
				break;
			default:
				num1Array[i] = 0x0;
				break;
			}
		   i++;    
			
		}
		if ((c == 0x2A || c == 0x2B || c == 0x2D || c == 0x2F) && operand == 0x0){	// Captures/assigns operand

			switch(c){
			case 0x2A:
				operand = '*';
				break;
			case 0x2B:
				operand = '+';
				break;
			case 0x2D:
				operand = '-';
				break;
			case 0x2F:
				operand = '/';
				break;
			default:
				operand = 0x0;
				break;

			}
			
		}

		if ((c >= 0x30 && c <= 0x39) && (operand != 0x0)){		// Captures/assigns second number
			switch(c){
			case 0x30:
				num2Array[j] = 0;
				break;
			case 0x31:
				num2Array[j] = 1;
				break;
			case 0x32:
				num2Array[j] = 2;
				break;
			case 0x33:
				num2Array[j] = 3;
				break;
			case 0x34:
				num2Array[j] = 4;
				break;
			case 0x35:
				num2Array[j] = 5;
				break;
			case 0x36:
				num2Array[j] = 6;
				break;
			case 0x37:
				num2Array[j] = 7;
				break;
			case 0x38:
				num2Array[j] = 8;
				break;
			case 0x39:
				num2Array[j] = 9;
				break;
			default:
				num2Array[j] = 0;
				break;
			}
		   j++;
		
		}
	   	
                uart_putchar(c);
                buf[buf_idx % 64] = c;
                buf_idx++;
                if (c == '\r') {
                    uart_write("\n");
                    buf_idx = 0u;
                    parse_cmd();
		    i = 0;
		    j = 0;
		    num1 = 0;
		    num2 = 0;	
		    operand = 0x0;	
                }
            }
	

        }

        return 0;
}
