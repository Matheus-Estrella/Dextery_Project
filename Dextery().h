/* //-- Favor, copie as linas abaixo dentro do comentário para rapidamente criar um arquivo para executar umt este desta biblioteca

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

// abixo encontra-se o print para inserção de observações de novos módulos de funções (linhas 18 á 31)

/*
Resumo de funções apresentadas abaixo:

 ----> Funções Principais:
 
 
 

 ----> Funções Auxiliares:
 
 
 

*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//Abaixo serão inseridas as configurações para os defines necessários



// Acima serão inseridas as configurações para os defines necessários
//------------------------------------------------------------------------
//------------------------------------------------------------------------

/*
Resumo de funções apresentadas abaixo: Funções Universais Dextery()

 ----> Funções Principais:
 SetConfigs() = Seta configurações iniciais, tais como SetPurtugues
 CreateTxtFile = Cria um arquivo de texto com nome personalizável
 criarArquivoBinario = Cria um arquivo binário com nome personalizável

 ----> Funções Auxiliares:
  SetPurtuguese() = Configura opções em português para Dextery()
 
*/

void SetPurtuguese(){
	setlocale(LC_ALL, "Portuguese");
	system("pause");
}

void SetConfigs(){ 
	SetPurtuguese();
}

void Warning(){
	printf("\n\n\n----------  POR FAVOR DIGITE UMA OPÇÃO VÁLIDA DO MENU  ----------\n\n\n");
}
/*
Resumo de funções apresentadas abaixo: Manipulção de datas

 ----> Funções Principais:
 
Datetoday() = Retorna em int o número que representa o dia atual
Getdate() = Permite que o usuárioo insira uma data e a retorne em valor int
Betweendates() = Retorna em int o número que representa a diferença entre duas datas inseridas
Showdate() = Imprime uma data em int, no formato dd/mm/aaaa
Printbetween() = Imprime a difernça entre duas datas em int, mostrando dias, semanas, meses, anos, decadas e séculos entre elas

 ----> Funções Auxiliares:

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

        printf("Digite o mês: ");
        scanf("%d", &month);

        printf("Digite o ano: ");
        scanf("%d", &year);

        leap_year = check_leap_year(year);
        valid_month = check_valid_month(month);
        valid_day = check_valid_day(day, month, leap_year);

        if ((valid_day == 0) || (valid_month == 0)) {
            printf("\n\nFavor, insira uma data válida\n\n");
            if ((day == 29) && (month == 2) && (leap_year == 0)) {
                printf("Neste ano não houve ano bissexto");
            }
        }

    } while ((valid_day == 0) && (valid_month == 0));

    int date_int = (year * 10000) + (month * 100) + day;

    return date_int;
}

int Betweendates() {
    printf("\nDeseja utilizar a referência da data de hoje como uma das datas?\n1 - Sim\n2 - Não\n:");
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
		printf("\nHoje é dia: ");
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
	printf("\nA diferença de datas entre os dias selecionados equivalem a");
	if(day<0){
		printf(" seguinte futura data:\n");
	}else{
		printf(" seguinte data passada:\n");
	}
	printf("\n %d dias;\n %.3f semanas;\n %.3f meses;\n %.3f anos;\n %.3f décadas\n %.4f séculos",day,week, month, year, decade, century);
}
//---------------------------------------------------------------------------------------------------------------------------------------


/*
Resumo de funções apresentadas abaixo: Verificar Triângulos ----------> Verificadas, funcionando corretamente

 ----> Funções Principais:
 checktriangle() = Executa as funções auxiliares dos triângulos
 
 ----> Funções Auxiliares:
 TypeTriangleValue = Insere um valor de lado do triangulo a ser inserido
 Modulo_Dif = Retorna um valor de diferença float em módulo
 Check_If_Triangle = Checa se 3 lados float inseridos formam um triângulo ou não
 checkEquilatero checkIsosceles checkEscaleno = Verifica qual triangulo é formado ao inserir seus lados, caso seja
 Triangle_Area_Perimeter = Calcula a área de um triangulo e sue perímetro
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
		FUNÇÃO MENU DEXTERY. FUNÇÃO PRINCIPAL DA BIBLIOTECA
*/ 

int CallDextery(){ // EXECUTAR MENU DEXTERY
	int stop = 1, substop = 1, understop = 1;
	int op = 1, subop = 1, underop = 1;
	SetPurtuguese();
	do{
		printf("\nBEM VINDO AO DEXTERY\n\nFavor, escolha uma opção válida no menu abaixo:\n");
		printf("\n 0- Sair");
		printf("\n 1- Configurações Iniciais Dextery");
		printf("\n 2- Realizar operações Matemáticas");
		printf("\n:");
		//printf("\n x- \n"); // Para novas funções
		scanf("%d",&op);
		switch(op){
			case 0:
				stop = 0;
			break;
			
			case 1:
				do{
				printf("\n\nAgora você esta no submenu de Configurações Iniciais Dextery, favor, insira qual das aplicações disponíveis você deseja executar:\n");
				printf("\n\n0- Voltar;\n1- Configurações Gerais;\n2- Configurar Idioma Português (PT)");
				printf("\n:");
				scanf("%d",&subop);
				switch(subop){
					
					case 0:
						substop = 0;
					break;
					
					case 1: // Configurações Gerais
						SetConfigs();	
					break;
					
					case 2: // Configurar Idioma Português (PT)
						SetPurtuguese();
					break;
					
					default:
						Warning();	
					}
				}while(subop != 0);
				break;
			
			case 2:
				do{
				printf("\n\nAgora você esta no submenu de Realizar operações Matemáticas, favor, insira qual das aplicações disponíveis você deseja executar:\n");
				printf("\n\n0- Voltar;\n1- Checagem de triângulos;\n2- Calcular entre datas");
				printf("\n:");
				scanf("%d",&subop);
				switch(subop){
					case 0:
						substop = 0;
					break;
					
					case 1: // Checa três inputs para ver se são triâgulos, quais, e sua area e perímetro
						checktriangle();
						
					break;
					
					case 2: // Para sub-sub manipulação de datas
						do{
							printf("\n\nAgora você esta no submenu de manipulação de datas, favor, insira qual das aplicações disponíveis você deseja executar:\n");
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
			
			default:
			Warning();
		}
	}while(op != 0);
    return stop;
}


/*PRINTS PARA INSERIR OPÇÕES DO SUBMENU
				do{
					printf("\nAgora você esta no submenu de x, favor, insira qual das aplicações disponíveis você deseja executar:\n");
					printf("\n0- Sair;\n1- ;\n2- ;\n3- ;\n4- ;\n5- ;\n");
					scanf("%d",&subop);
					switch(subop){
						case 0:
							substop = 0;
						break;
						case 1:
							
						break;
						case 2: // Para sub-sub rotinas (underop)
							do{
								printf("\nAgora você esta no submenu de x, favor, insira qual das aplicações disponíveis você deseja executar:\n");
								printf("\n0- Sair;\n1- ;\n2- ;\n3- ;\n4- ;\n5- ;\n");
								scanf("%d",&underop);
								switch(underop){
									case 0:
										understop = 0;
									case 1:
										
									break;
							
									default:
										Warning();
								}
							}while(underop != 0);
						break;
						
						default:
							Warning();	
					}
				}while(subop != 0);
*/

