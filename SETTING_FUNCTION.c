#define _CRT_SECURE_NO_WARNINGS
#include "main.h"


void add_Item(ITEM* item_box) {
	int i;
	ITEM *tmp_item_box[30] = {0};


	for (i = 0; i < 30; i++)
	{
		tmp_item_box[i] = item_box + i;
	}


	FILE* fp = NULL;
	fp = fopen("item_list.txt", "r");
	if (fp == NULL)
		printf("���� �ҷ����⸦ �����߽��ϴ�.");
	

	for (i = 0; i < 30; i++) {
		fscanf(fp, "%d %s %s %s %s %d %d %d %d", &tmp_item_box[i]->item_num, &tmp_item_box[i]->item_name[0], &tmp_item_box[i]->item_info[0], &tmp_item_box[i]->item_info[1], &tmp_item_box[i]->item_mark, &tmp_item_box[i]->item_type[0], &tmp_item_box[i]->item_type[1], &tmp_item_box[i]->item_stat[0], &tmp_item_box[i]->item_stat[1]);
		//fscanf(fp, "%d %s %s %s %d %d %s %d %d",&tmp_item_box[i]->item_num, &tmp_item_box[i]->item_name[0], &tmp_item_box[i]->item_info[0], &tmp_item_box[i]->item_info[1], &tmp_item_box[i]->item_type[0], &tmp_item_box[i]->item_type[i], &tmp_item_box[i]->item_mark, &tmp_item_box[i]->item_stat[0], &tmp_item_box[i]->item_stat[1]);
	}

	fclose(fp);

	//for (i = 0; i < 30; i++) {
	//	printf("%d %s %s %s %s %d %d %d %d\n", tmp_item_box[i]->item_num, tmp_item_box[i]->item_name, tmp_item_box[i]->item_info[0], tmp_item_box[i]->item_info[1], tmp_item_box[i]->item_mark, tmp_item_box[i]->item_type[0], tmp_item_box[i]->item_type[1], tmp_item_box[i]->item_stat[0], tmp_item_box[i]->item_stat[1]);
	////	//printf("%d %s\n", tmp_item_box[i]->item_num, tmp_item_box[i]->item_name, tmp_item_box[i]->item_info[0], tmp_item_box[i]->item_info[1], tmp_item_box[i]->item_type[0], tmp_item_box[i]->item_type[i], tmp_item_box[i]->item_mark, tmp_item_box[i]->item_stat[0], tmp_item_box[i]->item_stat[1]);

	//}

}

void reset()	// �ʱ�ȭ �Լ� 
{
	stage_clear = TRUE;								// �������� Ŭ���� �߳� Ȯ���ϴ� ī����

	cha.b_str = BASIC_STATUS;						// ü��
	cha.b_dex = BASIC_STATUS;						// ��ø
	cha.b_int = BASIC_STATUS;						// ����
	cha.b_luck = BASIC_STATUS - 4;					// ��

	game_cnt = 0;

	item_see[0] = 0;	//�������� ������ ���� 
	item_see[1] = 1;
	item_see[2] = 2;

	cnt = 0;										// ī���Ͱ�
	stage_cnt = 0;									// �������� ���� ����
	choice_pos = 0;									// ���� �������� ��ġ ��ȣ
	strcpy(slot_item, " ");
}



STAGE_DIFF STAGE_NUM[10] = {	// str , int , dex ����
	{3,200,100},				// 1��������	
	{2,200,2},					// 2�������� 
	{3,300,3},					// 3��������
	{4,400,4},					// 4��������
	{5,500,5},					// 5��������
	{6,600,6},					// 6��������
	{7,700,7},					// 7��������
	{8,800,8},					// 8��������
	{9,900,9},					// 9�������� 
	{50,47,56},					// 10��������
};



