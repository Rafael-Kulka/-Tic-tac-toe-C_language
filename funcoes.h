/*	Aqui conterá todas as funções do jogo da velha*/

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/////////////////////////Variaveis globais////////////////////////////////////////////////////////////////////////////
 char jogo[3][3];
 int verificador,pont1=0,pont2=0,lixeiro=0;
 char nj1[30], nj2[30]={'C', 'o', 'm', 'p', 'u', 't', 'a', 'd', 'o', 'r'};
 char arquivon[11] = {'A','r','q','u','i','v','o','.', 'b', 'i', 'n'};
 typedef struct {
        int partida;
        char jogvelha[3][3];
        char resultado;
    } jogos;
int numpart=0;
jogos dados;
jogos tabuleiro[100];
//////////////////////////////////prototypes/////////////////////////////////////////////////////////////////////

int menu();
void escolha_simb(char *jog1, char *jog2);
void inicializa_velha();
int verifica_vitoria(char *simvito);
void verifica_posicao(int posicao, int *linha, int *coluna);


/*Fun��es do BOT*/
void jogada_computador(char jog, int nivel);
int verifica_vitoria_bot(char sim);
int verifica_derrota(char sim, char sim_bot);
int ocuparposicao(char sim);
void bot_facil(char sim);
int bot_hard(char sim_p1, char sim);
int bot_medium(char sim_p1, char sim);
////////////////////////////////////////corpo das funcoes//////////////////////////////////////////////////////////

void verifica_posicao(int posicao, int *linha, int *coluna){
	switch (posicao)
	{
	case 1:
		*linha=0; *coluna=0;
		break;
	case 2:
		*linha=0; *coluna=1;
		break;
	case 3:
		*linha=0; *coluna=2;
		break;
	case 4:
		*linha=1; *coluna=0;
		break;
	case 5:
		*linha=1; *coluna=1;
		break;
	case 6:
		*linha=1; *coluna=2;
		break;
	case 7:
		*linha=2; *coluna=0;
		break;
	case 8:
		*linha=2; *coluna=1;
		break;
	case 9:
		*linha=2; *coluna=2;
		break;
	default:
		break;
	}
}

