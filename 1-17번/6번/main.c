/* ����6 ������ ���α׷��� ����ÿ�.
��Ʈ
a. ó�� ���� �ܰ� �ݾװ� ���� �����ݾ��� �����ش�.
b. ������ ������ ������ �Է� �޴´�.
c. ������ ��뿩�θ� ���´�.
c-1. ��� -> ������ �� �ִ��� �˷��ش�.
����� �����ݾ� �Է�.
�Է��� ����ŭ ����.
����ó��) ��� ������ ������ > �Է� �� ��쿡��,
c-2. ���� -> ���űݾ��� �����ݾ�(5%)�� ����.
d. ���� �����ִ� �������� ���� �����ش�.

�䱸 ����
a. ���� ��������� Ǯ��� �ϸ�, 2���� ������ �ʿ�� �Ѵ�.
(���� �ܰ� �ݾ� ���ϰ� �����ݾ� ����)
*/
#include <stdio.h>
#include <stdlib.h>
#define SAVING_RATIO 0.05
int main()
{
	int balance, /* �ܾ� */
		reserve, /* ������ */
		purchace_price, /* ���� ���� */
		desired_amount; /* ����� ������ */
	char choice; // ������ ��� ���� 
	FILE * fp_b, /* balance.txt�� ������� �ϴ� <���� ����ü ������> */
		*fp_r; /* reserve.txt�� ������� �ϴ� <���� ����ü ������> */

	// ������ read-only ���� ����
	fopen_s(&fp_b, "balance.txt", "r");
	fopen_s(&fp_r, "reserve.txt", "r");

	// ���� ���½� ���� ó��
	if (fp_b == NULL || fp_r == NULL){
		printf("balance.txt �Ǵ� reserve.txt ���� open ����!");
		return -1;
	}

	// ���� ������ �о ������ ����
	fscanf_s(fp_b, "%d", &balance);
	fscanf_s(fp_r, "%d", &reserve);

	// ���� ���� ����
	fclose(fp_b);
	fclose(fp_r);


	printf("\n\t[ ������ ���α׷� ]\n\n");
	printf("...���� ���� �ܰ� : %d��, ������ : %d��\n", balance, reserve);

	// ���� ���� �Է� �κ� -����ó��(o)
	while (1)
	{
		printf("�����Ͻ� ������ ���� : ");
		scanf_s("%d", &purchace_price);
		if (balance < purchace_price)
			printf("���� ���� �ܰ� �����մϴ�. �����Ͻ� ������ ������ �ٽ� �Է����ּ���.\n");
		else
			break;
	}

	// ������ ��� ���� �Է� �κ� -����ó��(o)
	while (1)
	{
		printf("�������� ����Ͻðڽ��ϱ�?\n->->");
		fflush(stdin);
		scanf_s("%c", &choice);
		if (choice == 'y' || choice == 'n' || choice == 'Y' || choice == 'N')
		{
			switch (choice)
			{
			case 'y':
			case 'Y':
				// ����� �����ݾ� �Է� �κ� -����ó��(o)
				while (1)
				{
					printf("����Ͻ� �������� �Է��ϼ��� : ");
					scanf_s("%d", &desired_amount);
					if (reserve < desired_amount)
						printf("���� ��밡���� ������ �ܾ��� �����մϴ�. ����Ͻ� ������ ���� �ٽ� �Է����ּ���.\n");
					else
						break;
				}
				// ����Ÿ ������ ���� ������ write���� ��� ���� ������ �����
				fopen_s(&fp_b,"balance.txt", "w");
				fopen_s(&fp_r, "reserve.txt", "w");

				// ���� ���� ���Ͽ� ����
				fprintf(fp_r, "%d", reserve - desired_amount);
				fprintf(fp_b, "%d", balance - (purchace_price - desired_amount));

				printf("������ ����ϼż� %d�� ���� �Ǿ����ϴ�.\n", purchace_price - desired_amount);
				break;
			case 'n':
			case 'N':
				// ����Ÿ ������ ���� ������ write���� ��� ���� ������ �����
				fopen_s(&fp_b, "balance.txt", "w");
				fopen_s(&fp_r, "reserve.txt", "w");

				// ���� ���� ���Ͽ� ����
				fprintf(fp_r, "%d", reserve + (int)(purchace_price * SAVING_RATIO));
				fprintf(fp_b, "%d", balance - purchace_price);

				printf("%d�� �����Ǿ����ϴ�\n", (int)(purchace_price * SAVING_RATIO));
				break;
			}
			// ���ϳ� ����Ÿ�� ����Ű�� �����͸� ù�κ����� ���� 
			fseek(fp_b, 0, SEEK_SET);
			fseek(fp_r, 0, SEEK_SET);

			// ù �κ����� ���͵� �����͸� �̿��� ���ڿ��� �о ������ ��ȯ�� ����ͷ� ���
			fprintf(stdout, "\n\n... ���� ���� �ܰ� : %d��, ������ : %d��\n", strtol(fp_b->_ptr, NULL, 10), strtol(fp_r->_ptr, NULL, 10));

			// ���� ���� ����
			fclose(fp_b);
			fclose(fp_r);
			break;
		}
		else
			printf("�ٽ� �Է��ϼ���!\n");
	}


	return 0;
}