char* story[10] =
{
	// 1 stage	������	// �ο��.  ����Ѵ�. 
	"����� ������ ã�� ������ ������ �뺴�Դϴ�. �ֱ� ������ ��Ÿ�� ���� ����\n   ��               óġ�ϱ� ���� �� ������ �Ա��� �����߽��ϴ�.\n\n\n   ��               ����� ���������� ������ ì��� ���� ���� ���� ������ ���ϴ�.\n   ��               ���ɽ����� �߰����� �ű�� �� �ν����Ÿ��� �Ҹ��� �鸳�ϴ�.\n\n   ��               �ڼ��� ���� �������� ���谡�� ��ü�� �԰��ֽ��ϴ�.\n   ��               �Դ� ���� ������ �������� ����� ���� ��ġä�� ���ϰ� �ֽ��ϴ�.\n   ��               �����̶�� ������ �ص� ��ġä�� ���� �� ���ƺ��Դϴ�.\n\n\n   ��               '������'",
	// 2 stage	��	// �ο�� . ����Ѵ� , �����Ѵ�.
	"����� ���������� ����� ���� �������� �ֽ��ϴ�. ���� �� �������� ����\n   ��               �Ʒ������� �� ���� ��Ҹ��� �鸳�ϴ�.\n\n\n\n\n   ��               '��Ҹ�1: ũ����... ��... ��� �ż��� �ΰ� ������ ���� �ʾ�?'\n\n   ��               '��Ҹ�2: �ۛ�... ��! �Ʊ� ���� �׳� ����.. ��! �ƴϾ�?'\n\n   ��               '��Ҹ�1: �ƴϾ� .. ��! �и� ������ ���ٱ�.. ��! �������� �ѹ� ����..��!'\n\n\n\n\n   ��               ����� �ִ� ������ �߼Ҹ��� ���� ��������ϴ�.\n   ��               ��������� �׸��ڸ� ���� ������ �ֵ��̸� ���� ����� ����Դϴ�.",
	// 3 stage  ��ġ����	//str : �ο�� dex : ���Ѵ�. int : �����Ѵ�.
	"���� ���� �ȴ� �� ���� ���� �ɾ� �ִ� �ʶ��� ����� ������ ���Դϴ�.\n   ��               ������ �������� ������ ����� �ٶ󺸸� ���� �߾�Ÿ��ϴ�.\n\n\n\n   ��               '��� �� �׾���.... ���....�̷� ���� ,,,, �ƴϾ�'\n\n\n\n   ��               ����� ���ο��� �ٰ��� �������� �־��İ� ���� �̴ϴ�.\n   ��               ������ ����� �ٶ󺸸� ������ ���� �󱼷� ����� ���� �Ҹ�Ĩ�ϴ�.\n\n\n\n   ��               '�ƾƾƾ� �׾�!! !!�� ������!! �� ���� ���׾�!!!'\n\n\n\n   ��               ������ �Ŵ��� ���� ��� ����� ���� �ֵθ��ϴ�.",
	// 4 stage  �Ŵ� �Ź�
	"����� ���� ������ �� ������ �߰��߽��ϴ�.\n   ��               ����� �� ������ ���ɽ����� ���ϴ� .\n   ��               ���� �ȿ��� �ܶ� ������ ���̴� ������ �׿� �ֽ��ϴ�.\n   ��               ������ ���̴� ������ ì��� �ִ� �� �ü��� �������ϴ�.\n\n   ��               '�� ~~ ��'\n\n   ��               ���ڱ� ��� ����� ������ ��ü�� �������ϴ�.\n\n   ��               ����� �̾�ü�� ��� ���������� Ȯ���ϱ� ���� �÷��� ���ϴ�.\n\n\n\n   ��               !!!!!!!!!!!!!!!!\n\n\n   ��               ���� õ�忡�� ������ �Ź̿� �Ŵ��� ���� �Ź̰� �ֽ��ϴ�.\n\n   ��               'ļ ~~ �� ~~'\n\n   ��               ���հŹ̰� ������ ���� �Ź̵��� ����� ���� �����մϴ�. ",
	// 5 stage	��ũ����
	"������ ������ �������� ��� �����ϰ� ������ �̾�ϴ�.\n\n   ��               ����� ���ݱ��� ���� �������� �ؼ� ���� �ǰ����մϴ�.\n\n   ��               ����� �� ������ �߿����� ����� ������ �������ϴ�.\n\n   ��               ������ ����� ���� �ֺ����� �����ΰ��� ������ �޷����� �ֽ��ϴ�.\n\n   ��               ����� �����Ͼ ������ ������ϴ�.\n\n\n   ��               '###@!! @@# #####'\n\n\n   ��               ���� ������ ��� ������ �ѷ��Դϴ�.\n\n   ��               �� ���𰡴� �ٷ� ��ũ���������ϴ�.\n\n   ��               ��θӸ��� ���̴� ���� ������ ������\n\n   ��               ��ũ�������� ��ÿ��� ȭ���� ���ں��ϰ� �����ϴ�.",
	// 6 stage  �����̾�
	"����� ���� ���� �ȴٰ� �ϳ��� �Ŵ��� ���� �߰��߽��ϴ�.\n   ��               �Ŵ��� ���� �ٰ����� ���� �︮�鼭 �Ŵ��� ���� ������  �����߽��ϴ�.\n\n\n\n   ��               �Ŵ��� ���� �� ������ ����� ȣ��ɿ� �������� ���ϴ�.\n\n   ��               �Ŵ��� �� ���ʿ��� ������ �ܸ��� ���ڰ� ���ڿ� �ɾ� ����� �ٶ󺾴ϴ�.\n\n   ��               ���ڴ� ����� ���� �Ը��� �ٽø鼭 ���մϴ�.\n\n\n   ��               �ǹ��� ����:'����..�������� ���־� ���̴� �༮�� ���Ա���'\n\n   ��               ���� ��ģ ������ ��ü�� �Ǵ� �Դ� �����̾���ϴ�.\n\n   ��               �����̾�� ���� �ӵ��� ����� �ձ��� �Խ��ϴ�..",
	// 7 stage	��������Ʈ
	"����� ���������� �Ѿ�� ��� ��ó�� ġ���ϸ� �ڸ��� �ɽ��ϴ�.\n   ��               �޽��� ���� ����� ��ο� ����� �������� �Ŵ��� ���� ã�Ƴ½��ϴ�.\n\n\n\n   ��               ����� �Ŵ��� ���� �ٽ� ���� ���ϴ�.\n\n   ��               �Ŵ��� �� �� �ʿ��� ���� ������ �Ķ��ҵ��� �������ִ� �� �� \n   ��               �𵥵� ����� ��������Ʈ�� ���ֽ��ϴ�.\n\n   ��               'ö��.. ö��..'\n\n\n   ��               ��������Ʈ�� ���� ��� �ٴڿ� �������� ���·� ����� �ٶ󺾴ϴ�.\n\n\n\n   ��               ��������Ʈ�� ���� �Ҹ����� ���� ���� ��� �ڼ��� ���մϴ�.\n   ��               �ڼ��� ������ ��������Ʈ�� �����  ���ذ����ϱ� �����մϴ�..",
	// 8 stage  ��ġ
	"���� ������ �Ѿ�� ����� �ذ�鿡�� �ٷ� ������ �޾ҽ��ϴ�. \n   ��               ����� �ذ��� ���� ����� ���� ���ž��� �޸��ϴ�.\n\n\n\n\n   ��               �ذ���� �Ⱥ��϶� �� ����� ������ ������ ���� ���ϴ�.\n\n   ��               �տ��� ��ο� ����� �Ѹ��� ������ ���� ��ġ�� ���ֽ��ϴ�.\n\n   ��               ��ġ:'��������Ʈ��.. ����Ʈ���ٴ�.. �� �ϴ� ���̱���...'\n\n   ��               ��ġ:'���� ���� ������ ���� ���� ��ȸ�ϰ� ���ָ�!!!'\n\n\n\n   ��               ��ġ�� �ڽ��� �𵥵� ��ȯ������ ��ȯ�Ͽ� ����� �����մϴ�.",
	// 9 stage  ��������
	"���� ���� ������ ������ ����� ���������� ���� ���� �߰��߽��ϴ�.\n   ��               �� ���� ������ ũ���� ���ڰ� �����ְ� ���̰� �پ� �ֽ��ϴ�.\n\n\n\n\n   ��               ū ����: ���� �ִ� �ڸ��� ���� ���ϸ���\n\n   ��               �߰� ����: ���� �ִ� �ڸ��� ���� ���� �� �ִ�.\n\n   ��               ���� ����: �����ο� �ڸ��� ���� �� �� �ִ�.\n\n\n\n   ��               ��� ���ڸ� ������?",
	// 10 stage  �巡��
	"�Ӱ� ������ ���, Ŀ�ٶ� ����, ��� ���� ���� ����� ã�� ��޴� ���� �巡���Դϴ�.\n   ��               ���� �巡���� ����� ó�ٺ��� Ŀ�ٶ� ���� ���ϴ�.\n\n\n\n   ��               ���� �巡��:'�Ͼ�~~ �װ� �;� ã�ƿ� ���ΰ�?'\n\n   ��               ���� �巡���� ���¢���� ���� ���̸��ʴϴ�.\n\n   ��               �Ŵ��� �Ҳ��� ��ſ��� ���ؿɴϴ�.\n\n\n\n   ��               ����� ���и� ��� ����� ���Ƴ��ϴ�.\n\n   ��               ���� �巡��:'����...�� �ھ߰�..!!!\n\n   ��               ���� �巡���� ����� ����ִ� �Ϳ� ����ϴ�.\n\n   ��               ���� �巡���� ����� ���� ���� ���� �ٽ� �ѹ� ���� ���� ���ʴϴ�.\n\n   ��                ������ ������ ��ȸ�� ���Դϴ�."

};

