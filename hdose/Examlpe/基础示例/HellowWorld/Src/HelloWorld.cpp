// HelloWorld.cpp : Defines the entry point for the console application.
//
#include <hdose.h>
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int main(int argc, char* argv[])
{
	StartHdose("HellowWorld.SIM");

	printf("输入任意字符结束！！！\n");
	while(getchar())
	{
		EndHdose();
		Sleep(100);
		return 0;
	}
	
}
