#include "AllFiles.h"

/*
 * ��ȡ�ַ��������������
 */

void get_string(char *data)
{
    fflush(stdin);
    gets(data);
    fflush(stdin);
}

/*
 * ��ȡһ���ַ�����ջ�����
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
            printf("��������Ч��������ѡ��");
            break;
        case USERNAME_DISABLE:
            printf("���û��������ã��밴Ҫ����д��");
            break;
        case USERNAME_EXIST:
            printf("���û��������ã����û����ѱ�ʹ�ã���������д��");
            break;
        case USERNAME_NOT_EXIST:
            printf("���û������ڣ����������룡");
            break;
        case PASSWORD_DISABLE:
            printf("�����벻���ã��밴Ҫ����д��");
            break;
        case PASSWORD_DIFFERENT:
            printf("��������֤�����ϣ����������룡");
            break;
        case PASSWORD_ERROR:
            printf("���������");
            break;
        case TRY_TOOMANY:
            printf("���Դ������࣬���Ժ�����..");
            break;
        default:
            break;
    }
}





