/*******************************************************
 * @Filename: BeginPage.h
 * @Author: Malloc-Luo
 * @Data: 2019-12-2
 * @Description: 开始页，包括开始页函数
 *******************************************************/

#ifndef __BEGIN_PAGE_H__
#define __BEGIN_PAGE_H__
#include "AllFiles.h"

//在线状态
extern int OnlineFlag;

#define ONLINE 0x00
#define LEAVE  0x404

int Begin_page(void);

/*
 * 可能会执行：
 *          新用户注册
 *          用户登录
 *          帮助
 *          退出
 * 以下对应宏定义
 */
int Begin_page_windows(void);

#define LOGIN       0x02 //注册
#define SIGNIN      0x01 //登录
#define HELP        0x03 //帮助
#define EXIT        0x04 //退出
#define SIGNOUT     0x05 //注销登录
#define FINDPASSWORD 0x06 //找回密码
#define HOMEPAGE    0x01
#define PERSION     0x02

int Begin_page_callback(int flag);

static int check_command(char );

#endif // __BEGIN_PAGE_H__
