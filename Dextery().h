/* //-- Favor, copie as linas abaixo dentro do coment�rio para rapidamente criar um arquivo para executar umt este desta biblioteca

#include<stdio.h>
#include"Dextery().h"

int main(){
	WakeDexter();
	return 0;
}

*/

// abixo encontra-se o print para inser��o de observa��es de novos m�dulos de fun��es (linhas 15 � 31)

/*
Resumo de fun��es apresentadas abaixo:

 ----> Fun��es Principais:
 
 
 

 ----> Fun��es Auxiliares:
 
 
 

*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//Abaixo ser�o inseridas as configura��es para os defines necess�rios



// Acima ser�o inseridas as configura��es para os defines necess�rios
//------------------------------------------------------------------------
//------------------------------------------------------------------------

/*
Resumo de fun��es apresentadas abaixo: Fun��es Universais Dextery()

 ----> Fun��es Principais:
 SetConfigs() = Seta configura��es iniciais, tais como SetPurtugues
 CreateTxtFile = Cria um arquivo de texto com nome personaliz�vel

 ----> Fun��es Auxiliares:
  SetPurtuguese() = Configura op��es em portugu�s para Dextery()
 
*/

void SetPortuguese(){
	setlocale(LC_ALL, "Portuguese");
	system("pause");
}

void SetConfigs(){ 
	SetPortuguese();
}

void Warning(){
	printf("\n\n\n----------  POR FAVOR DIGITE UMA OP��O V�LIDA DO MENU  ----------\n\n\n");
}

void CreateTxTFile() {
	char Arqv_Name[50];
    printf("Digite o nome do arquivo: ");
    fflush(stdin);
    fgets(Arqv_Name, sizeof(Arqv_Name), stdin);
    Arqv_Name[strcspn(Arqv_Name, "\n")] = '\0'; // Para remover nova linha "\n" no nome do arquivo
    
    char filename_dottxt[54];
    snprintf(filename_dottxt, sizeof(filename_dottxt), "%s.txt", Arqv_Name); // Para adicionar ".txt" ao nome personalizado

    FILE* Arqv = fopen(filename_dottxt, "w");
    if (Arqv == NULL) {
        printf("\nErro ao criar arquivo\n");
    } else {
        fclose(Arqv);
    }
}

/*
Resumo de fun��es apresentadas abaixo: Manipul��o de datas

 ----> Fun��es Principais:
 
Datetoday() = Retorna em int o n�mero que representa o dia atual
Getdate() = Permite que o usu�rioo insira uma data e a retorne em valor int
Betweendates() = Retorna em int o n�mero que representa a diferen�a entre duas datas inseridas
Showdate() = Imprime uma data em int, no formato dd/mm/aaaa
Printbetween() = Imprime a difern�a entre duas datas em int, mostrando dias, semanas, meses, anos, decadas e s�culos entre elas

 ----> Fun��es Auxiliares:

int check_leap_year(int year)
int check_valid_month(int month)
int check_valid_day(int day, int month, int ly)

*/

/*
---------------------------------------------------------------------------------------------------------------------------------------
*/
int Datetoday() {
    time_t agora = time(NULL);
    struct tm *datehour = localtime(&agora);

    int ano = datehour->tm_year + 1900;
    int mes = datehour->tm_mon + 1;
    int dia = datehour->tm_mday;

    int dateinint = (ano * 10000) + (mes * 100) + dia;

    return dateinint;
}

