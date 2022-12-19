#include "main.h"	

// define 전부대문자  함수는 첫 글자부터 대문자인 카멜케이스 변수는 첫 문자는 소문자인 카멜케이스 구조체 함수랑 같다.

int main() {
	system("mode con cols=116 lines=71");	// 콘솔창 열었을 때의 크기 지정

	setcursortype(NOCURSOR);				// 커서 없애기

	int key_value = 0;						// 키보드값을 입력받는 변수

	ITEM ITEM_BOX[30];						// 아이템을 불러올 구조체 배열
	add_Item(ITEM_BOX);						// 아이템을 불러오는 함수

	
	do {
		title();							// 타이틀 화면 띄우기 
		choice_Start(&key_value);			// 게임시작 선택 함수

		for (game_cnt = 0;game_cnt < 10; game_cnt++) {
			print_Item(ITEM_BOX);			// 아이템 선택 화면 띄우기
			choice_Item(key_value);			// 아이템 선택 함수
				
			print_Stage();					// 스테이지 화면 띄우기
			choice_Stage(key_value);		// 선택지 선택

			if (stage_clear == FALSE)		// 실패했는지 체크
				break;						// 스테이지 실패했으면 타이틀화면으로 돌아감 
			else if(game_cnt == 9)			// 10스테이지를 모두 통과했을 경우 
			{
				print_Ending();			// 엔딩 화면 띄우기
				choice_Start(&key_value); // 다시 할건지 선택
				break;
			}

		}


	} while (1);	

	
	gotoxy(50, 62);
	return 0;
}