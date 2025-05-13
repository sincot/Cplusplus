#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <locale.h>  // ���ַ�

//���͵����� �� ����������
 
// ����̰���ߵĽ��Ľṹ
typedef struct SnackNode
{
	//����
	int x;
	int y;

	//ָ��
	struct SnackNode* next;
}SnackNode;

typedef struct SnackNode* pSnackNode;

// ö�ٳ�̰���ߵ����з��� ���� �ϣ��£�����
enum DIRACTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

//�ߵ�״̬ ���� ������ײǽ��ײ���Լ��������˳�
enum GAME_STATUS
{
	OK,             // ������������ͣ��
	KILL_BY_WALL,   // ײǽ
	KILL_BY_SELF,   // ײ���Լ�
	END_NORMAL      // �����˳�
};

//̰���ߵĽṹ
typedef struct Snack
{
	pSnackNode s_pSnake;           // ָ����ͷ����ָ��
	pSnackNode s_pFood;            // ָ��ʳ�����ָ��
	enum DIRACTION s_dir;          // �ߵķ���
	enum GAME_STATUS s_status;     // ��Ϸ״̬
	int s_food_score;              // һ��ʳ��ķ���
	int s_score;                   // �ܷ���
	int s_sleep_time;              // ��Ϣʱ��Խ���ٶ�Խ�죬��Ϣʱ��Խ���ٶ�Խ��
}Snack;

typedef struct Snack* pSnack;

//��Ϸ�ĳ�ʼ��
void GameStart(pSnack ps);

//��ӭ����Ĵ�ӡ
void WelComToGame();

//���Ƶ�ͼ
void CreatMap();