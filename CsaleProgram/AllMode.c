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

int prepare_for_program(void)
{
    FILE * fp;
    if(_access("D:\\ALessionProject", 0) == -1)
    {
        Frist_time_to_use();
        _mkdir("D:\\ALessionProject");

        fp = fopen("D:\\ALessionProject\\readme.txt", "w");
        fputs("1 flag\n", fp);
        fputs("this is a test file, you can delete it now", fp);
        fprintf(fp, "\n\t������\n\t20184023\n\t�Զ���1803");

        fclose(fp);
    }

    if(_access("D:\\ALessionProject\\Users", 0) == -1)
    {
        _mkdir("D:\\ALessionProject\\Users");
    }

    if(_access("D:\\ALessionProject\\Manager", 0) == -1)
    {
         _mkdir("D:\\ALessionProject\\Manager");
    }
    return 0;
}


int Frist_time_to_use(void)
{
    endline;
    action_mode();
    endline; endline;
    beginline; printf("��ӭʹ�ñ�����ϵͳ\n"); newline;
    beginline; printf("��֪��"); newline;
    beginline; printf("�û���Ϣ����������  d:\\ALessionProject\\Users �ļ�����\n");
    middle; middle; printf("�û��ļ� NEUusername.user"); newline;
    beginline; beginline; printf("�������ʼʹ��..");

    getch();
    system("cls");
}

int action_mode(void)
{
    int i = 0;
    for(i = 0;i<120;i++)
    {
        putchar('|');
        Sleep(10);
    }

    return 0;
}



