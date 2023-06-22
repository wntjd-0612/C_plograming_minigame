#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tetris.h"
int num_bb();
int rsp();
int main() {
    int n;
    printf("�Ͻ� ������ �Է��Ͻʽÿ�.\n 1, ���ھ߱�\n 2, ��Ʈ����\n 3, ���� ���� ��\n 4, �� ���ϱ�\n5, �º����� ����\n 6, �δ��� ����\n 7, Ȩ���� ����\n8, ���� ������\n");
    scanf_s("%d", &n);
    switch (n)
    {
    case(1): num_bb(); break;
    case(2):  tetris();  break;
    case(3): rsp();  break;
    }

}
int num_bb() {
    int answer[3];
    int guess[3];
    int strike = 0;
    int ball = 0;


    answer[0] = rand() % 9 + 1;
    do {
        answer[1] = rand() % 10;
    } while (answer[0] == answer[1]);
    do {
        answer[2] = rand() % 10;
    } while (answer[0] == answer[2] || answer[1] == answer[2]);

    printf("������ �����մϴ�!\n");


    while (strike != 3) {

        printf("3�ڸ� ���ڸ� �Է��ϼ��� (�ߺ� ����): ");
        scanf_s("%1d%1d%1d", &guess[0], &guess[1], &guess[2]);
        strike = 0;
        ball = 0;


        for (int i = 0; i < 3; i++) {
            if (guess[i] == answer[i]) {
                strike++;
            }
            else {
                for (int j = 0; j < 3; j++) {
                    if (guess[i] == answer[j]) {
                        ball++;
                        break;
                    }
                }
            }
        }


        printf("���: %d ��Ʈ����ũ, %d ��\n\n", strike, ball);
    }

    printf("�����մϴ�! ������ ���߼̽��ϴ�.\n");

    return 0;
}

int rsp() {
    int userChoice, computerChoice;

    printf("����(1), ����(2), ��(3) �� �ϳ��� �����ϼ���: ");
    scanf_s("%d", &userChoice);
    computerChoice = rand() % 3 + 1;
    printf("�����: ");
    switch (userChoice) {
    case 1:
        printf("����\n");
        break;
    case 2:
        printf("����\n");
        break;
    case 3:
        printf("��\n");
        break;
    default:
        printf("�߸��� ����\n");
        return 1;
    }

    printf("��ǻ��: ");
    switch (computerChoice) {
    case 1:
        printf("����\n");
        break;
    case 2:
        printf("����\n");
        break;
    case 3:
        printf("��\n");
        break;
    }


    if (userChoice == computerChoice) {
        printf("�����ϴ�!\n");
    }
    else if (
        (userChoice == 1 && computerChoice == 3) ||
        (userChoice == 2 && computerChoice == 1) ||
        (userChoice == 3 && computerChoice == 2)
        ) {
        printf("����ڰ� �̰���ϴ�!\n");
    }
    else {
        printf("��ǻ�Ͱ� �̰���ϴ�!\n");
    }

    return 0;
}
