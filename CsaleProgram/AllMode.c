#include "AllFiles.h"

/*
 * ��ȡ�ַ��������������
 */

void get_string(char *data)
{
    gets(data);
    fflush(stdin);
}

/*
 * ��ȡһ���ַ�����ջ�����
 */
char get_char(void)
{
    char ch;
    ch = getchar();
    fflush(stdin);

    return ch;
}

/*
 * ��ӡ������ʾ��
 */
void command_char(void)
{
    printf("$->  ");
}

/*
 * ������ʾ
 */
void error_remind(int error_type)
{
    switch(error_type)
    {
        case NOCOMMAND:
            printf("������Ч��������ѡ��");
            break;
        case USERNAME_DISABLE:
            printf("�û��������ã��밴Ҫ����д");
            break;
        case USERNAME_EXIST:
            printf("�û��������ԣ����û����ѱ�ʹ�ã���������д");
            break;
        case USERNAME_NOT_EXIST:
            printf("�û������ڣ�����������");
            break;
        case PASSWORD_DISABLE:
            printf("���벻���ã�����ϸ�Ķ��淶");
            break;
        case PASSWORD_DIFFERENT:
            printf("������֤�����ϣ�����������");
            break;
        case PASSWORD_ERROR:
            printf("�������");
            break;
        default:
            break;
    }
}


