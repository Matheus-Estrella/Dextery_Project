/* //-- Favor, copie as linas abaixo dentro do coment�rio para rapidamente criar um arquivo para executar umt este desta biblioteca

#include<stdio.h>
#include"Dextery().h"

int main(){
	int ret;
	do{
		ret = CallDextery();
	}while(ret != 0);
	return 0;
}

*/

// abixo encontra-se o print para inser��o de observa��es de novos m�dulos de fun��es (linhas 18 � 31)

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

void SetPurtuguese(){
	setlocale(LC_ALL, "Portuguese");
	system("pause");
}

void SetConfigs(){ 
	SetPurtuguese();
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

//---------------------------------------------------------------------------------------------------------------------------------------


/*
		FUN��O MENU DEXTERY. FUN��O PRINCIPAL DA BIBLIOTECA
*/ 

int CallDextery(){ // EXECUTAR MENU DEXTERY
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
						SetPurtuguese();
					break;
					
					default:
						Warning();	
					}
				}while(subop != 0);
				break;
			
			case 2:
				do{
				printf("\n\nAgora voc� esta no submenu de Realizar opera��es Matem�ticas, favor, insira qual das aplica��es dispon�veis voc� deseja executar:\n");
				printf("\n\n0- Voltar;\n1- Checagem de tri�ngulos;\n2- Calcular entre datas");
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
							printf("\n\n0- Voltar;\n1- Mostrar dia atual;\n2- Calcular datas;\n");
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
							scanf("%d",&underop);
							switch(underop){
								case 0:
									understop = 0;
									
								case 1: // Basic Call SubCase
									Showdate(Datetoday());	
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


