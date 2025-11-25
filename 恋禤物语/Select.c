#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

unsigned int Select_1(void)
{
	unsigned int select = 0;
	printf("\n");
	printf("---- 1. 请多多关照\n");
	printf("---- 2. ... \n");
	do
	{
		printf("请输入选择：");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		default:
			printf("没有该选项呢~");
				break;
		}
	} while (select != 1 || select != 2);	
}