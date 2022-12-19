#include "main.h"


// 선택하는 기능을 모아놓은 함수들

void choice_Start(int *key_B) {												// 게임 시작, 종료 선택 함수 

	int check_start[2] = { 28,32 };											// 게임 시작 화면의 y선택 좌표
	int* key = &key_B;
	do
	{
		*key = 0;
		if (choice_pos < 0 || choice_pos > 1) {								// 예외 처리
			choice_pos = 0;
		}
		gotoxy(36, check_start[choice_pos]); printf("▶");					// 해당 위치에 꽉 찬 선택기호 출력

		if (kbhit()) {														// 키보드 입력값 확인
			*key = getch();													// 키보드값 받는다.
			if (*key == 224) {												// 방향키값을 받으면 통과
				do { *key = getch(); } while (*key == 224);					// 특정 방향키값 받기
				switch (*key) {
				case DOWN:													// 아래 방향키를 누를 시
					choice_pos++;											// 위치 조절 전역변수값을 올리고
					gotoxy(36, check_start[choice_pos - 1]); printf("▷");   // 전의 위치에 빈 칸을 출력
					break;
				
				case UP:													// 위의 방향키를 누를 시
					choice_pos--;											// 위치 조절 전역변수값 내리고
					gotoxy(36, check_start[choice_pos + 1]); printf("▷");	// 전의 위치에 빈 칸을 출력
				}
			}
			else {															// 누른 키가 방향키 값이 아니었을 경우
				switch (*key) {
				case ENTER:													// 엔터키를 누를 경우
					if (choice_pos == 0) {									// 만약 시작하기를 선택한 경우 게임 진행
						cnt++;												// 탈출
						break;
					}
					else {													// 종료하기 선택지 선택 시 
						gotoxy(0, 0);										// 좌표 이동 후
						exit(1);											// 시스템 종료
					}
				}
			}
		}

	} while (cnt == 0);
	system("cls");
}

void choice_Stage(int *key_B) {												// 선택지 선택 함수 

	int check_choice[3] = { 47 ,49 , 51 };									// 선택지의 선택  y좌표
	int* key = &key_B;														// 포인터 변수를 선언하고 매개변수로 가져온 주소값과 연결

	do
	{
		*key = 0;
		if (choice_pos < 0 || choice_pos > 2) {								// 예외 처리
			choice_pos = 0;
		}
		gotoxy(12, check_choice[choice_pos]); printf("▶");					// 현재 위치에 꽉 찬칸을 출력


		if (kbhit()) {														// 키보드 입력값 확인
			*key = getch();													// 키보드값 받는다.
			if (*key == 224) {												// 방향키값을 받으면 통과
				do { *key = getch(); } while (*key == 224);					// 특정 방향키값 받기
				switch (*key) {								
				case DOWN:													// 아래 방향키를 누를 시
					choice_pos++;											// 위치 조절 전역변수값을 올리고
					gotoxy(12, check_choice[choice_pos - 1]); printf("▷");	// 전의 위치에 빈 칸을 출력
					break;
				
				case UP:													// 위의 방향키를 누를 시
					choice_pos--;											// 위치 조절 전역변수값 내리고
					gotoxy(12, check_choice[choice_pos + 1]); printf("▷");	// 전의 위치에 빈 칸을 출력
					break;
				}
			}
			else {															// 누른 키가 방향키 값이 아니었을 경우
				switch (*key) {	
				case ENTER:													// 엔터키를 누를 경우
					stage_Result(choice_pos);								// 결과값을 가지고 출력 함수로 간다.
					system("cls");											// 모든 창을 지우는 함수
					cnt++;													// cnt 값을 올려 탈출
					break;
				}
			}
		}
	} while (cnt == 0);
}

void choice_Item(int *key_B) {												// 아이템 선택 함수
	int check_item[3] = { 25,57,90 };										// 아이템 선택 창의 x좌표
	int* key = &key_B;														// main함수에서 가져온 key변수와 연결된 포인터와 연결 
	do
	{
		*key = 0;															// 처음 키값을 0으로 초기화 
		if (choice_pos < 0 || choice_pos > 2) {								// 현재 위치를 가리키는 0~2 중에 벗어 났다면 0으로 간다. 
			choice_pos = 0;
		}
		gotoxy(check_item[choice_pos], 33); printf("▲");					// x , y좌표가 {25,57,90}, 33으로 이동하고 출력

		if (kbhit()) {														// 키보드의 입력이 있다면 내부로 진입
			*key = getch();													// 키보드의 입력값을 키값에 아스키코드로 넣는다.
			if (*key == 224) {												// 키보드 방향키를 눌렀을 때 반환되는 값
				do { *key = getch(); } while (*key == 224);					// 방향키값을 얻었을때 반복문 탈출 
				switch (*key) {												// 얻은 키값을 넣는다.
				
				case RIGHT:													// 오른쪽 키보드를 눌렀을 때
					choice_pos++;											// x축 좌표를 하나 올린다.
					gotoxy(check_item[choice_pos - 1], 33); printf("△");	//전에 있던 x축 좌표에 빈칸을 넣는다.
					break;
				
				case LEFT:													// 왼쪽 키보드를 눌렀을 때
					choice_pos--;											// x축 좌표를 하나 내린다.
					gotoxy(check_item[choice_pos + 1], 33); printf("△");	// 전에 있던 x축 좌표에 빈칸을 넣는다.
					break;

				}
			}
			else {															// 키보드 방향기가 아닌 값을 눌렀을때
				if (*key == ENTER) {										// 그 값이 엔터값이라면
					system("cls");											// 화면 지우고
					change_Status(choice_pos);								// 캐릭터 스탯을 변화시키는 함수
					strcat(slot_item, item_now[choice_pos].item_mark);		// 먹은 아이템을 표시하는 char형 배열에 그 문양을 넣는다.
					strcat(slot_item, " ");									// 뒤에 공백 한칸 표시 

					cnt++;													// 카운터값을 올려 do-while문 탈출
				}
			}
		}
	} while (cnt == 0);														
}
