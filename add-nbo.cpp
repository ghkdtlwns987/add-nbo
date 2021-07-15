  
//두 파일을 읽어 500 + 1000 = 1500 을 울력하는 프로그램을 출력
//(파일에서 4bit 를 읽도록 한다.)

#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<stdint.h>
#include<stddef.h>
uint32_t my_ntohl(uint32_t p){
	return ((p >> 24) & 0x000000FF) | ((p >> 8) & 0x0000FF00) | ((p << 8) & 0x00FF0000) | ((p << 24) & 0xFF000000);
}

int five_hundred(char * path){
	FILE * fp = fopen(path,"rb");
	if(fp == NULL){
		puts("FILE OPEN ERROR!!");
		exit(1);
	}
	uint8_t data[4] = {0,};
	fread(data, 4, 1, fp);
	uint32_t * p = reinterpret_cast<uint32_t*>(data);
	uint32_t n = my_ntohl(*p);	
	
	printf("bit : 0x%x \n",n);
	return n;
}

int thousand(char * path){
	FILE * fp = fopen(path,"rb");
	if(fp == NULL){
		puts("FILE OPEN ERROR!!");
		exit(1);
	}
	uint8_t data[4] = {0,};
	fread(data, 4, 1, fp);
	uint32_t * p = reinterpret_cast<uint32_t*>(data);
	uint32_t n = my_ntohl(*p);

	printf("bit : 0x%x \n",n);
	return n;
}

int main(int argc, char * argv[]){
	uint32_t data1;
	uint32_t data2;
	
	data1 = thousand(argv[1]);
	data2 = five_hundred(argv[2]);

	printf("%d(0x%x) + %d(0x%x) = %d\n",data1, data1, data2, data2, data1 + data2);
			
	return 0;
}
