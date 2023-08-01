#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void eightqueen(int num);
int* queen;
int check;
int tim = 1;

int main() {

    queen = (int*)calloc(9, sizeof(int));//row column

    eightqueen(1);

    system("pause");
    return 0;
}

void eightqueen(int row) {
    for (int col = queen[row] + 1; col <= 8; col++) {
        check = 0;
        for (int i = 1; i < row; i++) {
            if (queen[i] == col || abs(queen[i] - col) == abs(row - i)) {
                check = 1;
                break;
            }
        }
        if (check == 0) {
            queen[row] = col;
            if (row == 8) {
                int ans = 1;
                printf("\nsolution of %d:\n",tim);
                tim++;
                for (int i = 1; i <= 8; i++) {
                    for (int j = 1; j <= 8; j++) {
                        if (ans < 9) {
                            if (queen[ans] == j && ans == i) {
                                printf(" [Q]");
                                ans++;
                            }
                            else printf(" [-]");
                        }
                        else printf(" [-]");
                    }
                    printf("\n");
                }
                check = 1;
            }
            else {
                row++;
                if (row < 9) {
                    eightqueen(row);
                }
            }
        }
    }
    if (check == 1) {
        queen[row] = 0;
        row--;
        if (row >= 1) {
            eightqueen(row);
        }
    }
}