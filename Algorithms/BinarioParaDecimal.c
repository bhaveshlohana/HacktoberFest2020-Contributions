#include <stdio.h>
#include <math.h>

int main(){
	char numBin[8];
	int i = 0, b = 0, decimal = 0;

	//le bits
	for(i = 0; i < 8; i++){
		scanf("%c", &numBin[i]);
	}

	printf("\n");
	for(i = 0; i < 8; i++){
		//compara se 'i' do tipo char é = 48 da tabela ascci que simboliza 0 da tabela ASCII
		if(numBin[i] == 48)
			b = 0;
		else
		//caso contrario espera-se 'i' = 1 que comparamos com 49 sendo 1 da tabela ASCII
			b = 1;
		//pow = elevado. como temo algo do tipo iiiiiiii usamos 7-1 pra corrigir
		decimal += b*pow(2,7-i);
	}
	printf("%d", decimal);

	return 0;
}

/*
 * binario para decimal
 * Transforma uma sequencia de char (bits) em valor decimal
*/
