#include "5-12.h"

void SetPos(short x, short y)
{
	// ��ñ�׼�����Ȩ��
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//��λ����λ��
	COORD pos = { x, y };
	SetConsoleCursorPosition(houtput, pos);
}

void WelComToGame()
{
	SetPos(14, 40);
	wprintf(L"��ӭ����̰����С��Ϸ\n");
	SetPos(14, 42);
	system("pause");
	system("cls");
	SetPos(40, 14);
	wprintf(L"�� ��.��.��.�� �����Ʒ��򣬰� F3 �����٣�F4 ����\n");
	SetPos(40, 15);
	wprintf(L"�����ܵõ����ߵķ���\n");

	SetPos(42, 20);
	system("pause");
}

void CreatMap()
{
	//��
	for (int i = 0; i < 29; i++)
	{
		wprintf(L"%lc", L'��');
	}

	//��
	SetPos(0, 26);
	for (int i = 0; i < 29; i++)
	{
		wprintf(L"%lc", L'��');
	}

	//��
	for (int i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", L'��');
	}

	//��
	for (int i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", L'��');
	}
}

void GameStart(pSnack ps)
{
	// 0. �����ô��ڵĴ�С���ٹ������
	system("mode con cols=100 lines=30");
	system("title ̰����");
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE); 
	CONSOLE_CURSOR_INFO CursorInfo;             // ���ع�����
	GetConsoleCursorInfo(houtput, &CursorInfo); // ��ȡ���ƹ����Ϣ
	CursorInfo.bVisible = false;                // ���ؿ���̨��Ϣ
	SetConsoleCursorInfo(houtput, &CursorInfo); // ���ÿ���̨���


	// 1. ��ӡ��ӭ����
	// 2. ���ܽ���
	WelComToGame();
	// 3. ���Ƶ�ͼ
	CreatMap();
	// 4. ������
	// 5. ����ʳ��
	// 6. ������Ϸ�������Ϣ
}