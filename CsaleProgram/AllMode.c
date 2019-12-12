#include "AllFiles.h"

/*
 * 获取字符串并清除缓冲区
 */

void get_string(char *data)
{
    fflush(stdin);
    gets(data);
    fflush(stdin);
}

/*
 * 读取一个字符并清空缓冲区
 */
char get_char(void)
{
    char ch;
    fflush(stdin);
    ch = getchar();
    fflush(stdin);

    return ch;
}

/*
 * 打印命令提示符
 */
void command_char(void)
{
    printf("$->  ");
}

/*
 * 错误提示
 */
void error_remind(int error_type)
{
    switch(error_type)
    {
        case NOCOMMAND:
            printf("！命令无效，请重新选择！");
            break;
        case USERNAME_DISABLE:
            printf("！用户名不可用，请按要求填写！");
            break;
        case USERNAME_EXIST:
            printf("！用户名不可用，该用户名已被使用，请重新填写！");
            break;
        case USERNAME_NOT_EXIST:
            printf("！用户不存在，请重新输入！");
            break;
        case PASSWORD_DISABLE:
            printf("！密码不可用，请按要求填写！");
            break;
        case PASSWORD_DIFFERENT:
            printf("！密码验证不符合，请重新输入！");
            break;
        case PASSWORD_ERROR:
            printf("！密码错误！");
            break;
        case TRY_TOOMANY:
            printf("尝试次数过多，请稍后重试..");
            break;
        default:
            break;
    }
}





