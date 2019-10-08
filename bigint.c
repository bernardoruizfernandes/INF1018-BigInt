/* Bernardo Ruiz Fernandes 1711180 3WA */
/* Rafael Barbosa 1720736 3WA */

#include "bigint.h"

/* Atribuição (com extensão) ------------------------------------------------------- */

void dump (void *p, int n, BigInt res) {

	unsigned char *p1 = p;
	unsigned int a = 0;

	while (n--) {
		res[a] = *p1;						/* coloca o valor que estamos analisando em res */
		a++;
		p1++;
	}
}


void big_val (BigInt res, long val){

	unsigned int k = 8, u;					

	dump(&val, sizeof(val), res);			/* dump coloca os valores no bigInt */	

	u = val>>63;							/* salva em u o valor do ultimo bit */

	while (k<16){							/* 16 por que o BigInt tem 16 bytes */
		res[k] = u;							/* completa os 8 bytes com u para ff(negativos) ou 00(positivos) */
		k++;
	}

	return;
}


/* Operações de Deslocamento ------------------------------------------------------- */

/* res = a << n - - - - - - - - - - - - - - - - - -*/
void big_shl(BigInt res, BigInt a, int n){

	int c, b = 0, t = 0, i= 0;

	while(n>8){								/* completa com zero de 8 em 8 bytes */
		res[t]= 0;
		t++;
		n-=8;								/* desconta as casas que ja foram colocadas */
	}

	while(t<16){								
		c = a[i]<<(n);						/* c guarda os n bits que vao ser delocados*/
		res[t] = c + b;						/* soma os bits de c e b (sobra da interacao anterior) */
		b = a[i]>>(8-n);					/* pego a sobra de a[i] para a proxima interacao */
		i++;
		t++;
	}

	return;
}

/*res = a >> n (logico)- - - - - - - - - - - - - -*/

void big_shr (BigInt res, BigInt a, int n){
	
	int c, b = 0, t = 15, i = 15;

	while (n > 8){							/* completa com zero de 8 em 8 bytes */
		res[t] = 0;
		t--;
		n-=8;								/* desconta as casas que ja foram colocadas */
	}

	while (t>=0){
		c = a[i] >> (n);					/* c guarda os n bits que vao ser delocados*/
		res[t] = c + b;						/* soma os bits de c e b (sobra da interacao anterior) */
		b = a[i] << (8-n);					/* pego a sobra de a[i] para a proxima interacao */
		i--;
		t--;
	}

	return;
}

/*res = a >> n (aritimetico)- - - - - - - - - - - - - -*/

void big_sar (BigInt res, BigInt a, int n){
	

	int c, bsig, ms = 0, t = 15, i = 15, b = 0;	/* ms iniciado como 00 */

	bsig = a[15]>>7;						/* shift ate o ultimo bit para saber qual o mais significativo */
	if (bsig==1)							/* se o mais significativo for 1 completa com FF */
		ms = 0xFF;

	while (n > 8){							/* completa com ms de 8 em 8 bytes */
		res[t] = ms;
		t--;
		n-=8;								/* desconta as casas que ja foram colocadas */
	}

	b = ms<<(8-n);
	
	while ( t > -1){
		c = a[i] >> (n);					/* c guarda os n bits que vao ser delocados*/
		res[t] = c + b;						/* soma os bits de c e b (sobra da interacao anterior) */
		b = a[i] << (8-n);					/* pego a sobra de a[i] para a proxima interacao */
		i--;
		t--;
	}

	return;
}




/* Operações Aritméticas ----------------------------------------------------------- */


/* res = a + b - - - - - - - - - - - - - - - - - - */
void big_sum(BigInt res, BigInt a, BigInt b){

	unsigned int s, ext = 0, n = 0;			/* ext inicia como 0 */

	while (n<16){
		s = a[n] + b[n] + ext;				/* soma os bytes de a, b e o extra (interacao anterior) */
		res[n] = s%256;						
		ext = (s/256);						/* pego o extra da interacao para a proxima */
		n++;
	}

	return;
}	

	

/* res = -a  - - - - - - - - - - - - - - - - - - - */
void big_comp2(BigInt res, BigInt a){

	unsigned int n = 0;
	BigInt num_1, invet;

	big_val(num_1,1);						/* cria o bigInt com valor 1 */
	
	while (n<16){
		invet[n] = ~a[n];					/* faz o complemento de todos os numeros */ 
		n++;
	}

	big_sum(res, invet, num_1);				/* soma 1 no invertido */

	return ;
}


/* res = a - b - - - - - - - - - - - - - - - - - - */
void big_sub(BigInt res, BigInt a, BigInt b){

	BigInt b_neg;

	big_comp2(b_neg,b);						/* faz o compara a 2 do segundo numero */
	big_sum(res, a, b_neg);					/* soma o a com o b invertido | a-b = a+(-b)*/

	return;
}


/* res = a * b - - - - - - - - - - - - - - - - - - */
void big_mul(BigInt res, BigInt a, BigInt b){

	int n = 0, i, t, m = 0, ext;			
	BigInt c, d;							/* bigInts auxiliares */

	big_val(res, 0);						/* cria res com valor 0 */

	while (n<16){							/* percorer o 2º bigInt */

		i = 0;									 
		ext = 0;							/* extra e zero para cada nova conta */
		while(i<16){						/* percorer o 1º bigInt */

			t = (a[i]*b[n])+ext;			/* multiplica o a e o b e soma com o extra anterior */
			ext = t/256;					/* o extra e o resto da multiplicacao */
			c[i] = t%256;					/* salva no bigInt auxiliar */
			i++;
		}

		big_shl(d,c,m);						/* shift left para 'multiplicar por 10' cada multiplicacao */
		big_sum(res, res, d);				/* soma o anterior com a nova multiplicacao */
		m+=8;								/* adiciona 8 para o proximo shift */
		n++;
	}
	return;
}


