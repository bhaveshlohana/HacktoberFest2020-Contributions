#include<stdio.h>
int main(){
	int vet[9],i,j,div;
	for(i=0;i<9;i++){
		scanf("%d",&vet[i]); //preenchendo vetor
	}
	printf("\n\nNumeros primos:\n");
	for(i=0;i<9;i++){
		div=0;
		for(j=1;j<=vet[i];j++){
			if(vet[i]!= 1){
				if(vet[i]%j==0){ 	//Calculando se é primo caso nao seja o numero 1
					div++;
				}
			}else{
				div =2; //Se for o num 1 ja vai direto
			}
		
			
		}
		if(div==2){ //Se for primo só vai ter dois divosores (1 e o proprio numero)
			printf("num: %d\t pos: %d\n",vet[i],i);
		}
	}
	return 0;
}
