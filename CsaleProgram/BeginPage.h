/*******************************************************
 * @Filename: BeginPage.h
 * @Author: Malloc-Luo
 * @Data: 2019-12-2
 * @Description: ��ʼҳ��������ʼҳ����
 *******************************************************/

#ifndef __BEGIN_PAGE_H__
#define __BEGIN_PAGE_H__
#include "AllFiles.h"

//����״̬
extern int OnlineFlag;

#define ONLINE 0x00
#define LEAVE  0x404

int Begin_page(void);

/*
 * ���ܻ�ִ�У�
 *          ���û�ע��
 *          �û���¼
 *          ����
 *          �˳�
 * ���¶�Ӧ�궨��
 */
int Begin_page_windows(void);

#define LOGIN       0x02 //ע��
#define SIGNIN      0x01 //��¼
#define HELP        0x03 //����
#define EXIT        0x04 //�˳�
#define SIGNOUT     0x05 //ע����¼
#define FINDPASSWORD 0x06 //�һ�����
#define HOMEPAGE    0x01
#define PERSION     0x02

int Begin_page_callback(int flag);

static int check_command(char );

#endif // __BEGIN_PAGE_H__
