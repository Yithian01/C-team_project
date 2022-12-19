#include "main.h"


void gotoxy(int x, int y)													// 콘솔창의 커서 위치를 옮기는 함수
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcursortype(CURSOR_TYPE c) {											// 커서의 모습을 숨기는 함수
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = 0;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}





void title()																// 타이틀 화면을 그리는 함수
{
	reset();																// 초기화 함수
	print_Game();															// 게임판 그리는 함수
	int title_x = 7;
	int title_y = 7;
	gotoxy(title_x, title_y); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(title_x, title_y + 1); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(title_x, title_y + 2); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(title_x, title_y + 3); printf("□□■■■■□□□□□□□□□□■■■■□□■■■■□■■■■■■□■■■■■■□□□□■■■□□□□");
	gotoxy(title_x, title_y + 4); printf("□□■■■■■■□□□□□□□□□■■□□□□■■□□■■■■■■□■■□□■■■□□■■■■■□□□");
	gotoxy(title_x, title_y + 5); printf("□□■■□□■■■■□□□□□□□■■□□□□■■□□■■□□□□□■■□□□■■□■■□□□■■□□");
	gotoxy(title_x, title_y + 6); printf("□□■■□□□□■■□□□■□□□■■■■■■■■□□■■□□□□□■■□□□■■□■■□□□■■□□");
	gotoxy(title_x, title_y + 7); printf("□□■■□□□□■■□□■■■□□■■■■■■■■□□■■■■■■□■■□□■■□□■■□□□■■□□");
	gotoxy(title_x, title_y + 8); printf("□□■■□□□□■■□□□■□□□■■□□□□■■□□■■■■■■□■■■■■□□□■■□□□■■□□");
	gotoxy(title_x, title_y + 9); printf("□□■■□□□□■■□□□□□□□■■□□□□■■□□■■□□□□□■■□□■■□□■■□□□■■□□");
	gotoxy(title_x, title_y + 10); printf("□□■■□□■■■■□□□□□□□■■□□□□■■□□■■□□□□□■■□□□■■□■■□□□■■□□");
	gotoxy(title_x, title_y + 11); printf("□□■■■■■■□□□□□□□□□■■□□□□■■□□■■■■■■□■■□□□■■□□■■■■■□□□");
	gotoxy(title_x, title_y + 12); printf("□□■■■■□□□□□□□□□□■■■■□□■■■■□■■■■■■□■■□□□■■□□□■■■□□□□");
	gotoxy(title_x, title_y + 13); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(title_x, title_y + 14); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(title_x, title_y + 15); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");

	gotoxy(36, 28); printf("▷"); printf("모험을 떠난다...");
	gotoxy(36, 32); printf("▷"); printf("끝내기");

}

void print_Game() {
	int i, j;
	for (j = 2; j <= 62;j++) {
		gotoxy(3, j);
		if (j == 2 || j == 62 || j == 42) {							 // y축의 좌표 3, 43 , 63에 
			for (i = 0; i < 55; i++) {								 // 54개의 네모를 출력
				printf("□");
			}
		}
		else
		{
			printf("□");											 // 그외의 경우는 3, j 좌표 와 111, j에 네모 출력 
			gotoxy(PRAIM_X, j);printf("□");

		}
	}

	gotoxy(12, 47); printf("▷");
	gotoxy(15, 47); printf("힘을 사용한다. ( STR : %d )", STAGE_NUM[stage_cnt].di_str);
	gotoxy(12, 49); printf("▷");
	gotoxy(15, 49); printf("재주를 사용한다. ( dex : %d )", STAGE_NUM[stage_cnt].di_dex);
	gotoxy(12, 51); printf("▷");
	gotoxy(15, 51); printf("지혜를 사용한다. ( int : %d )", STAGE_NUM[stage_cnt].di_int);



	gotoxy(12, 59); printf("◆");
	gotoxy(15, 59); printf("slot : %s ", slot_item);


	gotoxy(STATUS_X, STATUS_Y); printf("STR  : "); printf("%d", cha.b_str);
	gotoxy(STATUS_X, STATUS_Y + 2); printf("DEX  : "); printf("%d", cha.b_dex);
	gotoxy(STATUS_X, STATUS_Y + 4); printf("INT  : "); printf("%d", cha.b_int);
	gotoxy(STATUS_X, STATUS_Y + 6); printf("LUCK : "); printf("%d", cha.b_luck);
	cnt = 0;
}




