#include "AllFiles.h"

//����Ա
_Administ MainUser;


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
 * ������ʾ�����ݲ�ͬ�������ʹ�ӡ����ʾ
 * ��������������
 * ���أ�void
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

/*
 * ׼�����򣬳���ʼ�׶����У�
 * ����Ƿ�����û��ļ��У����������򴴽�֮
 * ���ع���Ա��Ϣ��Ϊ����Աģʽ��׼��
 */
int prepare_for_program(void)
{
    FILE * fp;

    if(_access("D:\\ALessionProject", 0) == -1)
    {
        Frist_time_to_use();
        _mkdir("D:\\ALessionProject");

        fp = fopen("D:\\ALessionProject\\readme.txt", "w");
        fputs("\n", fp);
        fputs("\t this is a test file, you can delete it now\n", fp);
        fprintf(fp, "\n\t������\n\t20184023\n\t�Զ���1803\n");
        fprintf(fp, "\n\t����Ȼûд��~");

        fclose(fp);
    }

    if(_access("D:\\ALessionProject\\Users", 0) == -1)
    {
        _mkdir("D:\\ALessionProject\\Users");
    }

    if(_access("D:\\ALessionProject\\UserLog", 0) == -1)
    {
        _mkdir("D:\\ALessionProject\\UserLog");
    }

    if(_access("D:\\ALessionProject\\Manager", 0) == -1)
    {
         _mkdir("D:\\ALessionProject\\Manager");

         fp = fopen("D:\\ALessionProject\\Manager\\readme.txt", "w");
         fprintf(fp, "\t\tʲô�ǹ���Աģʽ��\n\t����ɾ�����޸���Ʒ��Ϣ�������û���");
         fprintf(fp, "\n\t�������Աģʽ�������ض��˺���Ĭ������\n\t���˺ţ�neu�������룺123�� ");
         fclose(fp);

         MainUser.times = 0;
         MainUser.usernumber = 1;
         fp = fopen("D:\\ALessionProject\\Manager\\Administrator.administ", "wb");
         fwrite("123", CHAR_SIZE, 20, fp);
         fwrite(&MainUser.times, INT_SIZE, 1, fp);
         fwrite(&MainUser.usernumber, INT_SIZE, 1, fp);
         fclose(fp);

         fp = fopen("D:\\ALessionProject\\Manager\\AllUsers.neu", "ab+");
         fwrite("neu", CHAR_SIZE, 20, fp);
         fclose(fp);
    }

    //��ȡ����Ա��Ϣ
    strcpy(MainUser.username, "neu");
    fp = fopen("D:\\ALessionProject\\Manager\\Administrator.administ", "rb");
    fread(MainUser.password, CHAR_SIZE, 20, fp);
    fread(&MainUser.times, INT_SIZE, 1, fp);
    fread(&MainUser.usernumber, INT_SIZE, 1, fp);
    fclose(fp);

    return 0;
}


int Frist_time_to_use(void)
{
    endline;
    action_mode();
    endline; endline;
//    beginline; printf("-.-.-.-.-.-.-.-.-.-"); newline;
    beginline; printf("|��ӭʹ�ñ�����ϵͳ|\n"); newline;
//    beginline; printf("-.-.-.-.-.-.-.-.-.-"); newline;
    beginline; printf("��֪��"); newline;
    beginline; printf("�û���Ϣ���������� d:\\ALessionProject\\Users �ļ�����\n"); newline;
    middle; middle; printf("�û��ļ� NEUusername.user"); newline;
    beginline; beginline; printf("�������ʼʹ��..");
    endline; endline;
    Sleep(1500);
    action_mode();
    getch();
    system("cls");
    Sleep(500);
}

int action_mode(void)
{
    int i = 0;
    for(i = 0;i<120;i++)
    {
        if(i%2)
            putchar('/');
        else
            putchar('\\');
        Sleep(10);
    }

    return 0;
}

void get_password(char *password)
{
    int i = 0;
    char buff;
    while((buff = getch()) != '\r')
    {
        fflush(stdin);
        if(buff == '\b')
        {
            i --;
            password[i] = '\0';
            putchar('\b');
            putchar(' ');
            putchar('\b');
        }
        else
        {
            password[i] = buff;
            putchar('*');
            i ++;
        }
    }
    password[i] = '\0';
}



