#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <iostream>

using namespace std;

void menu();
void setting();
void records();
void play();
bool winX();
void printboard();
int validrow(int);
void color(int);
HANDLE handelTextColor = GetStdHandle(STD_OUTPUT_HANDLE);

int i = 7, j = 6, w = 4;
std::string player1;
std::string player2;
std::string winner;
char jadval[20][20];
int main()
{
  menu();
}
void menu()
{
  system("cls");
  std::cout << "1. play" << '\n';
  std::cout << "2. setting" << '\n';
  std::cout << "3. records" << '\n';
  std::cout << "4. exit" << '\n';
  int v1;
  cin >> v1;
  switch (v1)
  {
  case 1:
  {
    play();
  }
  case 2:
  {
    setting();
  }
  case 3:
  {
    records();
  }
  case 4:
  {
    exit(0);
  }
  }
}
void setting()
{
  system("cls");
  std::cout << "1. sotoon :" << j << '\n';
  std::cout << "2. radif :" << i << '\n';
  std::cout << "3. mohre :" << w << '\n';
  std::cout << "4. back" << '\n';
  int a;
  cin >> a;
  switch (a)
  {
  case 1:
  {
    std::cout << "tedad sotoon jadid ra vared konid" << '\n';
    cin >> j;
    break;
  }
  case 2:
  {
    std::cout << "tedad radif jadid ra vared konid" << '\n';
    cin >> i;
    break;
  }
  case 3:
  {
    std::cout << "tedad mohre jadid ra vared konid" << '\n';
    cin >> w;
    break;
  }
  case 4:
    menu();
  default:
    setting();
  }
}
void records()
{
  system("cls");
  ifstream voroodi("scores.txt", ios::in);
  if (voroodi.is_open())
  {
    string line;
    int i = 1;
    while (getline(voroodi, line))
    {
      std::cout << i++ << ". " << line << '\n';
    }
  }
  else
    std::cout << "unable to open the file" << '\n';
  std::cout << "\n1. back" << '\n';
  int a;
  cin >> a;
  if (a == 1)
    menu();
  else
    records();
}
void play()
{
  color(15);
  system("cls");
  std::cout << "player 1s name" << '\n';
  std::cin >> player1;
  std::cout << "player 2s name" << '\n';
  std::cin >> player2;
  for (int kaa = 0; kaa < i; kaa++)
    for (int saa = 0; saa < j; saa++)
      jadval[kaa][saa] = ' ';
  int turns = 0;
  char XO;
  while (!winX())
  {
    turns++;
    printboard();
    if (turns % 2 == 1)
    {
      std::cout << player1;
      std::cout << "s turn" << '\n';
      XO = 'O';
      winner = player1;
    }
    else
    {
      std::cout << player2;
      std::cout << "s turn" << '\n';
      XO = 'X';
      winner = player2;
    }
    int x;
    cin >> x;
    x--;
    int tempx = validrow(x);
    jadval[tempx][x] = XO;
  }
  printboard();
  std::cout << winner << " wins . score : ";
  std::cout << pow(i, j) * 2 / turns << '\n';
  ofstream khorooji("scores.txt", ios_base::app);
  khorooji << winner << " : " << int(pow(i, j) * 2 / turns) << '\n';
  if (khorooji.is_open())
    khorooji.close();
  Sleep(1000);
  std::cout << "play again ? Y/N" << '\n';
  char co;
  cin >> co;
  if (co == 'y' || co == 'Y')
    play();
  else
    menu();
}
int validrow(int co)
{
  for (int ii = i - 1; ii >= 0; ii--)
  {
    if (jadval[ii][co] == ' ')
      return ii;
  }
  return -1;
}
void printboard()
{
  system("cls");
  for (int ii = 0; ii < i; ii++)
  {
    std::cout << "|";
    for (int jj = 0; jj < j; jj++)
    {
      if (jadval[ii][jj] == 'X')
        color(6);
      else
        color(11);
      std::cout << jadval[ii][jj];
      color(15);
      cout << "|";
    }
    std::cout << '\n';
  }
}
bool winX()
{
  int count;
  for (int r = i - 1; r >= 0; r--)
  {
    for (int c = j - 1; c >= 0; c--)
    {
      if (jadval[r][c] != ' ')
      {
        //chap
        char XO = jadval[r][c];
        count = 0;
        int tempi = r;
        int tempj = c;
        while (jadval[tempi][tempj] == XO && tempj > 0)
        {
          count++;
          tempj--;
        }
        if (count >= w)
          return 1;
        //bala
        count = 0;
        tempi = r;
        tempj = c;
        while (jadval[tempi][tempj] == XO && tempi > 0)
        {
          count++;
          tempi--;
        }
        if (count >= w)
          return 1;
        //orib -1;
        count = 0;
        tempi = r;
        tempj = c;
        while (jadval[tempi][tempj] == XO && tempi > 0 && tempj > 0)
        {
          count++;
          tempi--;
          tempj--;
        }
        if (count >= w)
          return 1;
        //orib 1;
        count = 0;
        tempi = r;
        tempj = c;
        while (jadval[tempi][tempj] == XO && tempi > 0 && tempj < j)
        {
          count++;
          tempi--;
          tempj++;
        }
        if (count >= w)
          return 1;
      }
    }
  }

  return 0;
}
void color(int a)
{
  SetConsoleTextAttribute(handelTextColor, a);
}
