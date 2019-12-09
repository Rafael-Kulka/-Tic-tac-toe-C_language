#include<stdio.h>
#include<stdlib.h>
#include"funcoes.h"

void main(){

    char j1, j2, ganhador, nome_j1[30], nome_j2[30]; //j1=jogador 1, j2=jogador 2
    int t, a, b, nivel=0,chave = 1; //a contem a resposta do menu // b contem o nivel do bot
	int verifica, linha, coluna, posicao;
	char nomearq[11] = {'A','r','q','u','i','v','o','.', 'b', 'i', 'n'}; //nome do arquivo binário
	//a = menu(&nivel);
	int n=0;
	while(a!=3){
		a = menu(&nivel);
		escolha_simb(&j1, &j2);

		//leventamento dos dados para arquivo bin.

		//.
		if (chave == 1) ler_nome(nivel);

		chave = 0;

		inicializa_velha();

		dados.partida = numpart++;
		while (verifica_vitoria(&ganhador) == 0){

			do{
				escreve_velha();
				printf("%s, escolha uma posicao do tabuleiro: ", nj1);
				scanf("%i", &posicao);
				fflush(stdin);
				verifica_posicao(posicao, &linha, &coluna);
				system("cls");
				verifica = jogada_usuario(linha, coluna, j1);
				escreve_velha();

			}while(verifica!=2);

			if (verifica_vitoria(&ganhador) == 1){
            printf("\n\n O GANHADOR FOI: %c\n\n", ganhador);
			if (j1 == ganhador) pont1++;
			if(j2 == ganhador) pont2++;
            arquivo(nomearq, dados);
			arq_txt(j1, j2);
			dados = ler_arquivo(nomearq, numpart);
			system("pause");
			break;
            }

            if (verifica_velha(&ganhador) == 1){
            printf("\nDEU VELHA! NINGUEM GANHOU... ;-;\n");
            if (j1 == ganhador) pont1++;
			if(j2 == ganhador) pont2++;
			arquivo(nomearq, dados);
			arq_txt(j1, j2);
			dados = ler_arquivo(nomearq, numpart);
			system("pause");
            break;
            }

		if (a==2){
		 // bot
			jogada_computador(j2, nivel);
            escreve_velha();
        if (verifica_vitoria(&ganhador) == 1){
            printf("\n\n O GANHADOR FOI: %c\n\n", ganhador);
			if (j1 == ganhador) pont1++;
			if(j2 == ganhador) pont2++;
            dados.resultado = ganhador;
            arquivo(nomearq, dados);
			arq_txt(j1, j2);
			dados = ler_arquivo(nomearq, numpart);
			system("pause");
			break;
		}
		if (verifica_velha(&ganhador) == 1){
            printf("DEU VELHA! NINGUEM GANHOU... ;-;");
			if (j1 == ganhador) pont1++;
			if(j2 == ganhador) pont2++;
            dados.resultado = ganhador;
            arquivo(nomearq, dados);
			arq_txt(j1, j2);
			dados = ler_arquivo(nomearq, numpart);
			system("pause");
            break;
				}
		 //.

		}
		else {
			do{
				system("cls");
				escreve_velha();
				printf("%s, escolha uma posicao do tabuleiro: ", nj2);
				scanf("%i", &posicao);
				fflush(stdin);
				verifica_posicao(posicao, &linha, &coluna);
				system("cls");
				verifica = jogada_usuario(linha, coluna, j2);
				system("cls");
				escreve_velha();

			}while(verifica!=2);

		if (verifica_vitoria(&ganhador) == 1){
            printf("\n\n O GANHADOR FOI: %c\n\n", ganhador);
			if (j1 == ganhador) pont1++;
			if(j2 == ganhador) pont2++;
            dados.resultado = ganhador;
            arquivo(nomearq, dados);
			arq_txt(j1, j2);
			dados = ler_arquivo(nomearq, numpart);
			system("pause");
			break;
		}
		if (verifica_velha(&ganhador) == 1){
            printf("DEU VELHA! NINGUEM GANHOU... ;-;");
			if (j1 == ganhador) pont1++;
			if(j2 == ganhador) pont2++;
            dados.resultado = ganhador;
            arquivo(nomearq, dados);
			arq_txt(j1, j2);
			dados = ler_arquivo(nomearq, numpart);
			system("pause");
            break;
				}
			}
		}

	}
}