int check_leap_year(int year){
    if(year % 4 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int check_valid_month(int month){
    if ((month<1)||(month>12)){
        return 0;
    }else{
        return 1;
    }
}

int check_valid_day(int day, int month, int ly){
    int x;
    switch(month){
        case 1:
            if((day==0)||(day>31)){
                x = 0;
            }else{
                x = 1;
            }
            break;
        case 2:
            if((day != 0)&&(((ly == 1)&&(day<30))||((ly == 0)&&(day<29)))){
                x = 1;
            }else{
                x = 0;
            }
            break;
        case 3:
            if((day==0)||(day>31)){
                x = 0;
            }else{
                x = 1;
            }
            break;
        case 4:
            if((day==0)||(day>30)){
                x = 0;
            }else{
                x = 1;
            }
            break;
        case 5:
            if((day==0)||(day>31)){
                x = 0;
            }else{
                x = 1;
            }
            break;
        case 6:
            if((day==0)||(day>30)){
                x = 0;
            }else{
                x = 1;
            }
            break;
        case 7:
            if((day==0)||(day>31)){
                x = 0;
            }else{
                x = 1;
            }
            break;
        case 8:
            if((day==0)||(day>31)){
                x = 0;
            }else{
                x = 1;
            }
            break;
        case 9:
            if((day==0)||(day>30)){
                x = 0;
            }else{
                x = 1;
            }
            break;
        case 10:
            if((day==0)||(day>31)){
                x = 0;
            }else{
                x = 1;
            }
            break;
        case 11:
            if((day==0)||(day>30)){
                x = 0;
            }else{
                x = 1;
            }
            break;
        case 12:
            if((day==0)||(day>31)){
                x = 0;
            }else{
                x = 1;
            }
            break;
        default:
            printf("\nErro de data\n");
    }
    return x;
}

int Getdate() {
    int day, month, year;
    int valid_day, valid_month, leap_year;

    do {
        printf("Digite o dia: ");
        scanf("%d", &day);

        printf("Digite o m�s: ");
        scanf("%d", &month);

        printf("Digite o ano: ");
        scanf("%d", &year);

        leap_year = check_leap_year(year);
        valid_month = check_valid_month(month);
        valid_day = check_valid_day(day, month, leap_year);

        if ((valid_day == 0) || (valid_month == 0)) {
            printf("\n\nFavor, insira uma data v�lida\n\n");
            if ((day == 29) && (month == 2) && (leap_year == 0)) {
                printf("Neste ano n�o houve ano bissexto");
            }
        }

    } while ((valid_day == 0) && (valid_month == 0));

    int date_int = (year * 10000) + (month * 100) + day;

    return date_int;
}

int Betweendates() {
    printf("\nDeseja utilizar a refer�ncia da data de hoje como uma das datas?\n1 - Sim\n2 - N�o\n:");
    int op, date_int2;
    scanf("%d", &op);
    int date_int1 = Getdate();
    if (op == 2) {
        date_int2 = Getdate();
    } else {
        date_int2 = Datetoday();
    }

    struct tm time1 = { 0 };
    struct tm time2 = { 0 };
    time1.tm_year = date_int1 / 10000 - 1900;
    time1.tm_mon = (date_int1 / 100) % 100 - 1;
    time1.tm_mday = date_int1 % 100;
    time2.tm_year = date_int2 / 10000 - 1900;
    time2.tm_mon = (date_int2 / 100) % 100 - 1;
    time2.tm_mday = date_int2 % 100;

    time_t time1_seconds = mktime(&time1);
    time_t time2_seconds = mktime(&time2);

    double seconds_diff = difftime(time2_seconds, time1_seconds);
    int days_diff = seconds_diff / (60 * 60 * 24);

    return days_diff;
}

void Showdate(int dateinint) {
	int dia, mes, ano;
	if(dateinint == Datetoday()){
		printf("\nHoje � dia: ");
	}else{printf("\n");}
    dia = dateinint % 100;
    mes = (dateinint / 100) % 100;
    ano = dateinint / 10000;

    printf("%02d/%02d/%04d\n", dia, mes, ano);
}

void Printbetween(int day){
	float week, year, month, decade, century;
	week = day / 7;
	year = day / 365.25;
	month = year * 12;
	decade = year / 10;
	century = decade / 10;
	printf("\nA diferen�a de datas entre os dias selecionados equivalem a");
	if(day<0){
		printf(" seguinte futura data:\n");
	}else{
		printf(" seguinte data passada:\n");
	}
	printf("\n %d dias;\n %.3f semanas;\n %.3f meses;\n %.3f anos;\n %.3f d�cadas\n %.4f s�culos",day,week, month, year, decade, century);
}
//---------------------------------------------------------------------------------------------------------------------------------------


/*
Resumo de fun��es apresentadas abaixo: Verificar Tri�ngulos ----------> Verificadas, funcionando corretamente

 ----> Fun��es Principais:
 checktriangle() = Executa as fun��es auxiliares dos tri�ngulos
 
 ----> Fun��es Auxiliares:
 TypeTriangleValue = Insere um valor de lado do triangulo a ser inserido
 Modulo_Dif = Retorna um valor de diferen�a float em m�dulo
 Check_If_Triangle = Checa se 3 lados float inseridos formam um tri�ngulo ou n�o
 checkEquilatero checkIsosceles checkEscaleno = Verifica qual triangulo � formado ao inserir seus lados, caso seja
 Triangle_Area_Perimeter = Calcula a �rea de um triangulo e sue per�metro
*/

//---------------------------------------------------------------------------------------------------------------------------------------

float TypeTriangleValue(int a){
	float b;
	printf("\nDigite o valor do %d lado do triangulo: ",a);
	scanf("%f",&b);
	return b;
}

float Modulo_Dif(float a, float b){
	float c;
	c = a - b;
	if(c<0){
		c = -c;
	}
	return c;
}

int Check_If_Triangle(float a, float b, float c){
	int d = 0;
	if(((Modulo_Dif(b,c)<a)&&(a< b + c))||((Modulo_Dif(a,c)<b)&&(b< a + c))||((Modulo_Dif(a,b)<c)&&(c< b + a))){
		d = 1;
		printf("\nOs valores inseridos formam um triangulo do tipo ");
		return 1;
	}else{
		d = 0;
		printf("\nOs valores inseridos nao formam um triangulo\n");
		return 0;
	}
}

void checkEquilatero(float a,float b,float c){
	if((a == b)&&(b == c)&&(c == a)){
		printf("equilatero");
	}
}

void checkIsosceles(float a,float b,float c){
	if(((a == b)&&(a !=c))||((a == c)&&(b !=c))||((c == b)&&(a !=c))){
		printf("isosceles");
	}
}

void checkEscaleno(float a,float b,float c){
	if((a != b)&&(a != c)&&(b != c)){
		printf("escaleno");
	}
}

float Triangle_Area_Perimeter(float a,float b,float c,float p){
	float area;
	if((a == b)&&(b == c)&&(c == a)){
		area = (pow(a,2)*pow(3,(1/2)))/4;
		return area;
	}
	if(((a == b)&&(a !=c))||((a == c)&&(b !=c))||((c == b)&&(a !=c))){
		area = (c/2)*((pow(b,2))-((pow(c,2))/4));
		return area;
	}
	if((a != b)&&(a != c)&&(b != c)){
		p = p/2;
		area = pow((p*(p-a)*(p-b)*(p-c)),(1/2));
		return area;
	}
}

float checktriangle(){
	float area;
	float a = TypeTriangleValue(1);
	float b = TypeTriangleValue(2);
	float c = TypeTriangleValue(3);
	if (Check_If_Triangle(a,b,c) == 1){
		checkEquilatero(a,b,c);
		checkIsosceles(a,b,c);
		checkEscaleno(a,b,c);
		float p = a+b+c;
		area = Triangle_Area_Perimeter(a,b,c,p);
		printf("\n\nO perimetro e de: %.2f e area de %.3f u^2 (unidades quadradas)",p, area);
		
	}else{
		Check_If_Triangle(a,b,c);
	}
}


/*
Resumo de fun��es apresentadas abaixo: MANIPULA��ES COM TEMPERATURA.

 ----> Fun��es Principais:
 	CalculateTemperature() = Calcula temperaturas;

 ----> Fun��es Auxiliares:
 	ShowTemperature(float k, float c, float f) = imprime as temperaturas em suas unidades k, c, f
 	Asktemperature(int y) = Pergunta uma temperatura (y=1), ou uma segunda se y = 2
 	TempCovert(int off, float temp,int saveconvert, int sigma){ = quatro fun��es em uma, para converter temperaturas
 	AskOperation(float temp1,float temp2, int calc1);

*/

void ShowTemperature(float k, float c, float f){
	printf("\n A temperatura em Celcius � de: %.3f",c);
	printf("\n A temperatura em Fahrenheit � de: %.3f",f);
	printf("\n A temperatura em Kelvin � de: %.3f",k);
}

int Asktemperature(int y){
	int op1;
	if( y == 1){
		printf("\n\nQual ser� a temperatura a ser inserida?\n1- Celcius\n2- Fahrenheit\n3- Kelvin\n:");
		scanf("%d",&op1);
	}else if( y == 2){
		printf("\n\nQual ser� a segunda temperatura a ser inserida?\n1- Celcius\n2- Fahrenheit\n3- Kelvin\n:");
		scanf("%d",&op1);
	}
	return op1;
}

float TempCovert(int off, float temp,int saveconvert, int sigma){ // quatro fun��es em uma, para converter temperaturas
/*

off = se igual a zero, pergunta ao usu�rio qual temperatura quer converter em todas, se n�o, se Ser� utilizado a vari�vel da fun��o, para inserir uma vari�vel temp
	  retornando, assim, uma vari�vel float de acordo com a unidade desejada em saveconvert
	off = 1 -> Insere temp como Celsius
	off = 2 -> Insere temp como Fahrenheit
	off = 3 -> Insere temp como Kelvin
	
Temp = Temperatura que deve ser inserida para que possa converter a unidade off em unidade saveconvert, e retorn�-la como um valor
	
saveconvert = utilizado para fazer que a fun��o salve algum dos valores convertidos como uma vari�vel de retorno float, o returnoperation
	saveconvert = 1 �> Retorna valor em Celsius
	saveconvert = 1 �> Retorna valor em Fahrenheit
	saveconvert = 1 �> Retorna valor em Kelvin
	
Sigma � apeans uma vari�vel para fazer, de maneira recursiva, a fun��o AskTemperature abaixo poder al�m de inserir uma equa��o, tamb�m poder chamar o conversor novamente.
	Utilize-a como padr�o 0
*/
	int op1;	
	float k,c,f,kx,cx,fx, returnoperation = 0;
	if(off == 0){
		op1 = Asktemperature(1);
	}else{
		op1 = off;
	}
	switch(op1){
		case 1:
			if(off == 0){
				printf("\nCelcius: ");
				scanf("%f",&c);
			}else{
				c = temp;
			}
			kx = c +273;
			fx = (c*1.8)+32;
			if((off == 0)||(off == 5)||(sigma != 0)){ShowTemperature(kx,c,fx);}
			else if(saveconvert == 1){
				returnoperation = c;
			}else if(saveconvert == 2){
				returnoperation = fx;
			}else if(saveconvert == 3){
				returnoperation = kx;				
			}
			getchar();
		break;
		case 2:
			if(off == 0){
				printf("\nFahrenheit: ");
				scanf("%f",&f);
			}else{
				f = temp;
			}
			kx = (((f-32)/9)*5)+273;
			cx = ((f-32)/1.8);
			if((off == 0)||(off == 5)||(sigma != 0)){ShowTemperature(kx,cx,f);}
			else if(saveconvert == 1){
				returnoperation = cx;
			}else if(saveconvert == 2){
				returnoperation = f;
			}else if(saveconvert == 3){
				returnoperation = kx;				
			}
			getchar();
		break;
		
		case 3:
			if(off == 0){
				printf("\nKelvin: ");
				scanf("%f",&k);
			}else{
				k = temp;
			}
			fx = (((k-273)/5)*9)+32;
			cx = k -273;
			if((off == 0)||(off == 5)||(sigma != 0)){ShowTemperature(k,cx,fx);}
			else if(saveconvert == 1){
				returnoperation = cx;
			}else if(saveconvert == 2){
				returnoperation = fx;
			}else if(saveconvert == 3){
				returnoperation = k;				
			}
			getchar();
		break;
		
		default:
			Warning();
	}
	if(sigma == 0){
		return returnoperation;
	}else{
		TempCovert(sigma,temp,0,0);
	}
}
float AskOperation(float temp1,float temp2, int calc1){
	float result;
	int op;
	printf("\nDeseja realizar qual opera��o dentre os valores de temperatura 1 (%.3f) e temperatura 2 (%.3f)",temp1,temp2);
	printf("\n1-	T1 + T2\n2-	T1 - T2\n3-	T2 * T2\n4-	T1 / T2\n:");
	scanf("%d",&op);
	switch(op){
		case 1:
			result = temp1 + temp2;
			break;
		case 2:
			result = temp1 - temp2;
			break;
		case 3:
			result = temp1 * temp2;
			break;
		case 4:
			result = temp1 / temp2;
			break;
		default:
			Warning();	
	}
	printf("\nO resultado �: %.3f ",result);
	if(calc1 == 1){
		printf("Celcius\n");
	}else if(calc1 == 2){
		printf("nFahrenheit\n");
	}else if(calc1 == 3){
		printf("Kelvin\n");
	}
	return result;
}
void CalculateTemperatures(){
	float t1,t2;
	int op;
	float c, f, k,result;
	int calc1,calc2;
	calc1 = Asktemperature(1);
	printf("\nInsira o valor: ");
	scanf("%f",&t1);
	calc2 = Asktemperature(2);
	printf("\nInsira o valor: ");
	scanf("%f",&t2);
	getchar();
	if( calc1 != calc2){
		if(calc1 == 1){ // C
			if(calc2 == 2){
				t2 = TempCovert(2,t2,1,0);
			}
			if(calc2 == 3){
				t2 = TempCovert(3, t2,1,0);
			}
		}
		if(calc1 == 2){ // F
			if(calc2 == 1){
				t2 = TempCovert(1, t2,2,0);
			}
			if(calc2 == 3){
				t2 = TempCovert(3, t2,2,0);
			}
		}
		if(calc1 == 3){ // K
			if(calc2 == 2){
				t2 = TempCovert(2, t2,3,0);
			}
			if(calc2 == 1){
				t2 = TempCovert(1, t2,3,0);
			}
		}
	}
	result = AskOperation(t1,t2,calc1);
	printf("\nDeseja converter este valor entre outras unidades?\n1-Sim\n2-N�o\nR_: ");
	scanf("%d",&op);
	if(op == 1){
		TempCovert(calc1,result,0,calc1);
	}
	
}

/*
Resumo de fun��es apresentadas abaixo: Jogo HangedMan();

 ----> Fun��es Principais:
 
 
 

 ----> Fun��es Auxiliares:
 
 
 

*/

#define MAX_PALAVRAS 1000
#define MAX_TAMANHO_PALAVRA 50

int CarregarPalavras(char palavras[][MAX_TAMANHO_PALAVRA]) {
    FILE* arquivo = fopen("hangwords.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de palavras.\n");
        return 0;
    }

    int indice = 0;
    char linha[MAX_TAMANHO_PALAVRA];

    while (fgets(linha, MAX_TAMANHO_PALAVRA, arquivo) != NULL) {
        // Remover a quebra de linha do final da linha
        linha[strcspn(linha, "\n")] = '\0';

        strncpy(palavras[indice], linha, MAX_TAMANHO_PALAVRA);
        indice++;
    }

    fclose(arquivo);
    return indice;
}

void CarregarDicas(char dicas[][MAX_TAMANHO_PALAVRA]) {
    FILE* arquivo = fopen("passwordtip.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de dicas.\n");
        return;
    }

    int indice = 0;
    char linha[MAX_TAMANHO_PALAVRA];

    while (fgets(linha, MAX_TAMANHO_PALAVRA, arquivo) != NULL) {
        // Remover a quebra de linha do final da linha
        linha[strcspn(linha, "\n")] = '\0';

        strncpy(dicas[indice], linha, MAX_TAMANHO_PALAVRA);
        indice++;
    }

    fclose(arquivo);
}

