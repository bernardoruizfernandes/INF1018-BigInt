#include <stdio.h>
#include "bigint.h"


void big_print2(BigInt res){
	
	int n = 16;

	while(n--)
		printf("%02x", res[n]);

	printf("\n");
	return;
}


int main (void){

	long num = 1000000;
	long num2 = 1;
	long num3 = 1000;
	BigInt numb_1, numb_2, numb_3;
	BigInt numb_c1, numb_c2;
	BigInt numb_sm12, numb_sm13, numb_sm11;
	BigInt numb_sb12, numb_sb13;
	BigInt numb_sl1, numb_sl11, numb_sl2;


/* ======= fazendo os bigints ======= */
	big_val(numb_1, num);
	big_val(numb_2, num2);
	big_val(numb_3, num3);

	/* prints */
	
	printf("\n\nBigInt 1 _________________________\n");
	big_print2(numb_1);

	printf("\n\nBigInt 2 _________________________\n");
	big_print2(numb_2);

	printf("\n\nBigInt 3 _________________________\n");
	big_print2(numb_3);
	
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

/* ======= comparacao dos bigints ======= */
	big_comp2(numb_c1, numb_1);
	big_comp2(numb_c2, numb_2);

	/* prints */
	printf("\n\ninverte a2 (1) _________________________\n");
	big_print2(numb_c1);

	printf("\n\ninverte a2 (2) _________________________\n");
	big_print2(numb_c2);
	
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

/* ======= somando bigints ======= */
	big_sum(numb_sm12, numb_1, numb_2);
	big_sum(numb_sm13, numb_1, numb_3);
	big_sum(numb_sm11, numb_1, numb_1);
	
	/* prints */

	printf("\n\nSoma (1)(2) _________________________\n");
	big_print2(numb_sm12);

	printf("\n\nSoma (1)(3) _________________________\n");
	big_print2(numb_sm13);

	printf("\n\nSoma (1)(1) _________________________\n");
	big_print2(numb_sm11);

	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");


/* ======= subtraindo bigints ======= */
	big_sub(numb_sb12, numb_1, numb_2);
	big_sub(numb_sb13, numb_1, numb_3);
	
	/* prints */

	printf("\n\nSoma (1)(2) _________________________\n");
	big_print2(numb_sb12);

	printf("\n\nSoma (1)(3) _________________________\n");
	big_print2(numb_sb13);

	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");


/* ======= shift =======*/
	big_shl(numb_sl1,numb_1, 10);
	big_shl(numb_sl11,numb_sm11, 50);
	big_shl(numb_sl2,numb_2, 50);

	/* prints */

	printf("\n\nLeft Shift (1)(10) _________________________\n");
	big_print2(numb_sl1);

	printf("\n\nLeft Shift (1+1)(50) _________________________\n");
	big_print2(numb_sl11);

	printf("\n\nLeft Shift (2)(50) _________________________\n");
	big_print2(numb_sl2);



	return 0;
}	
