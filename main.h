#ifndef __MAIN_H__
#define __MAIN_H__

// D.HERO 헤더파일
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


// define 전부대문자  함수는 첫 글자부터 대문자인 카멜케이스 변수는 첫 문자는 소문자인 카멜케이스 구조체 함수랑 같다.

#define STATUS_X 90			//스테이터스의 x위치
#define STATUS_Y 48			//스테이터스의 y위치
#define BASIC_STATUS 5		//처음 스테이터스 수치
#define PRAIM_X 111			//게임창의 끝단
#define TRUE 1			
#define FALSE 0
#define LEFT 75			
#define RIGHT 77
#define UP 72
#define DOWN 80 
#define ENTER 13


typedef struct {			// 캐릭터 기본 스텟 구조체
	int b_str;
	int b_int;
	int b_dex;
	int b_luck;

} BASIC_CHAR;
	
typedef struct {			// 스테이지 난이도 구조체
	int di_str;
	int di_int;
	int di_dex;
} STAGE_DIFF;


typedef struct item {		//아이템의 기능 구조체
	int item_num;			//아이템의 고유 번호 
	int item_type[2];		// 아이템의 타입
	char item_name[25];		// 아이템의 이름
	char item_info[2][10];	//아이템의 기능 설명
	int item_stat[2];		// 아이템이 가지고 있는 능력 
	char item_mark[4];		// 아이템의 모양

} ITEM;


typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;


int cnt;					// 카운터값
int stage_cnt;				// 스테이지 변동 변수


int choice_pos;				// 현재 아이템의 위치 번호
int item_see[3];			// 지금 보여지는 세개의 아이템 값의 위치 
char slot_item[50];			// 아이템 슬롯에 보여질 선택한 아이템
ITEM item_now[3];			// 현재 저장된 아이템 3개의 값들 
		


int game_cnt;				// 게임은 총 10라운드 재시작할때 필요 
int stage_clear;			// 스테이지 통과 여부 변수

BASIC_CHAR cha;				//처음 캐릭터 스탯		// 메인에서 디파인값 복사해서 변수로 사용



extern STAGE_DIFF STAGE_NUM[10];

extern char* story[10];				// 스테이지 스토리를 저장한 포인터 배열 
extern char* story_pass_result[10]; // 각 스테이지별로 성공 배열 
extern char* story_fail_result[10];	// 각 스테이지별로 실패 배열  






void gotoxy(int x, int y);			// 커서 좌표지정 함수 
void setcursortype(CURSOR_TYPE c);	// 커서 숨기기 함수 
void add_Item(ITEM* item_box);		// 텍스트에 있는 아이템 리스트를 옮기기 


void reset();						// 게임이 시작할때 값들 초기화 
void title();						// 타이틀 화면 출력함수 
void print_Game();					//게임틀을 띄우는 함수
void print_Ending();				//엔딩을 띄우는 함수 


void choice_Stage(int *key_B);		// 선택지를 선택하는 함수 
void choice_Item(int *key_B);		// 아이템을 선택하는 함수
void choice_Start(int *key_B);		// 시작,종료를 선택하는 함수 

void print_Item(ITEM* item_box);	// 아이템을 띄우는 함수
void item_Change();					// 띄워져있는 아이템을 바꾸는 함수
void change_Status(int item_value);	//아이템에 있는 스탯을 원래 스택에 더하는 함수


void print_Stage();					// 스테이지를 띄우는 함수
void stage_Result(int stage_stat);  // 게임 내부 통과여부 함수
void print_Result(int value);		// 게임 결과 여부에 따라 결과창을 띄우는 함수

#endif