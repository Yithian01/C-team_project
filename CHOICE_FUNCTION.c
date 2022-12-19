#include "main.h"


// �����ϴ� ����� ��Ƴ��� �Լ���

void choice_Start(int *key_B) {												// ���� ����, ���� ���� �Լ� 

	int check_start[2] = { 28,32 };											// ���� ���� ȭ���� y���� ��ǥ
	int* key = &key_B;
	do
	{
		*key = 0;
		if (choice_pos < 0 || choice_pos > 1) {								// ���� ó��
			choice_pos = 0;
		}
		gotoxy(36, check_start[choice_pos]); printf("��");					// �ش� ��ġ�� �� �� ���ñ�ȣ ���

		if (kbhit()) {														// Ű���� �Է°� Ȯ��
			*key = getch();													// Ű���尪 �޴´�.
			if (*key == 224) {												// ����Ű���� ������ ���
				do { *key = getch(); } while (*key == 224);					// Ư�� ����Ű�� �ޱ�
				switch (*key) {
				case DOWN:													// �Ʒ� ����Ű�� ���� ��
					choice_pos++;											// ��ġ ���� ������������ �ø���
					gotoxy(36, check_start[choice_pos - 1]); printf("��");   // ���� ��ġ�� �� ĭ�� ���
					break;
				
				case UP:													// ���� ����Ű�� ���� ��
					choice_pos--;											// ��ġ ���� ���������� ������
					gotoxy(36, check_start[choice_pos + 1]); printf("��");	// ���� ��ġ�� �� ĭ�� ���
				}
			}
			else {															// ���� Ű�� ����Ű ���� �ƴϾ��� ���
				switch (*key) {
				case ENTER:													// ����Ű�� ���� ���
					if (choice_pos == 0) {									// ���� �����ϱ⸦ ������ ��� ���� ����
						cnt++;												// Ż��
						break;
					}
					else {													// �����ϱ� ������ ���� �� 
						gotoxy(0, 0);										// ��ǥ �̵� ��
						exit(1);											// �ý��� ����
					}
				}
			}
		}

	} while (cnt == 0);
	system("cls");
}

void choice_Stage(int *key_B) {												// ������ ���� �Լ� 

	int check_choice[3] = { 47 ,49 , 51 };									// �������� ����  y��ǥ
	int* key = &key_B;														// ������ ������ �����ϰ� �Ű������� ������ �ּҰ��� ����

	do
	{
		*key = 0;
		if (choice_pos < 0 || choice_pos > 2) {								// ���� ó��
			choice_pos = 0;
		}
		gotoxy(12, check_choice[choice_pos]); printf("��");					// ���� ��ġ�� �� ��ĭ�� ���


		if (kbhit()) {														// Ű���� �Է°� Ȯ��
			*key = getch();													// Ű���尪 �޴´�.
			if (*key == 224) {												// ����Ű���� ������ ���
				do { *key = getch(); } while (*key == 224);					// Ư�� ����Ű�� �ޱ�
				switch (*key) {								
				case DOWN:													// �Ʒ� ����Ű�� ���� ��
					choice_pos++;											// ��ġ ���� ������������ �ø���
					gotoxy(12, check_choice[choice_pos - 1]); printf("��");	// ���� ��ġ�� �� ĭ�� ���
					break;
				
				case UP:													// ���� ����Ű�� ���� ��
					choice_pos--;											// ��ġ ���� ���������� ������
					gotoxy(12, check_choice[choice_pos + 1]); printf("��");	// ���� ��ġ�� �� ĭ�� ���
					break;
				}
			}
			else {															// ���� Ű�� ����Ű ���� �ƴϾ��� ���
				switch (*key) {	
				case ENTER:													// ����Ű�� ���� ���
					stage_Result(choice_pos);								// ������� ������ ��� �Լ��� ����.
					system("cls");											// ��� â�� ����� �Լ�
					cnt++;													// cnt ���� �÷� Ż��
					break;
				}
			}
		}
	} while (cnt == 0);
}

void choice_Item(int *key_B) {												// ������ ���� �Լ�
	int check_item[3] = { 25,57,90 };										// ������ ���� â�� x��ǥ
	int* key = &key_B;														// main�Լ����� ������ key������ ����� �����Ϳ� ���� 
	do
	{
		*key = 0;															// ó�� Ű���� 0���� �ʱ�ȭ 
		if (choice_pos < 0 || choice_pos > 2) {								// ���� ��ġ�� ����Ű�� 0~2 �߿� ���� ���ٸ� 0���� ����. 
			choice_pos = 0;
		}
		gotoxy(check_item[choice_pos], 33); printf("��");					// x , y��ǥ�� {25,57,90}, 33���� �̵��ϰ� ���

		if (kbhit()) {														// Ű������ �Է��� �ִٸ� ���η� ����
			*key = getch();													// Ű������ �Է°��� Ű���� �ƽ�Ű�ڵ�� �ִ´�.
			if (*key == 224) {												// Ű���� ����Ű�� ������ �� ��ȯ�Ǵ� ��
				do { *key = getch(); } while (*key == 224);					// ����Ű���� ������� �ݺ��� Ż�� 
				switch (*key) {												// ���� Ű���� �ִ´�.
				
				case RIGHT:													// ������ Ű���带 ������ ��
					choice_pos++;											// x�� ��ǥ�� �ϳ� �ø���.
					gotoxy(check_item[choice_pos - 1], 33); printf("��");	//���� �ִ� x�� ��ǥ�� ��ĭ�� �ִ´�.
					break;
				
				case LEFT:													// ���� Ű���带 ������ ��
					choice_pos--;											// x�� ��ǥ�� �ϳ� ������.
					gotoxy(check_item[choice_pos + 1], 33); printf("��");	// ���� �ִ� x�� ��ǥ�� ��ĭ�� �ִ´�.
					break;

				}
			}
			else {															// Ű���� ����Ⱑ �ƴ� ���� ��������
				if (*key == ENTER) {										// �� ���� ���Ͱ��̶��
					system("cls");											// ȭ�� �����
					change_Status(choice_pos);								// ĳ���� ������ ��ȭ��Ű�� �Լ�
					strcat(slot_item, item_now[choice_pos].item_mark);		// ���� �������� ǥ���ϴ� char�� �迭�� �� ������ �ִ´�.
					strcat(slot_item, " ");									// �ڿ� ���� ��ĭ ǥ�� 

					cnt++;													// ī���Ͱ��� �÷� do-while�� Ż��
				}
			}
		}
	} while (cnt == 0);														
}
