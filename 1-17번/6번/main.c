/* 문제6 적립금 프로그램을 만드시오.
힌트
a. 처음 통장 잔고 금액과 현재 적립금액을 보여준다.
b. 구매할 물건의 가격을 입력 받는다.
c. 적립금 사용여부를 묻는다.
c-1. 사용 -> 적립금 얼마 있는지 알려준다.
사용할 적립금액 입력.
입력한 값만큼 차감.
예외처리) 사용 가능한 적립금 > 입력 값 경우에만,
c-2. 적립 -> 구매금액의 일정금액(5%)를 적립.
d. 현재 남아있는 적립금의 양을 보여준다.

요구 사항
a. 파일 입출력으로 풀어야 하며, 2개의 파일을 필요로 한다.
(통장 잔고 금액 파일과 적립금액 파일)
*/
#include <stdio.h>
#include <stdlib.h>
#define SAVING_RATIO 0.05
int main()
{
	int balance, /* 잔액 */
		reserve, /* 적립금 */
		purchace_price, /* 구매 가격 */
		desired_amount; /* 사용할 적립금 */
	char choice; // 적립금 사용 여부 
	FILE * fp_b, /* balance.txt를 대상으로 하는 <파일 구조체 포인터> */
		*fp_r; /* reserve.txt를 대상으로 하는 <파일 구조체 포인터> */

	// 파일을 read-only 모드로 열기
	fopen_s(&fp_b, "balance.txt", "r");
	fopen_s(&fp_r, "reserve.txt", "r");

	// 파일 오픈시 에러 처리
	if (fp_b == NULL || fp_r == NULL){
		printf("balance.txt 또는 reserve.txt 파일 open 실패!");
		return -1;
	}

	// 파일 내용을 읽어서 변수에 쓰기
	fscanf_s(fp_b, "%d", &balance);
	fscanf_s(fp_r, "%d", &reserve);

	// 파일 연결 종료
	fclose(fp_b);
	fclose(fp_r);


	printf("\n\t[ 적립금 프로그램 ]\n\n");
	printf("...현재 통장 잔고 : %d원, 적립금 : %d원\n", balance, reserve);

	// 구매 가격 입력 부분 -예외처리(o)
	while (1)
	{
		printf("구매하실 물건의 가격 : ");
		scanf_s("%d", &purchace_price);
		if (balance < purchace_price)
			printf("현재 통장 잔고가 부족합니다. 구매하실 물건의 가격을 다시 입력해주세요.\n");
		else
			break;
	}

	// 적립금 사용 여부 입력 부분 -예외처리(o)
	while (1)
	{
		printf("적립금을 사용하시겠습니까?\n->->");
		fflush(stdin);
		scanf_s("%c", &choice);
		if (choice == 'y' || choice == 'n' || choice == 'Y' || choice == 'N')
		{
			switch (choice)
			{
			case 'y':
			case 'Y':
				// 사용할 적립금액 입력 부분 -예외처리(o)
				while (1)
				{
					printf("사용하실 적립금을 입력하세요 : ");
					scanf_s("%d", &desired_amount);
					if (reserve < desired_amount)
						printf("현재 사용가능한 적립금 잔액이 부족합니다. 사용하실 적립금 양을 다시 입력해주세요.\n");
					else
						break;
				}
				// 데이타 갱신을 위해 파일을 write모드로 열어서 이전 파일을 덮어쓰기
				fopen_s(&fp_b,"balance.txt", "w");
				fopen_s(&fp_r, "reserve.txt", "w");

				// 변수 값을 파일에 쓰기
				fprintf(fp_r, "%d", reserve - desired_amount);
				fprintf(fp_b, "%d", balance - (purchace_price - desired_amount));

				printf("적립금 사용하셔서 %d원 결제 되었습니다.\n", purchace_price - desired_amount);
				break;
			case 'n':
			case 'N':
				// 데이타 갱신을 위해 파일을 write모드로 열어서 이전 파일을 덮어쓰기
				fopen_s(&fp_b, "balance.txt", "w");
				fopen_s(&fp_r, "reserve.txt", "w");

				// 변수 값을 파일에 쓰기
				fprintf(fp_r, "%d", reserve + (int)(purchace_price * SAVING_RATIO));
				fprintf(fp_b, "%d", balance - purchace_price);

				printf("%d원 적립되었습니다\n", (int)(purchace_price * SAVING_RATIO));
				break;
			}
			// 파일내 데이타를 가리키는 포인터를 첫부분으로 복귀 
			fseek(fp_b, 0, SEEK_SET);
			fseek(fp_r, 0, SEEK_SET);

			// 첫 부분으로 복귀된 포인터를 이용해 문자열을 읽어서 정수로 변환후 모니터로 출력
			fprintf(stdout, "\n\n... 현재 통장 잔고 : %d원, 적립금 : %d원\n", strtol(fp_b->_ptr, NULL, 10), strtol(fp_r->_ptr, NULL, 10));

			// 파일 연결 종료
			fclose(fp_b);
			fclose(fp_r);
			break;
		}
		else
			printf("다시 입력하세요!\n");
	}


	return 0;
}