#include "game.h"
#include <stdio.h>
#include <stdlib.h>

void menu() {
  printf("**********************************\n");
  printf("********  1.play  0.exit  ********\n");
  printf("**********************************\n");
}

void game() {
  char ret = ' ';
  char board[ROW][COL] = {0};
  // 初始化棋盘的函数
  InitBoard(board, ROW, COL);
  DisplayBoard(board, ROW, COL);
  // 下棋
  while (1) {
    PlayerMove(board, ROW, COL);
    // 判断输赢
    ret = IsWin(board, ROW, COL);
    if (ret != 'C') {
      break;
    }
    DisplayBoard(board, ROW, COL);
    ComputerMove(board, ROW, COL);
    // 判断输赢
    ret = IsWin(board, ROW, COL);
    if (ret != 'C') {
      break;
    }
    DisplayBoard(board, ROW, COL);
  }
  if (ret == '*') {
    printf("玩家赢\n");
  } else if (ret == '#') {
    printf("电脑赢\n");
  } else {
    printf("平局\n");
  }
  DisplayBoard(board, ROW, COL);
}

int main() {
  srand((unsigned)time(NULL));
  int input = 0;
  do {
    menu(); // 打印菜单
    printf("请选择:>");
    scanf("%d", &input);
    switch (input) {
    case 1:
      game();
      break;
    case 0:
      printf("bye\n");
      break;
    default:
      printf("error\n");
      break;
    }
  } while (input);
  return 0;
}
