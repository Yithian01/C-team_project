#include "main.h"


void gotoxy(int x, int y)													// �ܼ�â�� Ŀ�� ��ġ�� �ű�� �Լ�
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcursortype(CURSOR_TYPE c) {											// Ŀ���� ����� ����� �Լ�
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = 0;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}





void title()																// Ÿ��Ʋ ȭ���� �׸��� �Լ�
{
	reset();																// �ʱ�ȭ �Լ�
	print_Game();															// ������ �׸��� �Լ�
	int title_x = 7;
	int title_y = 7;
	gotoxy(title_x, title_y); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 1); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 2); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 3); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 4); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 5); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 6); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 7); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 8); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 9); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 10); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 11); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 12); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 13); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 14); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 15); printf("����������������������������������������������������");

	gotoxy(36, 28); printf("��"); printf("������ ������...");
	gotoxy(36, 32); printf("��"); printf("������");

}

void print_Game() {
	int i, j;
	for (j = 2; j <= 62;j++) {
		gotoxy(3, j);
		if (j == 2 || j == 62 || j == 42) {							 // y���� ��ǥ 3, 43 , 63�� 
			for (i = 0; i < 55; i++) {								 // 54���� �׸� ���
				printf("��");
			}
		}
		else
		{
			printf("��");											 // �׿��� ���� 3, j ��ǥ �� 111, j�� �׸� ��� 
			gotoxy(PRAIM_X, j);printf("��");

		}
	}

	gotoxy(12, 47); printf("��");
	gotoxy(15, 47); printf("���� ����Ѵ�. ( STR : %d )", STAGE_NUM[stage_cnt].di_str);
	gotoxy(12, 49); printf("��");
	gotoxy(15, 49); printf("���ָ� ����Ѵ�. ( dex : %d )", STAGE_NUM[stage_cnt].di_dex);
	gotoxy(12, 51); printf("��");
	gotoxy(15, 51); printf("������ ����Ѵ�. ( int : %d )", STAGE_NUM[stage_cnt].di_int);



	gotoxy(12, 59); printf("��");
	gotoxy(15, 59); printf("slot : %s ", slot_item);


	gotoxy(STATUS_X, STATUS_Y); printf("STR  : "); printf("%d", cha.b_str);
	gotoxy(STATUS_X, STATUS_Y + 2); printf("DEX  : "); printf("%d", cha.b_dex);
	gotoxy(STATUS_X, STATUS_Y + 4); printf("INT  : "); printf("%d", cha.b_int);
	gotoxy(STATUS_X, STATUS_Y + 6); printf("LUCK : "); printf("%d", cha.b_luck);
	cnt = 0;
}




void print_Ending()												// ������ ����ϴ� �Լ�
{	
	system("cls");												// ȭ���� ����� �Լ�														
	print_Game();												// �������� �׸����Լ�
	int title_x = 7;
	int title_y = 7;
	gotoxy(title_x, title_y); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 1); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 2); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 3); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 4); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 5); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 6); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 7); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 8); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 9); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 10); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 11); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 12); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 13); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 14); printf("����������������������������������������������������");
	gotoxy(title_x, title_y + 15); printf("����������������������������������������������������");
	gotoxy(12, 47); printf("�١١١١١١١١١١١١١١١١١١١١١�");
	gotoxy(12, 49); printf("�١١١١١١١١١١١١١١١١١١١١١�");
	gotoxy(12, 51); printf("�١١١١١١١١١١١١١١١١١١١١١�");


	gotoxy(36, 28); printf("�� "); printf("Ÿ��Ʋ ȭ������ ���ư���");
	gotoxy(36, 32); printf("�� "); printf("������");
	//gotoxy(7, 25); system("PAUSE");

}

