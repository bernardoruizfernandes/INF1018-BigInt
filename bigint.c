/* Bernardo Ruiz Fernandes 1711180 3WA */
/* Rafael Barbosa Matricula 3WA */

#include <stdio.h>
#include "bigint.h"


/* Print do BigInt */
void big_print(BigInt res){
	
	int n = 16;

	while(n--)
		printf("%02x", res[n]);

	printf("\n");
	return;
}


/* Atribuição (com extensão) */

void dump (void *p, int n, BigInt res) {

	unsigned char *p1 = p;
	int a = 0;

	while (n--) {
		res[a] = *p1;
		a++;
		p1++;
	}
}

void big_val (BigInt res, long val){

	int k = 8;

	dump(&val, sizeof(val), res);

	while (k<16){
		res[k] = 0;
		k++;
	}

	return;
}




/* Operações Aritméticas */


/* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b){

	unsigned int s, ext = 0, n = 0;

	while (n<16){

		s = a[n] + b[n] + ext;
		res[n] = s%256;
		ext = (s/255);
		n++;

	}
	return;
}	

	


/* res = -a */
void big_comp2(BigInt res, BigInt a){

	int n = 0;
	BigInt num_1;

	big_val(num_1,1);
	
	while (n<16){
		//printf("1-%02x\n",a[n]);
		a[n] = ~(a[n]);
		//printf("2-%02x\n",a[n]);
		n++;
	}

	big_print(a);

	big_sum(res, a, num_1);

	return ;
}






	