char* story_pass_result[10] = {
	//1�������� ���
	"����� �������� �Դ� ���� �����ȸ� ���� ��� �ִ� ����� �����ƽ��ϴ�.\n\n   ��                 �Ӹ��� ���� ���� �������� �̳� ������ ������� �ֽ��ϴ�.\n\n   ��                 �������� ����� ���� ��ȭ���� ���� ���ǵ��� ���� �ֽ��ϴ�.\n\n   ��                 �νĵ��� ���� ���� �� ����� ������ �� ���� �� �����ϴ�.",
	//2�������� ���
	"����� ���� ������ �ö����� ��� �ڿ� ���� ħ���ϰ� ��ٸ��ϴ�.\n\n   ��                 ���� ����� ������ ���� �� ���ܳ��� �ܰ��� ���� �� �ƾ� �ֽ��ϴ�.\n\n   ��                 �׸��� ���� �ִ� �ܰ��� �̾� �ڿ� �ִ� �� �ٸ� ��� �����ϴ�.\n\n   ��                 '��...! �ΰ�! ����..' �ܰ��� ������ ���ư� ���� �̰��� �����մϴ�!\n\n   ��                 ���� �������� ����� �¸��߽��ϴ�. �������� ���� ������ �׿� �ֽ��ϴ�.\n\n   ��                 ������ ���� �����ϰ� �ִ� ���� ���� ���谡���� ��� ���� ���Դϴ�.",
	//3�������� ���
	"����� ���ƿ��� ���� ���ϰ� ������ ���� �ָ��� �����ϴ�.\n\n   ��                 ������ �ڷ� ���� ���� �Ӹ��� �ε�Ĩ�ϴ�.\n\n   ��                 '����... ���Ⱑ..�����? �и� �� �Ź̿���....'\n\n   ��                 ������ ���� ������ ����� �ٶ󺸸� �̾߱��մϴ�.\n\n   ��                 '�� �ڴ� �ſ� �����ϴٳ� ����� �Ʊ��ٸ� ���ư��Գ� ������'\n\n   ��                 '�׷��� ���߸� �ϰڴٸ� �� ������ ��������'\n\n   ��                 ������ ��ſ��� �ڽ��� ������ �ǳ��ϴ�.",
	//4�������� ���
	"����� ���� �Ź̵��� �޷���� ����� �ڷ� �������ϴ�.\n\n   ��                 ����� �Ź̸� ���������� ������ ������ ���� ����Ͽ� �Ź��ٿ� ���� ���ϴ�.\n\n   ��                 �Ź̿����� ��Ȳ���մϴ�.\n\n   ��                 ����� �Ź̿����� ��Ȳ�ϴ� ������ �����Ͽ� �Ź̿����� ���� �߶���ϴ�.\n\n   ��                 'Ű ~~ �� ... �� ..'\n\n   ��                 �Ź� ������ �������� �ٸ� �Ź̵��� ������ϴ�.\n\n   ��                 ����� ����ǰ�� ì��� ���� �����ϴ�.",
	//5�������� ���
	"����� �ڿ��� ������� ȭ���� ���� ���� ���մϴ�.\n\n   ��                 �ٽ� ȭ���� ������� ���з� ���Ƴ��� ��ũ�������� ������ �����մϴ�.\n\n   ��                 ���õ� �뺴�� ��ſ��� ��ũ������ ��밡 ���� �ʽ��ϴ�.\n\n\n   ��                 ��ũ�������� ����� ������ ���� ������ �ٶ󺾴ϴ�'\n\n\n   ��                 �ٴڿ� ��ũ������ ���� ���߱��� �ֽ��ϴ�.\n\n   ��                 ����� ��ũ�������� �������ִ� ������ ������ ì��� ������ ���ư��ϴ�.",
	//6�������� ���
	"����� ����� ħ���ϰ� �ٷ� �ձ��� �� �����̾ �����մϴ�.\n\n   ��                 �����̾��� ���� ������ ����� �ڷ� �̵��Ͽ� ����� �����մϴ�.\n\n   ��                 ����� �ڷ� ��¦ ���� ġ������ �������� �״��� ���� ��Ȳ�� �ƴմϴ�.\n\n   ��                 �����̾�� �Ǹ� ����Ͽ� ����ؼ� ����� �����մϴ�.\n\n   ��                 �����̾��� ������ ħ���ϰ� ���ϰ� �����̾ ���忡 �ϰ��� �����ϴ�..\n\n   ��                 �����̾� ���� ����� ���ϰ� ���� �翡�� �����̾ ���� �ִ� �������� �������ϴ�.",
	//7�������� ���
	"��������Ʈ�� ���� �÷� ��ſ��� ���� �ֵθ��ϴ�.\n\n   ��                 ����� ���� ����Ʈ�� ���� �޾Ƴ����� ���� ���̷����� �з����ϴ�.\n\n   ��                 ��������Ʈ�� ��ſ��� ������ �ð��� ���� ���� ���Դϴ�.\n\n   ��                 ����� ġ���� ���ݸ� ���ϸ鼭 ����� ���� �����ֽ��ϴ�.\n\n   ��                 ����� ��������Ʈ�� ������ ��Ƽ�ٰ� ��������Ʈ�� ��ƴ�� �߰��߽��ϴ�.\n\n   ��                 ����� ��ƴ�� �İ���� ��������Ʈ���� �¸��� �����ϴ�.\n\n   ��                 ��������Ʈ�� ���� ������ ������ ì�� ���������� ���ϴ�.",
	//8�������� ���
	"����� �ذ���� ó�������� �ذ��� ��ġ�� �������� ���Ӿ��� ��Ƴ��ϴ�.\n\n   ��                 ����� �̴�δ� �ȵǰڴٰ� �����Ͽ� ��ġ���� �����մϴ�.\n\n   ��                 ����� ��ġ�� ����� ������ ���ķ� ���ư��ϴ�.\n\n   ��                 ���ư� ���ķ� ��� ������ �������ϴ�.\n\n   ��                 ��ο� ����� ǰ�� �ִ� ���������� ���� �������ϴ�.\n\n   ��                 �� ����� ���� ��ġ�� ǥ���� ��¾�� ��ο� ���Դϴ�.\n\n   ��                 ����� ������ �ٰ��� ���ָ� �����ش� �ֹ��� ��Ĩ�ϴ�.\n\n   ��                 ���������� ���� ���ϰ� �ֺ��� ��� ���� ��ȭ���ѹ����ϴ�.",
	//9�������� ���
	"����� ���ڸ� �������ϴ�.\n\n\n   ��                 'ö��!! ��~~��~��!'\n\n\n   ��                 ���ڸ� ���� ������ ��ȭ�� �Բ� ���̰� ����ֽ��ϴ�.\n\n   ��                 '�ڰ��ִ� �� ������ ��������'\n\n   ��                 ������ ì��� ������ ���ư��ϴ�.",
	//10�������� ���
	"���� �巡���� ��ſ��� �ʹݿ� �� �극������ �� �����ϰ� ���� ���̸��ʴϴ�.\n\n   ��                 ����� ������ ����� ���� ������ Ÿ�� ���� �Ӹ����� �پ�����ϴ�.\n\n   ��                 �巡���� ���� ���� ���� �ھ� �ְ� �� ���� ���� ������ �ֽ��ϴ�.\n\n   ��                 ����� ������� ���鼭 ������ ���͸� ����߽��ϴ�.\n\n   ��                 �׸��� ���� ���� ���谡���� ���� ����� �� ���ϰ� ���־����ϴ�.\n\n   ��                 ����� ���� ���� ���� ���� ������ ���� �������ϴ�!!\n\n   ��                 ���� �巡��:'��..���.. �ΰ� ��������....'",

};