void print_Item(ITEM *item_box) {									// �Ű������� �������� ����� �迭�� �ּҰ��� ������
	int i = 0;
	int j = 0;
	int check_item[3] = { 25,57,90 };								// ������ ���� â�� x��ǥ
	ITEM *ITEM_BOX[30] = { 0 };										// ������ ������ �����ϰ� �ʱ�ȭ

	for (i = 0; i < 30; i++)										// for�� ����� �ϳ��ϳ� ����
	{
		ITEM_BOX[i] = item_box + i;
	}
	print_Game();													// ������ ȣ�� �Լ�

	gotoxy((PRAIM_X / 2) - 6, 10); printf("SELECT ITEM");			// ������ ����â �׸���
														
	gotoxy(12, 15);printf("���������������");						//1 ��° ����
	for (i = 16; i <= 30; i++) {
		gotoxy(12, i);printf("��                        ��");
	}
	gotoxy(12, 31);printf("���������������");

	
	gotoxy(44, 15);printf("���������������");						//2 ��° ����
	for (i = 16; i <= 30; i++) {
		gotoxy(44, i);printf("��                        ��");

	}
	gotoxy(44, 31);printf("���������������");

	
	gotoxy(76, 15);printf("���������������");						//3 ��° ���� 
	for (i = 16; i <= 30; i++) {
		gotoxy(76, i);printf("��                        ��");

	}
	gotoxy(76, 31);printf("���������������");
	for (i = 0; i < 3; i++) {
		gotoxy(check_item[i], 33); printf("��");

	}

	// ���� ������ �������� ITEM_BOX�� ����� �������� �����ͼ� �̸�, ������ ���
	gotoxy(18, 18); printf("%s", ITEM_BOX[item_see[0]]->item_name); gotoxy(18, 22); printf("%s %d", ITEM_BOX[item_see[0]]->item_info[0], ITEM_BOX[item_see[0]]->item_stat[0]); gotoxy(18, 24); printf("%s %d", ITEM_BOX[item_see[0]]->item_info[1], ITEM_BOX[item_see[0]]->item_stat[1]);
	gotoxy(50, 18); printf("%s", ITEM_BOX[item_see[1]]->item_name); gotoxy(50, 22); printf("%s %d", ITEM_BOX[item_see[1]]->item_info[0], ITEM_BOX[item_see[1]]->item_stat[0]); gotoxy(50, 24); printf("%s %d", ITEM_BOX[item_see[1]]->item_info[1], ITEM_BOX[item_see[1]]->item_stat[1]);
	gotoxy(82, 18); printf("%s", ITEM_BOX[item_see[2]]->item_name); gotoxy(82, 22); printf("%s %d", ITEM_BOX[item_see[2]]->item_info[0], ITEM_BOX[item_see[2]]->item_stat[0]); gotoxy(82, 24); printf("%s %d", ITEM_BOX[item_see[2]]->item_info[1], ITEM_BOX[item_see[2]]->item_stat[1]);

	for (j = 0; j < 3; j++) {													// for���� ����� ���� �������� ������ ���������� ����
		for (i = 0;i < 2;i++) {
			item_now[j].item_type[i] = ITEM_BOX[item_see[j]]->item_type[i];		//���� �������� Ÿ�� ����� ����
			item_now[j].item_stat[i] = ITEM_BOX[item_see[j]]->item_stat[i];		//���� �������� ���� ������ ����
			strcpy(item_now[j].item_mark, ITEM_BOX[item_see[j]]->item_mark);	//���� �������� ǥ�� ������ ����
		}
	}
}

void print_Stage() {
	print_Game();
	gotoxy((PRAIM_X / 2) - 3, 7); printf("STAGE %d", stage_cnt + 1);
	gotoxy(20, 12); printf("%s", story[stage_cnt]);
}

void print_Result(int value)
{

	print_Game();
	if (value == 1) {
		gotoxy((PRAIM_X / 2) - 3, 7); printf("STAGE CLEAR");

		gotoxy(22, 27); printf("�������������������������������������");
		gotoxy(22, 28); printf("�������������������������������������");
		gotoxy(22, 29); printf("�������������������������������������");
		gotoxy(22, 30); printf("�������������������������������������");
		gotoxy(22, 31); printf("�������������������������������������");
		gotoxy(22, 32); printf("�������������������������������������");
		gotoxy(22, 33); printf("�������������������������������������");
		gotoxy(22, 34); printf("�������������������������������������");
		gotoxy(22, 35); printf("�������������������������������������");
		gotoxy(22, 36); printf("�������������������������������������");
		gotoxy(22, 37); printf("�������������������������������������");

		gotoxy(22, 10); printf("%s\n\n   ��                 ", story_pass_result[stage_cnt]);
		system("PAUSE");
		stage_cnt++;
		item_Change();

	}
	else {
		gotoxy((PRAIM_X / 2) - 3, 7); printf("YOU DIE");

		gotoxy(22, 27); printf("�������������������������������������");
		gotoxy(22, 28); printf("�������������������������������������");
		gotoxy(22, 29); printf("�������������������������������������");
		gotoxy(22, 30); printf("�������������������������������������");
		gotoxy(22, 31); printf("�������������������������������������");
		gotoxy(22, 32); printf("�������������������������������������");
		gotoxy(22, 33); printf("�������������������������������������");
		gotoxy(22, 34); printf("�������������������������������������");
		gotoxy(22, 35); printf("�������������������������������������");
		gotoxy(22, 36); printf("�������������������������������������");
		gotoxy(22, 37); printf("�������������������������������������");

		gotoxy(22, 10); printf("%s\n\n   ��                 ", story_fail_result[stage_cnt]);
		system("PAUSE");
		stage_clear = FALSE;
		//gotoxy(50, 62);
		//exit(1);
	}

}