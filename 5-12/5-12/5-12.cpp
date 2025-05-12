#include "5-12.h"

void SetPos(short x, short y)
{
	// 获得标准输入的权柄
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//定位光标的位置
	COORD pos = { x, y };
	SetConsoleCursorPosition(houtput, pos);
}

void WelComToGame()
{
	SetPos(14, 40);
	wprintf(L"欢迎来到贪吃蛇小游戏\n");
	SetPos(14, 42);
	system("pause");
	system("cls");
	SetPos(40, 14);
	wprintf(L"用 ↑.↓.←.→ 来控制方向，按 F3 键加速，F4 减速\n");
	SetPos(40, 15);
	wprintf(L"加速能得到更高的分数\n");

	SetPos(42, 20);
	system("pause");
}

void CreatMap()
{
	//上
	for (int i = 0; i < 29; i++)
	{
		wprintf(L"%lc", L'□');
	}

	//下
	SetPos(0, 26);
	for (int i = 0; i < 29; i++)
	{
		wprintf(L"%lc", L'□');
	}

	//左
	for (int i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", L'□');
	}

	//右
	for (int i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", L'□');
	}
}

void GameStart(pSnack ps)
{
	// 0. 先设置窗口的大小，再光标隐藏
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE); 
	CONSOLE_CURSOR_INFO CursorInfo;             // 隐藏光标操作
	GetConsoleCursorInfo(houtput, &CursorInfo); // 获取控制光标信息
	CursorInfo.bVisible = false;                // 隐藏控制台信息
	SetConsoleCursorInfo(houtput, &CursorInfo); // 设置控制台光标


	// 1. 打印欢迎界面
	// 2. 功能介绍
	WelComToGame();
	// 3. 绘制地图
	CreatMap();
	// 4. 创建蛇
	// 5. 创建食物
	// 6. 设置游戏的相关信息
}