int menu(int *nivel){
   int opc;
   do{
   system("cls");
   printf("        Universidade Federal do Parana    \nCurso de Analise e Desenvolvimento de Sistemas\nAlunos Erik Borges Ribeiro e Rafael Andre Kulka\n");
   printf("\n-----------------Jogo da velha-----------------\nEscolha uma das opcoes abaixo:\n1)Jogar contra outro jogador.\n2)Jogar contra o computador.\n3)Sair do jogo.\n");
   printf("Opcao desejada: ");
   scanf("%i", &opc);
   fflush(stdin);
   } while(opc>3 || opc<1);
   if (opc == 3){
    system("cls");
	escreve(dados, arquivon);
    printf("\nObrigado por Jogar!\n");
	system("pause");
	exit(0);
   }
   if (opc==2){
   		do{
			system ("cls");
   			printf("escolha o Nivel: \n1) Facil\n2) Medio\n3) Dificil\n");
   			scanf("%i", nivel);
   			fflush(stdin);
		}while(*nivel>3 || *nivel<1);
   }
   return (opc);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void escolha_simb(char *jog1, char *jog2){
    fflush(stdin);
	system("cls");
	do {
    printf("Jogador 1 selecione 'X' ou 'O' \n");
    scanf("%c", jog1);

	fflush(stdin);} while (*jog1 != 'x' && *jog1 != 'o');
    *jog2 = *jog1=='x'?'o':'x';
    *jog2 = toupper(*jog2);
	*jog1 = toupper(*jog1);
	printf("jogador 2 ficou com: %c\n", *jog2);
	system("pause");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inicializa_velha(){
    int i, j, z=0;
    for (i=0; i<=2; i++){
        for (j=0; j<=2; j++){
        	z++;
			char c = z+'0';
			jogo[i][j] = c;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int jogada_usuario(int linha, int coluna, char jogador){


		if (linha>2 && linha<0 || coluna>2 && linha <0){
			return 1;
		}
		if (jogo[linha][coluna] != 'X' && jogo[linha][coluna] != 'O'){
			jogo[linha][coluna]=toupper(jogador);
			return 2;
		}
		else return 0;
	}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int verifica_vitoria(char *simvito){   //simvito=simbolo vitorioso(quem ganhou)
	int i, vitoria=0;
	for (i=0;i<3;i++){
		if (jogo[0][i] == jogo[1][i] && jogo[1][i] == jogo[2][i]){  //verifica linhas
			vitoria=1;
			*simvito=jogo[1][i];
			break;
		}
		if (jogo[i][0] == jogo[i][1] && jogo[i][1] == jogo[i][2]){  //verifica colunas
			vitoria=1;
			*simvito=jogo[i][1];
			break;
		}
	}
	if (jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2]){
		vitoria=1;
		*simvito=jogo[1][1];
	}

	if (jogo[0][2] == jogo [1][1] && jogo[1][1] == jogo[2][0]){
		vitoria=1;
		*simvito=jogo[1][1];

	}
	return vitoria;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int verifica_velha(char *simvito){
        if (jogo[0][0] != '1' && jogo[0][1] != '2' && jogo[0][2] != '3' && jogo[1][0] != '4' && jogo[1][1] != '5' && jogo[1][2] != '6' && jogo[2][0] != '7' && jogo[2][1] != '8' && jogo[2][2] != '9'){
            *simvito = 'V';
            return 1;
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void escreve_velha(){
    int i;
	system("cls");
    printf("\n");
    for(i=0;i<3;i++){
      printf(" %c | %c | %c\n",jogo[i][0],jogo[i][1],jogo[i][2]);
      if(i<2)
      printf("============\n");
    }
}

void ler_nome(int bot){
	printf("nome1=");
	fgets(nj1, 29, stdin);
	system("pause");
	nj1[strlen(nj1) - 1] = '\0';
	fflush(stdin);
	if (bot < 1){
		printf("nome2=");
		fgets(nj2, 29, stdin);
		nj2[strlen(nj2) - 1] = '\0';
		fflush(stdin);
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*	Aqui CONTERA AS FUNCOES DO BOT*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void jogada_computador(char jog, int nivel){
	switch (nivel)
	{
	case 1:
		bot_facil(jog);
		break;
	case 2:
		bot_medium((jog=='X'?'O':'X') ,jog);
		break;
	case 3:
		bot_hard((jog=='X'?'O':'X') ,jog);
		break;

}
}

////////////////////////////////////*/*/*/*/*/*/*/*/*/*/*///////////////////////////////////////////////////////
void bot_facil(char sim){
    int linha, coluna;
	while(1==1){
		linha=rand()%3;
    	coluna=rand()%3;
    	if (jogo[linha][coluna] != 'X' && jogo[linha][coluna] != 'O'){
			jogo[linha][coluna] = sim;
			break;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int bot_hard(char sim_p1, char sim){
	int a,b,c;
	a = verifica_vitoria_bot(sim);
	if (a==1){
		return 1;
	}

	b = verifica_derrota(sim_p1, sim);
	if (b==1){
		return 1;
	}
	c = ocuparposicao(sim);
	if (c==1){
		return 1;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int bot_medium(char sim_p1, char sim){
	if (verificador%2==0)
		bot_hard(sim_p1, sim);
	else
		bot_facil(sim);
	verificador = rand();
}

/////////////////////////fun��o de verifica vit�ria///////////////////////////////////////////////////////////////////
/*
verificar se o pr�ximo movimento do computador pode ganhar o jogo. Em caso afirmativo, executar este movimento. retorna 1 se sim e 0 sen�o
*/
int verifica_vitoria_bot(char sim){
	//verifica as linha:
	int i;
	for (i=0; i<3; i++){
		if (jogo[i][0]==jogo[i][1] && jogo[i][0]==sim && (jogo[i][2]!='X' && jogo[i][2]!='O')){
			jogo[i][2]=sim;
			return 1;
		}

		if (jogo[i][0]==jogo[i][2] && jogo[i][0]==sim && (jogo[i][1]!='X' && jogo[i][1]!='O')){
			jogo[i][1]=sim;
			return 1;
		}
		if (jogo[i][1]==jogo[i][2] && jogo[i][2]==sim && (jogo[i][0]!='X' && jogo[i][0]!='O')){
			jogo[i][0]=sim;

			return 1;
		}
	}

	for (i=0; i<3; i++){
		if (jogo[0][i] == jogo[1][i] && jogo[0][i]==sim && (jogo[2][i]!='X' && jogo[2][i]!='O')){
			jogo [2][i]=sim;
			return 1;

		}
		if (jogo[0][i] == jogo[2][i] && jogo[2][i]==sim && (jogo[1][i]!='X' && jogo[1][i]!='O')){
			jogo [1][i]=sim;
			return 1;
		}

		if (jogo[1][i] == jogo[2][i] && jogo[2][i]==sim && (jogo[0][i]!='X' && jogo[0][i]!='O')){
			jogo [0][i]=sim;
			return 1;
		}
	}
		//verifica diagonal principal
		if (jogo[0][0] == jogo[1][1] && jogo[0][0]==sim && (jogo[2][2]!='X' && jogo[2][2]!='O')){
			jogo[2][2] = sim;
			return 1;
		}
		if (jogo[0][0] == jogo[2][2] && jogo[0][0]==sim && (jogo[1][1]!='X' && jogo[1][1]!='O')){
			jogo[1][1] = sim;
			return 1;
		}
		if (jogo[2][2] == jogo[1][1] && jogo[1][1]==sim && (jogo[0][0]!='X' && jogo[0][0]!='O')){
			jogo[0][0] = sim;
			return 1;
		}

		// verifica diagonal secundaria
		if (jogo[0][2] == jogo[1][1] && jogo[0][2]==sim && (jogo[2][0]!='X' && jogo[2][0]!='O')){
			jogo[2][0] = sim;
			return 1;
		}
		if (jogo[0][2] == jogo[2][0] && jogo[2][0]==sim && (jogo[1][1]!='X' && jogo[1][1]!='O')){
			jogo[1][1] = sim;
			return 1;
		}
		if (jogo[2][0] == jogo[1][1] && jogo[2][0]==sim && (jogo[2][0]!='X' && jogo[2][0]!='O')){
			jogo[0][2] = sim;
			return 1;
		}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Verifica se h� algum movimento do jogador que possa faz�-lo ganhar o jogo. Se houver, o
computador bloqueia o jogador. */
//sim contem o simbolo do player sim_bot contem o simbolo do bot
int verifica_derrota(char sim, char sim_bot){
	//verifica as linha:
	int i;
	for (i=0; i<3; i++){
		if (jogo[i][0]==jogo[i][1] && jogo[i][0]==sim && (jogo[i][2]!='X' && jogo[i][2]!='O')) {
			jogo[i][2]=sim_bot;
			return 1;
		}

		if (jogo[i][0]==jogo[i][2] && jogo[i][0]==sim && (jogo[i][1]!='X' && jogo[i][1]!='O')){
			jogo[i][1]=sim_bot;
			return 1;
		}
		if (jogo[i][1]==jogo[i][2] && jogo[i][2]==sim && (jogo[i][0]!='X' && jogo[i][0]!='O')){
			jogo[i][0]=sim_bot;
			return 1;
		}
	}

	for (i=0; i<3; i++){
		if (jogo[0][i] == jogo[1][i] && jogo[0][i]==sim && (jogo[2][i]!='X' && jogo[2][i]!='O')){
			jogo [2][i]=sim_bot;

			return 1;

		}
		if (jogo[0][i] == jogo[2][i] && jogo[2][i]==sim && (jogo[1][i]!='X' && jogo[1][i]!='O')){
			jogo [1][i]=sim_bot;

			return 1;
		}

		if (jogo[1][i] == jogo[2][i] && jogo[2][i]==sim && (jogo[0][i]!='X' && jogo[0][i]!='O')){
			jogo [0][i]=sim_bot;

			return 1;
		}
	}
		//verifica diagonal principal
		if (jogo[0][0] == jogo[1][1] && jogo[0][0]==sim && (jogo[2][2]!='X' && jogo[2][2]!='O')){
			jogo[2][2] = sim_bot;
			return 1;
		}
		if (jogo[0][0] == jogo[2][2] && jogo[0][0]==sim && (jogo[1][1]!='X' && jogo[1][1]!='O')){
			jogo[1][1] = sim_bot;
			return 1;
		}
		if (jogo[2][2] == jogo[1][1] && jogo[1][1]==sim && (jogo[0][0]!='X' && jogo[0][0]!='O')){
			jogo[0][0] = sim_bot;
			return 1;
		}
		// verifica diagonal secundaria
		if (jogo[0][2] == jogo[1][1] && jogo[0][2]==sim && (jogo[2][0]!='X' && jogo[2][0]!='O')){
			jogo[2][0] = sim_bot;
			return 1;
		}
		if (jogo[0][2] == jogo[2][0] && jogo[2][0]==sim && (jogo[1][1]!='X' && jogo[1][1]!='O')){
			jogo[1][1] = sim_bot;
			return 1;
		}
		if (jogo[2][0] == jogo[1][1] && jogo[2][0]==sim && (jogo[0][2]!='X' && jogo[0][2]!='O')){
			jogo[0][2] = sim_bot;
			return 1;
		}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Verifica se h� espa�os livres nos cantos (posi��es 1, 3, 7, ou 9) e ocupa um deles. Retorna 1 quando sucesso*/
int ocuparposicao(char sim){
	if (jogo[1][1] == '5'){
		jogo[1][1]=sim;
		return 1;
	}

	if (jogo[0][0] == '1'){ //1
		jogo[0][0] = sim;
		return 1;
	}
	if (jogo[0][2] == '3'){ //3
		jogo[0][2] = sim;
		return 1;
	}
	if (jogo[2][0] == '7'){ //7
		jogo[2][0] = sim;
		return 1;
	}
	if (jogo[2][2] == '9'){ //9
		jogo[2][2] =sim;
		return 1;
	}

	if (jogo[1][0] == '4'){
		jogo[1][0] = sim;
		return 1;
	}
	if (jogo[0][1] == '2'){
		jogo[0][1] = sim;
		return 1;
	}
	if (jogo[1][2] == '6'){
		jogo[1][2] = sim;
		return 1;
	}
	if (jogo[2][1] == '8'){
		jogo[2][1] =sim;
		return 1;
	}
	return 0;
}

int tabuleiro_jogo(char ganhador){
	int x, y,c=0;
        for (x=0;x<3; x++){
            for (y=0; y<3; y++){
                if (jogo[x][y] != 'X' && jogo[x][y] != 'O')
                    tabuleiro[c].jogvelha[x][y] = ' ';
                else
                    tabuleiro[c].jogvelha[x][y] = jogo[x][y];
                    c++;
			}
        }
		tabuleiro[c].partida = numpart++;
		tabuleiro[c].resultado = ganhador;
}

int arquivo(char nomearq[], jogos dados){
    FILE *ftp = fopen(nomearq,"ab+");
	if(ftp == NULL){
		return 0;
		printf("NAO DEU PORRA!!!!!!!!");}
	fwrite(&dados, sizeof(dados), 1, ftp);
    fclose(ftp);
	return 1;
}

void arq_txt(char jo1, char jo2){
    FILE *arq_texto;
	arq_texto = fopen("arquivo_texto.txt", "a+");
    fprintf(arq_texto, "%s ; %c ; %s ; %c \n", nj1, jo1, nj2, jo2);
    fclose(arq_texto);
}

jogos ler_arquivo(char nomearq[], int pos){
    FILE *ftp_l = fopen(nomearq,"rb+");
    jogos dados_lido;
	fseek(ftp_l, sizeof(dados_lido) * pos, SEEK_SET);
	fread(&dados_lido, sizeof(dados_lido), 1, ftp_l);
    fclose(ftp_l);
	return dados_lido;
}

int escreve(jogos dados, char arquivon[]){
	int i,a=0;
	printf("\n");
	for(i=0;i<3;i++){
      printf(" %c | %c | %c\n",tabuleiro[a].jogvelha[i][0],tabuleiro[a].jogvelha[i][1],tabuleiro[a].jogvelha[i][2]);
      if(i<2) printf("============\n");
    }
	a++;
	printf("%s %d X %d %s", nj1,pont1, pont2, nj2);
	system("pause");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* FUNCOES_H*/
