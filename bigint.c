/* Bernardo Ruiz Fernandes 1711180 3WA */
/* Rafael Barbosa Matricula 3WA */

#include <stdio.h>
#include "bigint.h"


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

	unsigned int k = 8, u;

	dump(&val, sizeof(val), res);

	u = val>>63;

	while (k<16){
		res[k] = u;
		k++;
	}

	return;
}


/* Operações de Deslocamento ------------------------------------------------------- */

/* res = a << n - - - - - - - - - - - - - - - - - -*/
void big_shl(BigInt res, BigInt a, int n){

	int c, b = 0, t = 0, i= 0;

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

/*res = a >> n (logico)- - - - - - - - - - - - - -*/

void big_shr (BigInt res, BigInt a, int n){
	
	int c, b = 0, t = 15, i = 15;

	while (n > 8){
		res[t] = 0;
		t--;
		n-=8;
	}

	while (t>=0){
		c = a[i] >> (n);
		res[t] = c + b;
		b = a[i] << (8-n);
		i--;
		t--;
	}

	return;
}

/*res = a >> n (aritimetico)- - - - - - - - - - - - - -*/

void big_sar (BigInt res, BigInt a, int n){
	

	int c, ms, t = 15, i = 15, b = 0;

	ms = a[15]>>(7);

	while (n > 8){
		res[t] = ms;
		t--;
		n-=8;
	}

	while ( t > -1){
		c = a[i] >> (n);
		res[t] = c + b;
		b = a[i] << (8-n);
		i--;
		t--;
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


/* res = a * b - - - - - - - - - - - - - - - - - - */
void big_mul(BigInt res, BigInt a, BigInt b){

	int n = 0, i, t, m = 0, ext;
	BigInt c, d;

	big_val(res, 0);

	while (n<16){

		i = 0;
		ext = 0;
		while(i<16){

			t = (a[i]*b[n])+ext;
			ext = t/256;
			c[i] = t%256;
			i++;
		}

		big_shl(d,c,m);
		big_sum(res, res, d);
		m+=8;
		n++;
	}
	return;
}


