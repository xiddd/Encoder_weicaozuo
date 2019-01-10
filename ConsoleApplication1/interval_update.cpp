#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include"interval_update.h"
#include"intervalSearching.h"

FILE *fin;
FILE *fout;
void check_args(char *fn1, char *fn2, char *prob)
{
	
	double p0;
	fin = fopen(fn1, "rb");
	if (fin == NULL)
	{
		printf("\n cannot open input file %s", fn1);
		exit(1);
	}
	else
		printf("\n 成功打开intput %s", fn1);
	fout = fopen(fn2, "wb");
	if (fin == NULL)
	{
		printf("\n cannot open output file %s", fn2);
		exit(1);
	}
	else
		printf("\n 成功打开output %s", fn2);
	

	WriteFile(fn2, 1, 1, 0);
	p0 = strtod(prob, NULL);
	if (p0 >= 1.0)
	{
		printf("\n illegal prob: %s", prob);
		exit(1);
	}
}

bool NumofCount(int count){
	if (count < 8){
		return false;
	}
	else if (count == 8){
		return true;
	}
	else {
		printf("计数错误，超过了8");
		exit(0);
	}
}
void WriteFile(char *fn2,double low, double high,double d){


	int count = 0,output_bit=0;
	unsigned char buf;
	if (low==1)
	buf = 0x1;
	else
	buf = 0x2;

	printf(" test  %s  test",fn2);

	fwrite(&buf, 1, 1, fout); buf = 0x0;
	/*if (high < 0.5){ 
			if (NumofCount(count)){
				count = 0; fwrite(&buf, 1, 1, fout); buf = 0x0;
				printf("写入文件");
			}
			buf = buf << 1; count++;
			for (int i = 0; i < output_bit; i++){
				if (NumofCount(count)){
					count = 0; fwrite(&buf, 1, 1, fout); buf = 0x0;
				}
				buf = buf << 1 + 1; count++;
			}
			low *= 2; high *= 2; d = high - low;
		}
		else if (low > 0.5){
			if (NumofCount(count)){
				count = 0; fwrite(&buf, 1, 1, fout); buf = 0x0;
			}
			buf = buf << 1 + 1; count++;
			for (int i = 0; i < output_bit; i++){
				if (NumofCount(count)){
					count = 0; fwrite(&buf, 1, 1, fout); buf = 0x0;
				}
				buf = buf << 1; count++;
			}
			low = (low - 0.5) * 2; high = (high - 0.5) * 2; d = high - low;
		}
		else {
			low = (low - 0.25) * 2; high = (high - 0.25) * 2;
			d = high - low; output_bit += 1;
	}*/
}

void interval_update(char *fn1, char *fn2, char *prob)
{
	/***********************************************
	open file once
	***********************************************/
	double p0;
	fin = fopen(fn1, "rb");
	if (fin == NULL)
	{
		printf("\n cannot open input file %s", fn1);
		exit(1);
	}
	else
		printf("\n 成功打开intput %s", fn1);
	fout = fopen(fn2, "wb");
	if (fin == NULL)
	{
		printf("\n cannot open output file %s", fn2);
		exit(1);
	}
	else
		printf("\n 成功打开output %s", fn2);
	//

	p0 = strtod(prob, NULL);
	if (p0 >= 1.0)
	{
		printf("\n illegal prob: %s", prob);
		exit(1);
	}
	//open file done
	/******************************************/
	WriteFile(fn1, 1, 1, 1);
	//first change
	WriteFile(fn1, 2, 2, 2);
	////check_args(fn1, fn2, prob);
	//printf("\n %s \n %s \n %s",fn1, fn2, prob);
	//double p0, p1, d, low = 0.0, high = 1.0;
	//int count = 0,output_bit = 0,Numoffin=0;
	//unsigned char Q,buf = 0x0;//buf只能存8个，后面来的会被移走；
	//p0 = strtod(prob, NULL);//转成小数
	//p1 = 1 - p0; 
	//d = high - low;
	//int c;
	////找到文件大小
	//fseek(fin, 0, SEEK_END);//已经跳到末尾了，后面读的时候要从头开始
	//Numoffin = ftell(fin);
	//fseek(fin, 0, SEEK_SET);//跳回开头
	//写入文件
	/*for (int i = 0; i < 4; i++){
		buf = (buf << 1) + 1;	
	}
	for (int i = 4; i < 8; i++){
		buf = (buf << 1) ;
	}

	fwrite(&buf, 1, 1, fout);*/
	
	//for (int i = 0; i < Numoffin; i++)
	//{
	//	fread(&Q, 1, 1, fin);
	//	if (Q == '0'){
	//		high = low + d*p0;
	//		d = high - low;	
	//		/*while (d < 0.25)
	//		{
	//			if (high < 0.5){
	//				if (NumofCount(count)){
	//					count = 0;fwrite(&buf, 1, 1, fout); buf = 0x0;
	//				}
	//				buf = buf << 1; count++;
	//				for (int i = 0; i < output_bit; i++){
	//					if (NumofCount(count)){
	//						count = 0;fwrite(&buf, 1, 1, fout); buf = 0x0;
	//					}
	//					buf = buf << 1 + 1; count++;
	//				}
	//				low *= 2;high *= 2;d = high - low;
	//			}
	//			else if (low > 0.5){
	//				if (NumofCount(count)){
	//					count = 0; fwrite(&buf, 1, 1, fout); buf = 0x0;
	//				}
	//				buf = buf << 1 + 1; count++;
	//				for (int i = 0; i < output_bit; i++){
	//					if (NumofCount(count)){
	//						count = 0; fwrite(&buf, 1, 1, fout); buf = 0x0;
	//					}
	//					buf = buf << 1 ; count++;
	//				}
	//				low = (low - 0.5) * 2;high = (high - 0.5) * 2;d = high - low;
	//			}
	//			else {
	//				low = (low - 0.25) * 2; high = (high - 0.25) * 2;
	//				d = high - low; output_bit += 1;
	//			}
	//		}*/
	//		WriteFile(fn1, low, high, d);
	//	}
	//	else if (Q == '1'){
	//		low = low + d*p0;
	//		d = high - low;
	//		while (d < 0.25)
	//		{
	//			if (high < 0.5){
	//				if (NumofCount(count)){
	//					count = 0; fwrite(&buf, 1, 1, fout); buf = 0x0;
	//				}
	//				buf = buf << 1; count++;
	//				for (int i = 0; i < output_bit; i++){
	//					if (NumofCount(count)){
	//						count = 0; fwrite(&buf, 1, 1, fout); buf = 0x0;
	//					}
	//					buf = buf << 1 + 1; count++;
	//				}
	//				low *= 2; high *= 2; d = high - low;
	//			}
	//			else if (low > 0.5){
	//				if (NumofCount(count)){
	//					count = 0; fwrite(&buf, 1, 1, fout); buf = 0x0;
	//				}
	//				buf = buf << 1 + 1; count++;
	//				for (int i = 0; i < output_bit; i++){
	//					if (NumofCount(count)){
	//						count = 0; fwrite(&buf, 1, 1, fout); buf = 0x0;
	//					}
	//					buf = buf << 1; count++;
	//				}
	//				low = (low - 0.5) * 2; high = (high - 0.5) * 2; d = high - low;
	//			}
	//			else {
	//				low = (low - 0.25) * 2; high = (high - 0.25) * 2;
	//				d = high - low; output_bit += 1;
	//			}
	//		}
	//	}
	//}
	//fwrite(&buf, 1, 1, fout);
	//intervalSearching(low, high);
	printf("\n 执行结束");
	fclose(fin);
	fclose(fout);
}
