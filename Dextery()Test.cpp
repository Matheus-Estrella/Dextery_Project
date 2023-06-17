#include<stdio.h>
#include"Dextery().h"

int main(){
	int ret;
	do{
		ret = CallDextery();
	}while(ret != 0);
	return 0;
}
