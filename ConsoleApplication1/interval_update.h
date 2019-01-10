#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>

void check_args(char *fn1, char *fn2, char *prob);
void interval_update(char *fn1, char *fn2, char *prob);
void intervalSearching(double low, double high);
void WriteFile(char *fn2, double low, double high, double d);