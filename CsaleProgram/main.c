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

void test(void)
{
    FILE * fp;
    int flag;
    char ch1[10] = "abcd";
    char ch2[10] = "1234";
    char ch3[10] = "+-*/";

    char buff1[10];
    char buff2[10];
    char buff3[10];

    fp = fopen("user.txt", "wb");

    flag = fwrite(ch1, sizeof(char), 10, fp);
    flag = fwrite(ch2, sizeof(char), 10, fp);
    flag = fwrite(ch3, sizeof(char), 10, fp);
    printf("%d", flag);

    fclose(fp);

    fp = fopen("user.txt", "rb");

    flag = fread(buff1, sizeof(char), 10, fp);
    flag = fread(buff2, sizeof(char), 10, fp);
    flag = fread(buff3, sizeof(char), 10, fp);

    fclose(fp);

    printf("%s", buff1);printf("%d", flag);
    puts(buff2);printf("%d", flag);
    puts(buff3);printf("%d", flag);


//    system("md D:\\user");
//    if(_access("D:\\Users", 0) == -1)
//    {
//        _mkdir("D:\\Users");
//2    }
/*    char ch[10];
    char * c;
    gets(ch);

    c = Create_file_path(ch);
    putchar('\n');
    printf("%s", c);
*/
}



int main()
{
    system("color f0");
    prepare_for_program();
    Begin_page();
  //  test();
    return 0;
}
