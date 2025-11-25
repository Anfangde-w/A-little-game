#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.system.h>

//好心情回复1
void Story_Reply_Happy_1(void)
{
	printf("嗯呐~\n");
}


//开头剧情1
void Story_Start_1(void)
{
	printf("\n“嗨，初次见面，我叫“禤总”，你叫什么呢？”\n");
}

//开头剧情2
void Story_Start_2(char* Playername)
{
	printf("\n“原来你叫%s吗？真是一个好听的名字呢！以后请多多关照噢~”\n", Playername);
}

//旁白文本1
void Story_Text_1(void)
{
	printf("“禤”是你的家旁边新搬来的邻居，");
	system("timeout 2");
}