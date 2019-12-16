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
    time(&Now);
   Time_Now = localtime(&Now);
   printf("%d %d %d",Time_Now->tm_year + 1900, Time_Now->tm_mon + 1, Time_Now->tm_hour);

}



int main()
{
#if 1
    system("color f0");
    prepare_for_program();
    Begin_page();
#else
    test();
#endif // 0

    return 0;
}
