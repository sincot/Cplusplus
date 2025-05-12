#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <locale.h>  // 宽字符

//类型的声明 和 函数的声明
 
// 定义贪吃蛇的结点的结构
typedef struct SnackNode
{
	//坐标
	int x;
	int y;

	//指针
	struct SnackNode* next;
}SnackNode;

typedef struct SnackNode* pSnackNode;

// 枚举出贪吃蛇的所有方向 —— 上，下，左，右
enum DIRACTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

//蛇的状态 —— 正常，撞墙，撞到自己，正常退出
enum GAME_STATUS
{
	OK,             // 正常（包含暂停）
	KILL_BY_WALL,   // 撞墙
	KILL_BY_SELF,   // 撞到自己
	END_NORMAL      // 正常退出
};

//贪吃蛇的结构
typedef struct Snack
{
	pSnackNode s_pSnake;           // 指向蛇头结点的指针
	pSnackNode s_pFood;            // 指向食物结点的指针
	enum DIRACTION s_dir;          // 蛇的方向
	enum GAME_STATUS s_status;     // 游戏状态
	int s_food_score;              // 一个食物的分数
	int s_score;                   // 总分数
	int s_sleep_time;              // 休息时间越短速度越快，休息时间越长速度越慢
}Snack;

typedef struct Snack* pSnack;

//游戏的初始化
void GameStart(pSnack ps);

//欢迎界面的打印
void WelComToGame();

//绘制地图
void CreatMap();