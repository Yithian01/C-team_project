#ifndef __MAIN_H__
#define __MAIN_H__

// D.HERO �������
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


// define ���δ빮��  �Լ��� ù ���ں��� �빮���� ī�����̽� ������ ù ���ڴ� �ҹ����� ī�����̽� ����ü �Լ��� ����.

#define STATUS_X 90			//�������ͽ��� x��ġ
#define STATUS_Y 48			//�������ͽ��� y��ġ
#define BASIC_STATUS 5		//ó�� �������ͽ� ��ġ
#define PRAIM_X 111			//����â�� ����
#define TRUE 1			
#define FALSE 0
#define LEFT 75			
#define RIGHT 77
#define UP 72
#define DOWN 80 
#define ENTER 13


typedef struct {			// ĳ���� �⺻ ���� ����ü
	int b_str;
	int b_int;
	int b_dex;
	int b_luck;

} BASIC_CHAR;
	
typedef struct {			// �������� ���̵� ����ü
	int di_str;
	int di_int;
	int di_dex;
} STAGE_DIFF;


typedef struct item {		//�������� ��� ����ü
	int item_num;			//�������� ���� ��ȣ 
	int item_type[2];		// �������� Ÿ��
	char item_name[25];		// �������� �̸�
	char item_info[2][10];	//�������� ��� ����
	int item_stat[2];		// �������� ������ �ִ� �ɷ� 
	char item_mark[4];		// �������� ���

} ITEM;


typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;


int cnt;					// ī���Ͱ�
int stage_cnt;				// �������� ���� ����


int choice_pos;				// ���� �������� ��ġ ��ȣ
int item_see[3];			// ���� �������� ������ ������ ���� ��ġ 
char slot_item[50];			// ������ ���Կ� ������ ������ ������
ITEM item_now[3];			// ���� ����� ������ 3���� ���� 
		


int game_cnt;				// ������ �� 10���� ������Ҷ� �ʿ� 
int stage_clear;			// �������� ��� ���� ����

BASIC_CHAR cha;				//ó�� ĳ���� ����		// ���ο��� �����ΰ� �����ؼ� ������ ���



extern STAGE_DIFF STAGE_NUM[10];

extern char* story[10];				// �������� ���丮�� ������ ������ �迭 
extern char* story_pass_result[10]; // �� ������������ ���� �迭 
extern char* story_fail_result[10];	// �� ������������ ���� �迭  






void gotoxy(int x, int y);			// Ŀ�� ��ǥ���� �Լ� 
void setcursortype(CURSOR_TYPE c);	// Ŀ�� ����� �Լ� 
void add_Item(ITEM* item_box);		// �ؽ�Ʈ�� �ִ� ������ ����Ʈ�� �ű�� 


void reset();						// ������ �����Ҷ� ���� �ʱ�ȭ 
void title();						// Ÿ��Ʋ ȭ�� ����Լ� 
void print_Game();					//����Ʋ�� ���� �Լ�
void print_Ending();				//������ ���� �Լ� 


void choice_Stage(int *key_B);		// �������� �����ϴ� �Լ� 
void choice_Item(int *key_B);		// �������� �����ϴ� �Լ�
void choice_Start(int *key_B);		// ����,���Ḧ �����ϴ� �Լ� 

void print_Item(ITEM* item_box);	// �������� ���� �Լ�
void item_Change();					// ������ִ� �������� �ٲٴ� �Լ�
void change_Status(int item_value);	//�����ۿ� �ִ� ������ ���� ���ÿ� ���ϴ� �Լ�


void print_Stage();					// ���������� ���� �Լ�
void stage_Result(int stage_stat);  // ���� ���� ������� �Լ�
void print_Result(int value);		// ���� ��� ���ο� ���� ���â�� ���� �Լ�

#endif