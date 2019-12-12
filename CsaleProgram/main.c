/*************************************************************
 * @Filename: main.c
 * @Author: Malloc-Luo
 * @Data: 2019-12-2
 * @Description: 包含主函数部分，程序入口
 *
 * @Modified: 2019.12.06
 *              do a test;
 *
 ************************************************************/

#include "AllFiles.h"

int main()
{
 /*   FILE * fp;
    char ch1;
    char ch2;
    char string1[10];
    char string2[10];
    char string3[10];
    int i = 0;

    fp = fopen("userinformation\\NEU123456789.user", "r");

    if(fp == NULL)
        printf("can't open this file");

    while((ch1 = fgetc(fp)) != '+')
    {
        string1[i] = ch1;
        i++;
    }
    puts(string1);
//    fseek(fp, 1L, SEEK_CUR);
//fflush(fp);
    i = 0;
    while((ch2 = fgetc(fp))!= '+')
    {
        string2[i] = ch2;
        putchar(string2[i]);
        i++;
    }
    //flus

    //fscanf(fp,"%s %s %s %c", string1, string2, string3, &ch);
    //puts(string1);  putchar('\n');
    //puts(string2);  putchar('\n');
    //puts(string3);  putchar('\n');
    //putchar(ch);
    puts(string2);
    printf("\n%s", string2);
// if(strcmp(string1,string2)==0)
//    printf("对");
//
    printf("%d", strlen(string2));
    putchar('\n');
    getch();

  //Begin_page_windows();
//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
//  printf("test");
  //Begin_page();
//endline;
//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
  /*for(i = 0;i<120;i++)
  {

      putchar('|');
      Sleep(200);
  }
  getch();

  for(i = 0;i<5;i++)
  {0
      putchar(ch);
      Sleep(100);
  }
  getch();*/
 /* char ch1[] = "NEU";
  char ch2[] = ".user";
  char ch3[10];
  FILE * fp;
  gets(ch3);

  strcat(ch1, ch3);
  puts(ch1);
  strcat(ch1, ch2);
  endline;
  puts(ch1);

  fp = fopen(ch1, "w");
  if(fp == NULL)
    printf("error\n");
  fputs(ch1, fp);
  fclose(fp);*/
  system("color f0");

    Begin_page();
    return 0;
}
