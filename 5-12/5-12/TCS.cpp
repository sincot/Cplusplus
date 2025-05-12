#define  _CAR_SECURE_NO_WARNINGS
#include "5-12.h"

//游戏的实现
void game()
{
	//创建贪吃蛇 —— 基于链表实现贪吃蛇
	Snack snack = { 0 };

	//初始化游戏
	GameStart(&snack);

	//运行游戏
	//GameRun();
	//结束游戏，完成善后操作
	//GameEnd();
}

int main()
{
	//设置适配本地的环境
    setlocale(LC_ALL, "");
	
	game();

	return 0;
}