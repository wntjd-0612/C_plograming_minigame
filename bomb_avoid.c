#include <stdio.h>
#include <conio.h>
#include <windows.h> // Windows���� �ð� ������ ���� ���

#define MAP_WIDTH 20  // ���� �� ���� ����
#define MAP_HEIGHT 15 // ���� �� ���� ����

void bomb_gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void bomb_drawMap(int playerX, int playerY, int bombX[], int bombY[], int numBombs) {
    system("cls"); // ȭ���� ����� ���� �׸���

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (x == playerX && y == playerY) {
                printf("\033[1;32m@\033[0m"); // ĳ���� (@)
            }
            else {
                int isBomb = 0;
                for (int i = 0; i < numBombs; i++) {
                    if (x == bombX[i] && y == bombY[i]) {
                        isBomb = 1;
                        break;
                    }
                }
                if (isBomb) {
                    printf("\033[1;31m#\033[0m"); // ��ź (#)
                }
                else {
                    printf("."); // �� ����
                }
            }
        }
        printf("\n");
    }
}

int bomb() {
    int key;
    int playerX = MAP_WIDTH / 2; // ĳ������ �ʱ� X ��ǥ
    int playerY = MAP_HEIGHT - 1; // ĳ������ �ʱ� Y ��ǥ

    const int maxBombs = 10; // �ִ� ��ź ����
    int bombX[10]; // ��ź���� X ��ǥ �迭
    int bombY[10]; // ��ź���� Y ��ǥ �迭
    int numBombs = 0; // ���� ��ź ����

    int score = 0; // ����
    int speed = 100; // ��ź �ӵ� (�и���)

    while (1) {
        bomb_drawMap(playerX, playerY, bombX, bombY, numBombs);
        bomb_gotoxy(0, MAP_HEIGHT);

        if (_kbhit()) { // Ű���� �Է� üũ
            key = _getch();

            if (key == 224) {
                key = _getch();

                switch (key) {
                case 75: // ���� ȭ��ǥ Ű
                    if (playerX > 0) {
                        playerX--; // �������� �̵�
                    }
                    break;
                case 77: // ������ ȭ��ǥ Ű
                    if (playerX < MAP_WIDTH - 1) {
                        playerX++; // ���������� �̵�
                    }
                    break;
                }
            }
        }

        // ��ź ��ġ ������Ʈ
        for (int i = 0; i < numBombs; i++) {
            if (bombY[i] >= MAP_HEIGHT) { // ��ź�� �ٴڿ� ����� ��
                if (bombX[i] == playerX && bombY[i] == playerY) {
                    printf("\n\033[1;31mGame Over! Score: %d\n\033[0m", score);
                    return 0; // ���� ����
                }
                else {
                    // ��ź ����
                    for (int j = i; j < numBombs - 1; j++) {
                        bombX[j] = bombX[j + 1];
                        bombY[j] = bombY[j + 1];
                    }
                    numBombs--;
                }
            }
            else {
                bombY[i]++; // ��ź�� ���� �ٴڿ� ���� �ʾ����� ������
            }
        }

        // ������ ���� ��ź �߰�
        if (score % 10 == 0 && numBombs < maxBombs) {
            bombX[numBombs] = rand() % MAP_WIDTH;
            bombY[numBombs] = 0;
            numBombs++;
        }

        // ��ź�� ĳ���� �浹 üũ
        for (int i = 0; i < numBombs; i++) {
            if (bombX[i] == playerX && bombY[i] == playerY) {
                printf("\n\033[1;31mGame Over! Score: %d\n\033[0m", score);
                int ana;
                printf("�ش� ������ ��� �÷��� �� ���ΰ���?...��(1),�ƴϿ�(0) :");
                scanf_s("%d", &ana);
                if (ana == 1) {
                    bomb();
                }
                else if (ana == 0) {
                    return 1;
                } // ���� ����
            }
        }

        score++; // ���� ����
        Sleep(speed); // ���� �ð� ���� (Windows���� ���)
    }
    
}
