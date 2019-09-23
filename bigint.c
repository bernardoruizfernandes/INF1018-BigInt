/* Bernardo Ruiz Fernandes 1711180 3WA */
/* Rafael Barbosa Matricula 3WA */

#include <stdio.h>
#include "bigint.h"


/* Print do BigInt ----------------------------------------------------------------- */
void big_print(BigInt res){
	
	unsigned int n = 16;

	while(n--)
		printf("%02x", res[n]);

	printf("\n");
	return;
}


/* Atribuição (com extensão) ------------------------------------------------------- */

void dump (void *p, int n, BigInt res) {

	unsigned char *p1 = p;
	unsigned int a = 0;

	while (n--) {
		res[a] = *p1;
		a++;
		p1++;
	}
}


void big_val (BigInt res, long val){

	unsigned int k = 8;

	dump(&val, sizeof(val), res);

	while (k<16){
		res[k] = 0;
		k++;
	}

	return;
}




/* Operações Aritméticas ----------------------------------------------------------- */


/* res = a + b - - - - - - - - - - - - - - - - - - */
void big_sum(BigInt res, BigInt a, BigInt b){

	unsigned int s, ext = 0, n = 0;

	while (n<16){

		s = a[n] + b[n] + ext;
		res[n] = s%256;
		ext = (s/256);
		n++;

	}
	return;
}	

	

/* res = -a  - - - - - - - - - - - - - - - - - - - */
void big_comp2(BigInt res, BigInt a){

	unsigned int n = 0;
	BigInt num_1, invet;

	big_val(num_1,1);
	
	while (n<16){
		invet[n] = ~a[n];
		n++;
	}

	big_sum(res, invet, num_1);

	return ;
}


/* res = a - b - - - - - - - - - - - - - - - - - - */
void big_sub(BigInt res, BigInt a, BigInt b){

	BigInt b_neg;

	big_comp2(b_neg,b);
	big_sum(res, a, b_neg);

	return;
}





/* Operações de Deslocamento ------------------------------------------------------- */

/* res = a << n - - - - - - - - - - - - - - - - - -*/
void big_shl(BigInt res, BigInt a, int n){

	int c, b = 0 , t = 0, i= 0;

	while(n>8){
	
		res[t]= 0;
		t++;
		n-=8;
	}

	while(t<16){

		c = a[i]<<(n);
		res[t] = c + b;
		b = a[i]>>(8-n);
		i++;
		t++;
	}

	return;
}