void print_Ending()												// 엔딩을 출력하는 함수
{	
	system("cls");												// 화면을 지우는 함수														
	print_Game();												// 게임판을 그리는함수
	int title_x = 7;
	int title_y = 7;
	gotoxy(title_x, title_y); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(title_x, title_y + 1); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(title_x, title_y + 2); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(title_x, title_y + 3); printf("□□■■■■■■■□□■■■■□□■■■■■■■□□□□□□■■■■□□□□□□■■■■■■■□□□□");
	gotoxy(title_x, title_y + 4); printf("□■■■■■■■■■□□■■□□□■■■■■■■□□□□□■■■■■■□□□□■■■■■■■■■□□□");
	gotoxy(title_x, title_y + 5); printf("□■■□□□□□■■□□■■□□□■■□□□□□□□□□■■■□□■■■□□□■■■□□□■■■□□□");
	gotoxy(title_x, title_y + 6); printf("□■■□□□□□□□□□■■□□□■■□□□□□□□□■■■□□□□■■■□□■■■□□□■■■□□□");
	gotoxy(title_x, title_y + 7); printf("□■■□□□□□□□□□■■□□□■■■■■■■□□□■■■□□□□■■■□□■■■■■■■■■□□□");
	gotoxy(title_x, title_y + 8); printf("□■■□□□□□□□□□■■□□□■■■■■■■□□□■■■■■■■■■■□□■■■■■■■■□□□□");
	gotoxy(title_x, title_y + 9); printf("□■■□□□□□□□□□■■□□□■■□□□□□□□□■■■■■■■■■■□□■■■□□□■■■□□□");
	gotoxy(title_x, title_y + 10); printf("□■■□□□□□■■□□■■□□□■■□□□□□□□□■■■□□□□■■■□□■■■□□□□■■■□□");
	gotoxy(title_x, title_y + 11); printf("□■■■■■■■■■□□■■□□□■■■■■■■□□□■■■□□□□■■■□□■■■□□□□■■■□□");
	gotoxy(title_x, title_y + 12); printf("□□■■■■■■■□□■■■■□□■■■■■■■□□■■■■■□□■■■■■□■■■□□□□■■■□□");
	gotoxy(title_x, title_y + 13); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(title_x, title_y + 14); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(title_x, title_y + 15); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(12, 47); printf("☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆");
	gotoxy(12, 49); printf("☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆");
	gotoxy(12, 51); printf("☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆");


	gotoxy(36, 28); printf("▷ "); printf("타이틀 화면으로 돌아가기");
	gotoxy(36, 32); printf("▷ "); printf("끝내기");
	//gotoxy(7, 25); system("PAUSE");

}

