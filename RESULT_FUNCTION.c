#include "main.h"

// 결과에 관련된 함수들 

void item_Change()													// 아이템 창에 띄울 아이템을 변경하는 아이템
{
	int i=0;
	for (i = 0; i < 3; i++) {
		item_see[i] += 3;											// 보여지는 아이템의 값을 올린다.
	}
}



void change_Status(int item_value)									// 캐릭터의 스탯을 변경하는 함수
{
	int i;
	int item_type[2] = {											// 아이템 타입을 두 개 읽어옴
		item_now[item_value].item_type[0],
		item_now[item_value].item_type[1]
	};
	for (i = 0; i < 2;i++) {										// 아이템 옵션은 두개이기 때문에 두번 반복
		switch (item_type[i])										
		{
		case 0:														// 아이템 타입이 0이면 힘스탯 변경
			cha.b_str += item_now[item_value].item_stat[i];			
			break;													
		case 1:														// 아이템 타입이 1이면 민첩스탯 변경
			cha.b_dex += item_now[item_value].item_stat[i];
			break;
		case 2:														// 아이템 타입이 2이면 지능스탯 변경
			cha.b_int += item_now[item_value].item_stat[i];
			break;
		case 3:														// 아이템 타입이 3이면 운스탯 변경
			cha.b_luck += item_now[item_value].item_stat[i];

		}
	}


}




void stage_Result(int stage_stat) {
	srand(time(NULL));												// 시간으로 난수 초기화
	
	int stage_value;
	int player_value;

	srand(time(NULL));
	switch (stage_stat) {

	case 0:
		stage_value = rand() % (STAGE_NUM[stage_cnt].di_str);
		player_value = rand() % cha.b_str;
		break;

	case 1:
		stage_value = rand() % (STAGE_NUM[stage_cnt].di_dex);
		player_value = rand() % cha.b_dex;

		break;

	case 2:
		stage_value = rand() % (STAGE_NUM[stage_cnt].di_int);
		player_value = rand() % cha.b_int;
		break;

	}

	system("cls");
	if (stage_value <= (player_value + cha.b_luck)) print_Result(TRUE);
	else print_Result(FALSE);
}

