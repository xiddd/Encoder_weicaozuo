#include"Help_Functions.h"
bool update_filebuffer(Wei &output, int value)
{
	static int updateflag = 0;
	switch (updateflag)
	{
	case 0:
	{
		// do something
		updateflag++;
		return false;
	}
	case 7:
	{
		return true;
	}break;
	//case  n..
	default:
	}
}
bool fun(int v)//�ж��ǲ���2���ݴ�

{
	if ((v > 0) && (v&(v - 1)) == 0)
		return true;
	else
		return false;
}
bool mNum(int a, int b)
{
	int c = b - a;
	if ((a%c == 0) && (b%c == 0) && fun(c))
	{
		return true;
	}
	else
		return false;
}