void print_Item(ITEM *item_box) {									// 매개변수로 아이템이 저장된 배열의 주소값을 가져옴
	int i = 0;
	int j = 0;
	int check_item[3] = { 25,57,90 };								// 아이템 선택 창의 x좌표
	ITEM *ITEM_BOX[30] = { 0 };										// 포인터 변수를 선언하고 초기화

	for (i = 0; i < 30; i++)										// for문 사용해 하나하나 연결
	{
		ITEM_BOX[i] = item_box + i;
	}
	print_Game();													// 게임판 호출 함수

	gotoxy((PRAIM_X / 2) - 6, 10); printf("SELECT ITEM");			// 아이템 선택창 그리기
														
	gotoxy(12, 15);printf("□□□□□□□□□□□□□□");						//1 번째 슬롯
	for (i = 16; i <= 30; i++) {
		gotoxy(12, i);printf("□                        □");
	}
	gotoxy(12, 31);printf("□□□□□□□□□□□□□□");

	
	gotoxy(44, 15);printf("□□□□□□□□□□□□□□");						//2 번째 슬롯
	for (i = 16; i <= 30; i++) {
		gotoxy(44, i);printf("□                        □");

	}
	gotoxy(44, 31);printf("□□□□□□□□□□□□□□");

	
	gotoxy(76, 15);printf("□□□□□□□□□□□□□□");						//3 번째 슬롯 
	for (i = 16; i <= 30; i++) {
		gotoxy(76, i);printf("□                        □");

	}
	gotoxy(76, 31);printf("□□□□□□□□□□□□□□");
	for (i = 0; i < 3; i++) {
		gotoxy(check_item[i], 33); printf("△");

	}

	// 현재 보여질 아이템을 ITEM_BOX에 저장된 정보들을 꺼내와서 이름, 정보를 출력
	gotoxy(18, 18); printf("%s", ITEM_BOX[item_see[0]]->item_name); gotoxy(18, 22); printf("%s %d", ITEM_BOX[item_see[0]]->item_info[0], ITEM_BOX[item_see[0]]->item_stat[0]); gotoxy(18, 24); printf("%s %d", ITEM_BOX[item_see[0]]->item_info[1], ITEM_BOX[item_see[0]]->item_stat[1]);
	gotoxy(50, 18); printf("%s", ITEM_BOX[item_see[1]]->item_name); gotoxy(50, 22); printf("%s %d", ITEM_BOX[item_see[1]]->item_info[0], ITEM_BOX[item_see[1]]->item_stat[0]); gotoxy(50, 24); printf("%s %d", ITEM_BOX[item_see[1]]->item_info[1], ITEM_BOX[item_see[1]]->item_stat[1]);
	gotoxy(82, 18); printf("%s", ITEM_BOX[item_see[2]]->item_name); gotoxy(82, 22); printf("%s %d", ITEM_BOX[item_see[2]]->item_info[0], ITEM_BOX[item_see[2]]->item_stat[0]); gotoxy(82, 24); printf("%s %d", ITEM_BOX[item_see[2]]->item_info[1], ITEM_BOX[item_see[2]]->item_stat[1]);

	for (j = 0; j < 3; j++) {													// for문을 사용해 현재 아이템의 정보를 전역변수로 저장
		for (i = 0;i < 2;i++) {
			item_now[j].item_type[i] = ITEM_BOX[item_see[j]]->item_type[i];		//현재 아이템의 타입 저어보를 저장
			item_now[j].item_stat[i] = ITEM_BOX[item_see[j]]->item_stat[i];		//현재 아이템의 스탯 정보를 저장
			strcpy(item_now[j].item_mark, ITEM_BOX[item_see[j]]->item_mark);	//현재 아이템의 표시 정보를 저장
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

		gotoxy(22, 27); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
		gotoxy(22, 28); printf("□□□□□□□□□□□□□□□□■■□□□□□■□□□■□□□□□□□□");
		gotoxy(22, 29); printf("□□□■■■■■■■■□□□□■■■□□□■■□■■■□■■□□□□□□");
		gotoxy(22, 30); printf("□□□■■■□□■■■□□□■■■□□□■■■■□■□■■■■□□□□□");
		gotoxy(22, 31); printf("□□□■□□■■□□■□■■■■□□□□■■■■■□■■■■■□□□□□");
		gotoxy(22, 32); printf("□□□■□□■■□□■□■□■□□□□□■■■■□■□■■■■□□□□□");
		gotoxy(22, 33); printf("□□□■■■□□■■■□■■■□□□□□□□■□■□■□■□□□□□□□");
		gotoxy(22, 34); printf("□□□□■■□□■■□■■□□□□□□□□□■□■□■□■□□□□□□□");
		gotoxy(22, 35); printf("□□□□□■■■■□■■□□□□□□□□□□■□■■■□■□□□□□□□");
		gotoxy(22, 36); printf("□□□□□□□□□□□□□□□□□□□□□□■■■■■■■□□□□□□□");
		gotoxy(22, 37); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");

		gotoxy(22, 10); printf("%s\n\n   □                 ", story_pass_result[stage_cnt]);
		system("PAUSE");
		stage_cnt++;
		item_Change();

	}
	else {
		gotoxy((PRAIM_X / 2) - 3, 7); printf("YOU DIE");

		gotoxy(22, 27); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
		gotoxy(22, 28); printf("□□□■■■■■■■□□□□□□□□□□□□□■□□□□□□□□□□□□");
		gotoxy(22, 29); printf("□□■■□□□□□□■□□□□□□□□■□□■□□□□□□□□□□□□□");
		gotoxy(22, 30); printf("□□■■□■■■■□■□□□□□□□□□■■□□□□□□□□□□□□□□");
		gotoxy(22, 31); printf("□□■■□□□□□□□■□□□□□□□■■■□□□□□□□□□□□□□□");
		gotoxy(22, 32); printf("□□■■□■■■■□□■□□□□□□■■■□■□□□□□□■■□□□□□");
		gotoxy(22, 33); printf("□□■■□□□□□□□■□□□□□■■■□□□□□□□□□■■□□□□□");
		gotoxy(22, 34); printf("□□■■□■■■■□□■□□□□■■■□□□□□□□□□■□□□□□□□");
		gotoxy(22, 35); printf("□□■■□□□□□□□■□□■■■■■■■■■■■■□□■□□□□□□□");
		gotoxy(22, 36); printf("□□■■■■■■■■■■■■■■■■■■■■■■■■■□■□□□□□□□");
		gotoxy(22, 37); printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");

		gotoxy(22, 10); printf("%s\n\n   □                 ", story_fail_result[stage_cnt]);
		system("PAUSE");
		stage_clear = FALSE;
		//gotoxy(50, 62);
		//exit(1);
	}

}