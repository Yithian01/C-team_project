#include "main.h"	

// define ���δ빮��  �Լ��� ù ���ں��� �빮���� ī�����̽� ������ ù ���ڴ� �ҹ����� ī�����̽� ����ü �Լ��� ����.

int main() {
	system("mode con cols=116 lines=71");	// �ܼ�â ������ ���� ũ�� ����

	setcursortype(NOCURSOR);				// Ŀ�� ���ֱ�

	int key_value = 0;						// Ű���尪�� �Է¹޴� ����

	ITEM ITEM_BOX[30];						// �������� �ҷ��� ����ü �迭
	add_Item(ITEM_BOX);						// �������� �ҷ����� �Լ�

	
	do {
		title();							// Ÿ��Ʋ ȭ�� ���� 
		choice_Start(&key_value);			// ���ӽ��� ���� �Լ�

		for (game_cnt = 0;game_cnt < 10; game_cnt++) {
			print_Item(ITEM_BOX);			// ������ ���� ȭ�� ����
			choice_Item(key_value);			// ������ ���� �Լ�
				
			print_Stage();					// �������� ȭ�� ����
			choice_Stage(key_value);		// ������ ����

			if (stage_clear == FALSE)		// �����ߴ��� üũ
				break;						// �������� ���������� Ÿ��Ʋȭ������ ���ư� 
			else if(game_cnt == 9)			// 10���������� ��� ������� ��� 
			{
				print_Ending();			// ���� ȭ�� ����
				choice_Start(&key_value); // �ٽ� �Ұ��� ����
				break;
			}

		}


	} while (1);	

	
	gotoxy(50, 62);
	return 0;
}