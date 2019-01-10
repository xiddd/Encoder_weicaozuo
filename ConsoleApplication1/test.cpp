#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include"interval_update.h"


//#define step(n) 1.0/pow(2,n)
//bool fun(int v);
//bool mNum(int a, int b);
//void intervalSearching(double low, double high);
//void interval_update(char *fn1, char *fn2, char *prob);
//void check_args(char *fn1, char *fn2, char *prob);


int main(int argc, char *argv[])
{
	if (argc != 4)
		return 2;
	/*printf("argv[1]:%s", argv[1]);
	printf("argv[2]:%s", argv[2]);
	printf("argv[3]:%s", argv[3]);*/
	//check_args(argv[1], argv[2], argv[3]);
	//printf("\n %s \n %s \n %s", argv[1], argv[2], argv[3]);
	interval_update(argv[1], argv[2], argv[3]);//区间更新函数
	system("pause");
//fclose(fin);
	//fclose(fout);
}
//void check_args(char *fn1, char *fn2, char *prob)
//{
//	double p0;
//	fin = fopen(fn1, "rb");
//	if (fin == NULL)
//	{
//		printf("\n cannot open input file %s", fn1);
//		exit(1);
//	}
//	fout = fopen(fn2, "wb");
//	if (fin == NULL)
//	{
//		printf("\n cannot open output file %s", fn2);
//		exit(1);
//	}
//	p0 = strtod(prob, NULL);
//	if (p0 >= 1.0)
//	{
//		printf("\n illegal prob: %s", prob);
//		exit(1);
//	}
//}

//void interval_update(char *fn1, char *fn2, char *prob)
//{
//	double p0,p1,d;
//	int output_bit=0;
//	p0 = strtod(prob, NULL);
//	p1 = 1 - p0;
//	double low = 0.0;
//	double high = 1.0;
//	d = high - low;
//	unsigned char Q;
//	//output Output_encoder;
//	fread(&Q, 1, 1, fin);
//	while (!feof(fin))
//	{
//		if (Q == '0')
//		{
//			high = low + d*p0;
//			d = high - low;
//			if (d < 0.25)
//			{
//				while (d < 0.25)
//				{
//					if (high < 0.5)
//					{
//						//在位域里输入一个0
//
//						if (output_bit){
//							for (int i = 0; i < output_bit; i++){
//								//位域输入output_bit个1
//							}
//							output_bit = 0;
//						}
//						low *= 2;
//						high *= 2;
//						d = high - low;
//					}
//					else if (low > 0.5)
//					{
//						//在位域里输入1
//						if (output_bit){
//							for (int i = 0; i<output_bit; i++){
//								//位域输入output_bit个0
//							}
//							output_bit = 0;
//						}
//						low = (low - 0.5) * 2;
//						high = (high - 0.5) * 2;
//						d = high - low;
//					}
//					else
//					{
//						low = (low - 0.25) * 2;
//						high = (high - 0.25) * 2;
//						d = high - low;
//						output_bit += 1;
//					}
//				}
//			}
//		}
//		else if (Q == '1')
//		{
//			low = low + d*p0;
//			d = high - low;
//			if (d < 0.25)
//			{
//				while (d < 0.25)
//				{
//					if (high < 0.5)
//					{
//						//在位域里输入一个0
//						if (output_bit){
//							for (int i = 0; i < output_bit; i++){
//								//位域输入output_bit个1
//							}
//							output_bit = 0;
//						}
//						low *= 2;
//						high *= 2;
//						d = high - low;
//					}
//					else if (low > 0.5)
//					{
//						//在位域里输入1
//						if (output_bit){
//							for (int i = 0; i < output_bit; i++){
//								//位域输入output_bit个0
//							}
//							output_bit = 0;
//						}
//						low = (low - 0.5) * 2;
//						high = (high - 0.5) * 2;
//						d = high - low;
//					}
//					else
//					{
//						low = (low - 0.25) * 2;
//						high = (high - 0.25) * 2;
//						d = high - low;
//						output_bit += 1;
//					}
//				}
//			}
//		}
//		fread(&Q, 1, 1, fin);
//	}
//	intervalSearching(low, high);
//}
//void intervalSearching(double low, double high)
//{
//	double d = high - low;
//	double last;
//	int begin = 0;
//	int intlow = ceil(low * pow(2, begin));
//	int inthigh = floor(high * pow(2, begin));
//	int lowloop = intlow;
//	int highloop = inthigh;
//	bool flag = false;
//	int resultlow;
//	int resulthigh;
//	while (!flag)
//	{
//
//		while (lowloop < highloop && (!flag)){
//			for (int i = lowloop; i < highloop; i++)
//			{
//				for (int j = highloop; j > lowloop; j--)
//				{
//					if (flag = mNum(i, j))
//					{
//						resultlow = i;
//						resulthigh = j;
//						break;
//					}
//				}
//				if (flag)
//					break;
//			}
//		}
//		if (!flag)
//		{
//			begin += 1;
//			lowloop = ceil(low * pow(2, begin));
//			highloop = floor(high * pow(2, begin));
//		}
//	}
//	last = resultlow / pow(2, begin);//小数
//	//把这个写到文件里
//}

//output output1;
//output1.a = 0;
//output1.b = 1;
//output1.c = 0;
//output1.d = 0;
//output1.e = 0;
//output1.f = 1;
//output1.g = 0;
//output1.h = 0;
////printf("\n %d", sizeof(output1));
//fwrite(&output1, 1, 1, fout);
//output1.a = 0;
//output1.b = 1;
//output1.c = 0;
//output1.d = 0;
//output1.e = 0;
//output1.f = 1;
//output1.g = 0;
//output1.h = 0;
//fwrite(&output1, 1, 1, fout);