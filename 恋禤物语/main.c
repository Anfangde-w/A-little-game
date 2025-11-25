#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "Game.h"
//#include <math.h>
//#include <string.h>
//#include <stdlib.h>
#include <windows.system.h>

void Start_Win(void)
{
    printf("##############################\n");
    printf("#####      欢迎游玩      #####\n");
    printf("#####     ‘恋禤物语’     #####\n");
    printf("#####        V1.0        #####\n");
    printf("##############################\n\n");
}

void Menu(void)
{
    printf("  ------- 1.新的开始 -------\n");
    printf("  ------- 2.读取游戏 -------\n");
    printf("  ------- 3.  关于   -------\n");
    printf("  ------- 4.退出游戏 -------\n\n");
}

int main()
{
    int StartSelect = 0;
    Start_Win();
    do
    {
        Menu();
        printf("请输入你的选择：");
        scanf(" %d", &StartSelect);
        switch (StartSelect)
        {
        case 1:
            Game();
            break;
        case 2:
            ReGame();
            break;
        case 3:
            About();
            break;
        case 4:
            printf("游戏已退出，记得回来陪禤禤我啊！！！\n");
            break;
        default:
            printf("禤禤提醒你，选择错误，请重新选择哦~\n");
            break;
        }
    } while (StartSelect != 4);

	return 0;
}