char* story_fail_result[10] = {
	//1�������� ���
	"����� ��� �ִ� ����� �������� ����ġ�� ������\n\n   ��                 �������� ��ġä�� ������ ����� ���� Ÿ���ö�ɴϴ�.\n\n   ��                 ��Ȳ�� ����� ���� ������� �̳� �������� ����� �Ӹ��� �Ծ�ġ��ϴ�.\n\n   ��                 �þ߰� ������ϴ�. ����� ������ ��������Դϴ�.",
	//2�������� ���
	"����� ���� ������ �ö����� ��� �ڿ� ���� ħ���ϰ� ��ٸ��ϴ�.\n\n   ��                 ���� ����� ������ ���� �� ���ܳ��� �ܰ��� ���� �� �ƾ� �ֽ��ϴ�.\n\n   ��                 �׸��� ���� �ִ� �ܰ��� �̾� �ڿ� �ִ� �� �ٸ� ��� �����ϴ�.\n\n   ��                 '��...! �ΰ�! ���δ�!!' �ܰ��� ���� �Ӹ��� �ƽ��� ���ܳ����ϴ�.\n\n   ��                 ���� â�� ��� ��ſ��� ������ ���忡 �ƾƳֽ��ϴ�.\n\n   ��                 ����� �ִ��� ���ߺ����� ���� ���� �����ϴ�. �� ���� ��ο����ϴ�.",
	//3�������� ���
	"����� ���ƿ��� ���� ���ϰ� ������ �����Ϸ� ���� �ɾ�ϴ�.\n\n   ��                 �׷����� ������ �Ҹ��� ������ ����ؼ� ���� �ֵθ��ϴ�.\n\n   ��                 '�׾��!! �̱�����!! �׾�!!'\n\n   ��                 ����� �ᱹ ������ �˿� ���� �߷� �׾����ϴ�.",
	//4�������� ���
	"������ ���ƿ��� �Ź̸� ���ϰ� �ݰ��� �ҷ��� ������ ���հŹ̰� �� �Ź��ٿ� ���� ���Դϴ�.\n\n   ��                 ����� �Ź��ٿ� ���� ���� ����� �ο����� ���ϰ� �Ź̿��� ���� ���� �ߵ��˴ϴ�.\n\n   ��                 ����� ���� �ߵ��Ǿ� �Ǹ� ���ϸ鼭 ������ ���� �ӿ��� ���� �����ϴ�.",
	//5�������� ���
	"����� ���� ��Ʋ�� ���� ������ ���� ����� ȭ���� �������ϴ�.\n\n   ��                 ȭ�쿡�� �߶��� �ִ� �������� ���� ���� ���� �������ϴ�.\n\n   ��                 �������� ��Ƽ���� ������ �������� �׷� ��ſ��� ȭ���� �����ϴ�.\n\n   ��                 �Ÿ��� ������ ���� ����� ȭ��� ���� �������մϴ�.\n\n   ��                 ����� ������ ��������Դϴ�.",
	//6�������� ���
	"�����̾�� ����� ������ �ͼ� �������� ����� �����մϴ�.\n\n   ��                 ����� ���� ȸ���Ͽ� �������� �����̾�� �Ǹ� â���� ����� ��ſ��� �������ϴ�.\n\n   ��                 ����� �Ƿ� ������� â�� ���ؼ� ���� ���� ä�� ���� �ֽ��ϴ�.\n\n   ��                 �����̾ ��ſ��� �ٰ��� ����� ���� ���� �Ǹ� ���� �����մϴ�.\n\n   ��                 �ǰ� �������� ����� �þߴ� ���� ������ϴ�.\n\n   ��                 ����� �����̾��� ������ �� ���Դϴ�.",
	//7�������� ���
	"����� ������ �����ϰ� ��������Ʈ�� ������ �¹޾� ������ ���� ���� �з����ϴ�.\n\n   ��                 ��������Ʈ�� ����� ���� ���� ���� ���Դϴ�.\n\n   ��                 ����� �̴�� ���ٰ��� �ȵǰڴ� �; �ϰ����� �ºθ� �������մϴ�.\n\n   ��                 ��������Ʈ�� ��ŵ� �ϰ��� �غ��մϴ�.\n\n   ��                 ���� �޷��� ���� �ֵθ��ϴ�.\n\n   ��                 ����� ���� �μ����� ����� �׽��ϴ�.",
	//8�������� ���
	"����� �ذ���� ó�������� �ذ��� ��ġ�� �������� ���Ӿ��� ��Ƴ��ϴ�.\n\n   ��                 ����� �ذ���� ó���ϸ鼭 ������ ���ư� ��ġ�� �տ� �����մϴ�.\n\n   ��                 ������ ����� ������ �ذ���� ó���ϸ鼭 �ͼ� ü���� ũ�� �Ҹ�� �����Դϴ�.\n\n   ��                 ��ġ�� �׷� ��ſ��� ���ָ� �ɾ� �ӹ��մϴ�.\n\n   ��                 ��ġ�� �̾ ������ â�� ����� ����� ���忡 �Ƚ��ϴ�.\n\n   ��                 ��ο� ����� ����� ���� ���� ���̷������� ���մϴ�.",
	//9�������� ���
	"����� ���ڸ� ������ �ϴµ� �� �������� �ʾҽ��ϴ�.\n\n   ��                 �׷��� �ٸ� ���ڸ� �������ϴ� ���� ���ڰ� ������ ����� �����մϴ�.\n\n   ��                 �߿����� ���� ������ ��ü�� �̹��̿����ϴ�.\n\n   ��                 �̹��� �̻��� �巯���� ����� �� �ƾƳֽ��ϴ�.\n\n   ��                 ����� ����� ������ �̹Ϳ��� �յ� ����� ����� ���� �׾����ϴ�.\n\n   ��                 ����� ������ ������� �Դϴ�.",
	//10�������� ���
	"���� �巡���� ��ſ��� �ʹݿ� �� �극������ �� �����ϰ� ���� ���̸��ʴϴ�.\n\n   ��                 ����� ������ ����� ���� ������ Ÿ�� ���� �Ӹ����� �پ�����ϴ�.\n\n   ��                 �巡���� ���� ���� ���� �ھ� �������� ���� ���� ������ ����� ��Ĩ�ϴ�.\n\n   ��                 ����� ������ �¾� ������ �ε��� ���� ������ �ҽ��ϴ�.\n\n   ��                 ������ ã�� ���� ���� �ٶ󺾴ϴ�.\n\n   ��                 ����巡��: 'ȭ��������������'\n\n   ��                 ���� �Ŵ��� �극���� ����� ��ġ�� ����� �Ҳɿ� ���� �� ���� �簡 �˴ϴ�.",
};
