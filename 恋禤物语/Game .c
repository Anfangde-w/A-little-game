#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "Story.h"
#include "Select.h"
#include <string.h>
#include <stdlib.h>
#include <windows.system.h>

//游戏中所选择的选项
unsigned int Game_Select = 0;

//玩家的名字
char PlayerName[50];
//姓名存在判断指标
int nameflag = 0;

//角色属性值：
//1.好感度、2.伤心值、3.开心值、4.生气值、5.依赖值
typedef struct UserLevel
{
    int LoveLevel;//max500
    int SadLevel;//max300
    int HappyLevel;//max300
    int AngryLevel;//max150
    int DependeLevel;//max150
}userlevel;

//角色“禤”
userlevel Xuan = { 0,10,20,0,0 };

//文件数据的读取
char Laod_UserData(void)
{
    size_t count = 0;
    FILE* userdata = fopen("userdata.bin", "rb");
    if (userdata == NULL)
    {
        printf("文件读取失败！\n");
        return 1;
    }

    count += fread(PlayerName, sizeof(char), 50, userdata);
    printf("用户名读取成功！\n");
}

//游戏初始化
//读取存储文件
unsigned int Game_Init(void)
{
    ;
    return 1;
}

//好感度变化
void Select_LoveLevel_result_Up(int level)
{
    Xuan.LoveLevel += level;
    if (Xuan.LoveLevel > 500)
    {
        Xuan.LoveLevel = 500;
    }
    if (Xuan.LoveLevel < 0)
    {
        Xuan.LoveLevel = 0;
    }
}

void Select_LoveLevel_result_Down(int level)
{
    Xuan.LoveLevel -= level;
    if (Xuan.LoveLevel > 500)
    {
        Xuan.LoveLevel = 500;
    }
    if (Xuan.LoveLevel < 0)
    {
        Xuan.LoveLevel = 0;
    }
}

//伤心值变化
void Select_SadLevel_result_Up(int level)
{
    Xuan.SadLevel += level;
    if (Xuan.SadLevel > 300)
    {
        Xuan.SadLevel = 300;
    }
    if (Xuan.SadLevel < 0)
    {
        Xuan.SadLevel = 0;
    }
}

void Select_SadLevel_result_Down(int level)
{
    Xuan.SadLevel -= level;
    if (Xuan.SadLevel > 300)
    {
        Xuan.SadLevel = 300;
    }
    if (Xuan.SadLevel < 0)
    {
        Xuan.SadLevel = 0;
    }
}

//开心值变化
void Select_HappyLevel_result_Up(int level)
{
    Xuan.HappyLevel += level;
    if (Xuan.HappyLevel > 300)
    {
        Xuan.HappyLevel = 300;
    }
    if (Xuan.HappyLevel < 0)
    {
        Xuan.HappyLevel = 0;
    }
}

void Select_HappyLevel_result_Down(int level)
{
    Xuan.HappyLevel -= level;
    if (Xuan.HappyLevel > 300)
    {
        Xuan.HappyLevel = 300;
    }
    if (Xuan.HappyLevel < 0)
    {
        Xuan.HappyLevel = 0;
    }
}

//生气值变化
void Select_AngryLevel_result_Up(int level)
{
    Xuan.AngryLevel += level;
    if (Xuan.AngryLevel > 150)
    {
        Xuan.AngryLevel = 150;
    }
    if (Xuan.AngryLevel < 0)
    {
        Xuan.AngryLevel = 0;
    }
}

void Select_AngryLevel_result_Down(int level)
{
    Xuan.AngryLevel -= level;
    if (Xuan.AngryLevel > 150)
    {
        Xuan.AngryLevel = 150;
    }
    if (Xuan.AngryLevel < 0)
    {
        Xuan.AngryLevel = 0;
    }
}

//依赖值变化
void Select_DependeLevel_result_Up(int level)
{
    Xuan.DependeLevel += level;
    if (Xuan.DependeLevel > 150)
    {
        Xuan.DependeLevel = 150;
    }
    if (Xuan.DependeLevel < 0)
    {
        Xuan.DependeLevel = 0;
    }
}

void Select_DependeLevel_result_Down(int level)
{
    Xuan.DependeLevel -= level;
    if (Xuan.DependeLevel > 150)
    {
        Xuan.DependeLevel = 150;
    }
    if (Xuan.DependeLevel < 0)
    {
        Xuan.DependeLevel = 0;
    }
}


//角色属性值变化：
//1.好感度、2.伤心值、3.开心值、4.生气值、5.依赖值
//1.加、0.减
//1.level为值
void Select_Result(int type, int control, int level)
{
    switch (type)
    {
    case 1 :
        if (control == 1)
        {
            Select_LoveLevel_result_Up(level);
        }
        else
        {
            Select_LoveLevel_result_Down(level);
        }
        break;
    case 2:
        if (control == 1)
        {
            Select_SadLevel_result_Up(level);
        }
        else
        {
            Select_SadLevel_result_Down(level);
        }
        break;
    case 3:
        if (control == 1)
        {
            Select_HappyLevel_result_Up(level);
        }
        else
        {
            Select_HappyLevel_result_Down(level);
        }
        break;
    case 4:
        if (control == 1)
        {
            Select_AngryLevel_result_Up(level);
        }
        else
        {
            Select_AngryLevel_result_Down(level);
        }
        break;
    case 5:
        if (control == 1)
        {
            Select_DependeLevel_result_Up(level);
        }
        else
        {
            Select_DependeLevel_result_Down(level);
        }
        break;
    default:
        break;
    }
}

void Game(void)
{
    system("cls");
	printf("Game\n");
    Story_Start_1();  
    printf("输入你想起的名字：");
    getchar();
    scanf("%s", PlayerName);
    getchar();
    Story_Start_2(PlayerName);
    Game_Select = Select_1();
    if (Game_Select == 1)
    {
        Select_Result(1, 1, 1);
        Select_Result(3,1,3);
        Story_Reply_Happy_1();
    }
    Game_Select = 0;
    //printf("%d,%d,%d,%d,%d,%d\n", Xuan.AngryLevel, Xuan.DependeLevel, Xuan.HappyLevel, Xuan.LoveLevel, Xuan.SadLevel, Game_Select);
    Story_Text_1();
}

void ReGame(void)
{
	printf("ReGame\n");
}

void Respect(void)
{
    printf("######################################\n");
    printf("#####   感谢游玩‘恋禤物语’V1.0   #####\n");
    printf("######################################\n");
    printf("## 这是一款命令行文本交互类游戏     ##\n");
    printf("######################################\n\n");
}

void About(void)
{
    Respect();
}