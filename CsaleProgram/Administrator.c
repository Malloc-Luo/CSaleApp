#include "Administrator.h"

int Administrator(void)
{
    int cmd = 0;

    cmd = Administrator_windows(cmd);
    while(1)
    {
        cmd = Administrator_deal(cmd);
        cmd = Administrator_callback(cmd);
        if(cmd == _EXIT)
            return CANCEL;
    }
    return 0;
}

/*
 * return 0 ��¼�ɹ�
 * return CANCEL ȡ��
 */
int Administrator_windows(int cmd)
{
    char password_buff[20];
    static int times = 0;

    CLS;
    endline; endline; endline;
    beginline; printf("��⵽���ǹ���Ա..");
    Sleep(700);
    CLS;
    endline; endline; endline;
    middle; printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~����Ա~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); endline;
    beginline; printf("�������Ա���룺        $-> ȡ�� ->[1]"); newline;
    while(1)
    {
        beginline; command_char();
        get_password(password_buff);
        if(strlen(password_buff) == 1 && password_buff[0] == '1')
            return CANCEL;
        if(strcmp(MainUser.password, password_buff) != 0)
        {
            newline;
            beginline; error_remind(PASSWORD_ERROR); newline;
            times ++;
        }
        else
            break;
        if(times >=4)
        {
            CLS;
            endline; endline; endline;
            beginline; error_remind(TRY_TOOMANY);
            Sleep(1500);
            return CANCEL;
        }
    }
    movie();
    return 0;
}

int Administrator_deal(int cmd)
{
    int flag = 0;
    if(cmd == CANCEL)
        return cmd;
    cmd = show_option_windows();
    switch(cmd)
    {
    case 1:
        print_user_list();
        break;
    case 2:
        CLS;
        endline; endline;
        beginline; printf("�ù�����δ����!");
        Sleep(1200);
        CLS;
        break;
    case 3:
        Help();
        break;
    case 4:
        change_main_password();
        break;
    case 5:
        flag = Exit();
        break;
    default:
        break;
    }

    return flag;
}

int Administrator_callback(int cmd)
{
    if(cmd == _EXIT)
        return _EXIT;
    return 0;
}






int show_option_windows(void)
{
    int cmd = 0;

    if(MainUser.times == 0)
    {
        endline;
        beginline; printf("��һ�ε�¼���������޸��������룡");
        Sleep(1500);
        MainUser.times ++;
        change_main_password();
        save_Administrator_information();
    }
    CLS;
    endline; endline; endline;
    middle; printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~����Ա~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); endline;
    beginline; printf("$-> �鿴�û��б� ->[1]"); newline;
    beginline; printf("$-> �鿴��Ʒ�б� ->[2]"); newline;
    beginline; printf("$-> ����         ->[3]"); newline;
    beginline; printf("$-> �޸�����     ->[4]"); newline;
    beginline; printf("$-> �˳���¼     ->[5]"); newline;
    beginline; command_char();
    scanf("%d", &cmd);

    return cmd;
}


int save_Administrator_information(void)
{
    FILE * fp;
    fp = fopen("D:\\ALessionProject\\Manager\\Administrator.administ", "wb");
    fwrite(MainUser.password, CHAR_SIZE, 20, fp);
    fwrite(&MainUser.times, INT_SIZE, 1, fp);
    fwrite(&MainUser.usernumber, INT_SIZE, 1, fp);
    fclose(fp);

    return 0;
}


int change_main_password(void)
{
    CLS;
    endline; endline; endline;
    beginline; printf("�����룺"); newline;
    beginline; command_char();
    get_password(MainUser.password);
    CLS;
    endline; endline; endline;
    beginline; printf("�޸ĳɹ���");
    Sleep(1500);

    return 0;
}


int print_user_list(void)
{
    FILE * fp;
 //   char username[20];
    char ** name;
    int i = 0;
    int flag = 0;

    //Ϊ�û�������ռ�
    name = (char**)malloc(sizeof(char *) * MainUser.usernumber);
    for(i = 0;i<MainUser.usernumber; i++)
        name[i] = (char *)malloc(sizeof(char) * 20);

    while(1)
    {
        CLS;
        fp = fopen("D:\\ALessionProject\\Manager\\AllUsers.neu", "rb");
        fseek(fp, 0L, SEEK_SET);
        for(i = 0; i< MainUser.usernumber; i++)
        {
            fread(name[i], CHAR_SIZE, 20, fp);
            beginline; printf("[%d]   ", i+1); puts(name[i]);
            beginline; printf("-----------------------------------------");
        }

        fclose(fp);

        newline;
        beginline; printf("$-> �鿴��Ӧ����û���Ϣ  -> [ ]");newline;
        beginline; printf("$-> ����                  -> [-1]"); newline;
        beginline; command_char();
        scanf("%d", &flag);

        if(flag == -1)
            break;
        if(flag <=1 || flag > MainUser.usernumber)
        {
            CLS;
            endline; endline;
            beginline; printf("neu  is adminisator");
            Sleep(1200);
            CLS;
        }
        else
            _get_information(name[flag - 1]);
    }

    for(i = 0;i<MainUser.usernumber; i++)
        free(name[i]);
    free(name);

    return 0;

}

int _get_information(char *name)
{
    char flag = 0;
    char cmd = 0;

    Init_user_inf();
    strcpy(USER.username, name);
    Get_user_inf(&USER);

    while(1)
    {
        fflush(stdin);
        print_information();
        endline; newline;
        beginline; printf("&-> ���û���־     ->[0]"); newline;
        beginline; printf("&-> ����             ->[1]"); newline;
        beginline; command_char();
        //scanf("%d", &flag);
        flag = get_char();
        if(flag == '0')
        {
            open_user_log(name);
        }
        else
            break;

    }

    return 0;
}