void HangedMan() {
	int ImmortalOp;
	int vidas;
    char palavras[MAX_PALAVRAS][MAX_TAMANHO_PALAVRA];
    char dicas[MAX_PALAVRAS][MAX_TAMANHO_PALAVRA];

    int numPalavras = CarregarPalavras(palavras);
    CarregarDicas(dicas);

    // Gera��o de n�mero aleat�rio para escolher a palavra
    srand(time(NULL));
    int indicePalavra = rand() % numPalavras;
    char palavraEscolhida[MAX_TAMANHO_PALAVRA];
    strncpy(palavraEscolhida, palavras[indicePalavra], MAX_TAMANHO_PALAVRA);

    int numTentativas = strlen(palavraEscolhida) + 5;
    printf("\nDeseja jogar no modo treinamento?\n1- Sim\n2- N�o\n");
    scanf("%d",&ImmortalOp);
    if(ImmortalOp == 1){
    	vidas = 1000;
	}else{
		vidas = numTentativas;
	}
     
    // Letras ocultas
    char letrasOcultas[MAX_TAMANHO_PALAVRA];
    for (int i = 0; i < strlen(palavraEscolhida); i++) {
        letrasOcultas[i] = '+';
    }
    letrasOcultas[strlen(palavraEscolhida)] = '\0';

    // Hist�rico de letras digitadas
    char letrasUtilizadas[MAX_TAMANHO_PALAVRA];
    letrasUtilizadas[0] = '\0';

    printf("Bem-vindo ao jogo da forca!\n");

    while (vidas > 0 && strcmp(letrasOcultas, palavraEscolhida) != 0) {
        printf("\nVidas: %d\n", vidas);
                printf("Letras ocultas: %s\n", letrasOcultas);
        printf("Dica: %s\n", dicas[indicePalavra]);
        printf("Hist�rico de letras digitadas: %s\n", letrasUtilizadas);
        printf("N� Letras: %d\n", (int)strlen(palavraEscolhida));

        char letra;
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        // Limpar o buffer do teclado
        while (getchar() != '\n')
            continue;

        // Verificar se a letra j� foi utilizada
        if (strchr(letrasUtilizadas, letra) != NULL) {
            printf("Voc� j� digitou essa letra. Tente novamente.\n");
            continue;
        }

        // Adicionar a letra ao hist�rico de letras digitadas
        int tamanhoHistorico = strlen(letrasUtilizadas);
        letrasUtilizadas[tamanhoHistorico] = letra;
        letrasUtilizadas[tamanhoHistorico + 1] = '\0';

        // Verificar se a letra est� presente na palavra
        int letraEncontrada = 0;
        for (int i = 0; i < strlen(palavraEscolhida); i++) {
            if (palavraEscolhida[i] == letra) {
                letrasOcultas[i] = letra;
                letraEncontrada = 1;
            }
        }

        if (letraEncontrada) {
            printf("Letra correta!\n");
        } else {
            printf("Letra incorreta!\n");
            vidas--;
        }
    }

    if (vidas == 0) {
        printf("\nVoc� perdeu! A palavra era: %s\n", palavraEscolhida);
    } else {
        printf("\nParab�ns! Voc� venceu! A palavra era: %s\n", palavraEscolhida);
    }
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void createHangedManFiles() {
    FILE *hangWordsFile = fopen("hangwords.txt", "a");
    FILE *passwordTipFile = fopen("passwordtip.txt", "a");

    if (hangWordsFile == NULL || passwordTipFile == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        exit(1);
    }

    fclose(hangWordsFile);
    fclose(passwordTipFile);
}

void writeWordsToFile() {
    char hangWord[100];
    char passwordTip[100];
    char resposta[5];

    FILE *hangWordsFile = fopen("hangwords.txt", "a");
    FILE *passwordTipFile = fopen("passwordtip.txt", "a");

    if (hangWordsFile == NULL || passwordTipFile == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        exit(1);
    }

    do {
        printf("Digite a palavra para o arquivo hangwords.txt: ");
        getchar();
        fgets(hangWord, sizeof(hangWord), stdin);
        hangWord[strcspn(hangWord, "\n")] = '\0'; // Remover o caractere de nova linha

        printf("Digite a palavra para o arquivo passwordtip.txt: ");
        fgets(passwordTip, sizeof(passwordTip), stdin);
        passwordTip[strcspn(passwordTip, "\n")] = '\0'; // Remover o caractere de nova linha

        fprintf(hangWordsFile, "%s\n", hangWord);
        fprintf(passwordTipFile, "%s\n", passwordTip);

        printf("Palavras adicionadas aos arquivos com sucesso.\n");

        printf("Deseja adicionar outra palavra? (Sim/Nao): ");
        scanf("%s", resposta);
    } while (strcmp(resposta, "Sim") == 0 || strcmp(resposta, "sim") == 0);

    fclose(hangWordsFile);
    fclose(passwordTipFile);
}


void PlayHangedMan() {
    int option;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar palavras ao jogo\n");
        printf("2. Jogar o jogo da forca\n");
        printf("3. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                createHangedManFiles();
                writeWordsToFile();
                break;
            case 2:
                HangedMan();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (option != 3);
}




//---------------------------------------------------------------------------------------------------------------------------------------
/*
��___��������_��_��___���___�������_��������������_��_���/�/����\�\���
�/�__|�__�_�|�||�||���\�|�__|__�__|�|_��___��_�_�|�||�|�|�|������|�|��
|�(__�/�_`�||�||�||�|)�||�_|�\�\�/|��_|/�-_)|�'_|�\_.�|�|�|������|�|��
�\___|\__/_||_||_||___/�|___|/_\_\�\__|\___||_|���|__/���\_\_���/_/���

*/
//---------------------------------------------------------------------------------------------------------------------------------------


/*
		FUN��O MENU DEXTERY. FUN��O PRINCIPAL DA BIBLIOTECA
*/ 

int CallDextery(){ // EXECUTAR MENU DEXTERY
	int stop = 1, substop = 1, understop = 1;
	int op = 1, subop = 1, underop = 1;
	SetPortuguese();
	do{
		printf("\nBEM VINDO AO DEXTERY\n\nFavor, escolha uma op��o v�lida no menu abaixo:\n");
		printf("\n 0- Sair");
		printf("\n 1- Configura��es Iniciais Dextery");
		printf("\n 2- Realizar opera��es Matem�ticas");
		printf("\n 3- Manipular arquivos");
		printf("\n 4- Menu de jogos");
		printf("\n:");
		//printf("\n x- \n"); // Para novas fun��es
		scanf("%d",&op);
		switch(op){
			case 0:
				stop = 0;
			break;
			
			case 1:
				do{
				printf("\n\nAgora voc� esta no submenu de Configura��es Iniciais Dextery, favor, insira qual das aplica��es dispon�veis voc� deseja executar:\n");
				printf("\n\n0- Voltar;\n1- Configura��es Gerais;\n2- Configurar Idioma Portugu�s (PT)");
				printf("\n:");
				scanf("%d",&subop);
				switch(subop){
					
					case 0:
						substop = 0;
					break;
					
					case 1: // Configura��es Gerais
						SetConfigs();	
					break;
					
					case 2: // Configurar Idioma Portugu�s (PT)
						SetPortuguese();
					break;
					
					default:
						Warning();	
					}
				}while(subop != 0);
				break;
			
			case 2:
				do{
				printf("\n\nAgora voc� esta no submenu de Realizar opera��es Matem�ticas, favor, insira qual das aplica��es dispon�veis voc� deseja executar:\n");
				printf("\n\n0- Voltar;\n1- Checagem de tri�ngulos;\n2- Opera��es com datas;\n3- Calcular Temperaturas;");
				printf("\n:");
				scanf("%d",&subop);
				switch(subop){
					case 0:
						substop = 0;
					break;
					
					case 1: // Checa tr�s inputs para ver se s�o tri�gulos, quais, e sua area e per�metro
						checktriangle();
						
					break;
					
					case 2: // Para sub-sub manipula��o de datas
						do{
							printf("\n\nAgora voc� esta no submenu de manipula��o de datas, favor, insira qual das aplica��es dispon�veis voc� deseja executar:\n");
							printf("\n\n0- Voltar;\n1- Mostrar dia atual;\n2- Calcular datas;\n:");
							scanf("%d",&underop);
							switch(underop){
								case 0:
									understop = 0;
									
								case 1: // Mostra o dia atual
									Showdate(Datetoday());	
								break;
									
								case 2: // Calcular entre datas
									Printbetween(Betweendates());
								break;
								
								default:
									Warning();
							}
						}while(understop !=0);
					break;
					
					case 3: // Submenu Temperaturas
						do{
							printf("\n\nAgora voc� esta no submenu de Opera��es com Temperaturas, favor, insira qual das aplica��es dispon�veis voc� deseja executar:\n");
							printf("\n\n0- Voltar;\n1- Opera��es aritm�ticas entre duas temperaturas;\n2- Converter uma temperatura em todas unidades de medida;\n:");
							scanf("%d",&underop);
							switch(underop){
								case 0:
									understop = 0;
									
								case 1: 
									CalculateTemperatures();
									getchar();
									fflush(stdin);
								break;
								
								case 2:
									TempCovert(0,0,0,0);
									getchar();
									fflush(stdin);
								break;
								
								default:
									Warning();
							}
						}while(understop !=0);
					break;

					default:
						Warning();	
				}
				}while(subop != 0);
			
			case 3:
				do{
				printf("\n\nAgora voc� esta no submenu de Manipula��o de Arquivos, favor, insira qual das aplica��es dispon�veis voc� deseja executar:\n");
				printf("\n\n0- Voltar;\n1- Criar arquivos.txt;");
				printf("\n:");
				scanf("%d",&subop);
				switch(subop){
					case 0:
						substop = 0;
					break;
					
					case 1: // Criar Arquivo.txt
						CreateTxTFile();
					break;

					default:
						Warning();	
				}
				}while(subop != 0);
				break;
			
			case 4:
				do{
				printf("\n\nAgora voc� esta no submenu de Jogos, favor, insira qual das aplica��es dispon�veis voc� deseja executar:\n");
				printf("\n\n0- Voltar;\n1- Forca;");
				printf("\n:");
				scanf("%d",&subop);
				switch(subop){
					case 0:
						substop = 0;
					break;
					
					case 1: 
						PlayHangedMan();
					break;

					default:
						Warning();	
				}
				}while(subop != 0);
				break;
			
			default:
			Warning();
		}
	}while(op != 0);
    return stop;
}


/*PRINTS PARA INSERIR OP��ES DO MENU E SUBMENU*/


/* --> Atualmente esta � a linha 554, assim, para as refer�ncias de linha abaixo, cheque com a atual desta linha, se difernte, altere pela diferen�a: n' = n + (x-554)
		ABAIXO ENCONTRA-SE UM "ATALHO" PARA ADICIONAR AO MENU OUTROS CASES E OU SUBCASES, COM A IDENTA��O E FECHAMENTO CORRETO
*/ 


/*int CallDextery(){ // EXECUTAR MENU DEXTERY
	int stop = 1, substop = 1, understop = 1;
	int op = 1, subop = 1, underop = 1;
	SetPurtuguese();
	do{
		printf("\nBEM VINDO AO DEXTERY\n\nFavor, escolha uma op��o v�lida no menu abaixo:\n");
		printf("\n 0- Sair");
		printf("\n 1- Configura��es Iniciais Dextery");
		printf("\n 2- Realizar opera��es Matem�ticas");
		printf("\n 3- Manipular arquivos");
		printf("\n:");
		//printf("\n x- \n"); // Para novas fun��es
		scanf("%d",&op);
		switch(op){
*/
	
	// COPIE ABAIXO, ENTRE AS LINHAS 26 E 78 PARA SELECIONAR TODA UMA CATEGORIA DO MENU. O DEFAULT DO SUBMENU ESTA NA LINHA 67, CASO NECESSITE ADICION�-LO
/* --- > INICIAL

			case 2:
				do{
				printf("\n\nAgora voc� esta no submenu de x, favor, insira qual das aplica��es dispon�veis voc� deseja executar:\n");
				printf("\n\n0- Voltar;\n1- ;\n2- ;\n3- ;\n4- ;");
				printf("\n:");
				scanf("%d",&subop);
				switch(subop){
					case 0:
						substop = 0;
					break;
					
					case 1: // Basic Call Case
						
					break;
				
	// COPIE ABAIXO, ENTRE AS LINHAS 31 E 48 PARA SELECIONAR TODA UMA SUBCATEGORIA DO MENU
		
					case 2: // Submenu Call Case
						do{
							printf("\n\nAgora voc� esta no submenu de x, favor, insira qual das aplica��es dispon�veis voc� deseja executar:\n");
							printf("\n\n0- Voltar;\n1- ;\n2- ;\n3- ;\n4- ;");
							printf("\n: ");
							scanf("%d",&underop);
							switch(underop){
								case 0:
									understop = 0;
									
								case 1: // Basic Call SubCase
									//Showdate(Datetoday());	
								break;
								
								default:
									Warning();
							}
						}while(understop !=0);
					break;

					default:
						Warning();	
				}
				}while(subop != 0);
				break;

 --- > FINAL */
			
			/*default:
			Warning();
		}
	}while(op != 0);
    return stop;
}*/

void WakeDexter(){
	int ret;
	do{
		ret = CallDextery();
	}while(ret != 0);
}
