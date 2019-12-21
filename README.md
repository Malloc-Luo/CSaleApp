# CSaleApp
### 2019秋季学期 程序设计作业
******

**初步设想**
> 每个用户对应一个数据文件，文件格式 "NEU + username.user"，例如用户名：Malloc，数据文件NEUMalloc.user  ,二进制读写  
> 用户文件位置 D:\\ALessionProject\\Users  
> 管理员文件位置 D:\\ALessionProject\\Manager  
> 用户日志文件位置 D:\\ALessionProject\\UserLog
> 建立用户名索引文件 user.dat  
> 考虑对文件进行加密  
* <font color=red>程序准备</font>
>> 检查文件夹是否存在，不存在则创建之  
>> 读入管理员信息
* <font color=red>程序开始界面</font>
>> 操作引导
* <font color=red>用户登录</font>
>> 用户检查密码核对  
>> 无用户提示注册  
>> 登陆限制  

* <font color=red>新用户注册</font>
>> 检查现有用户名(如果有重复重新填写)  
>> 完善个人信息  
>> 确认注册创建用户文件
* <font color=red>找回密码</font>  
>> 根据电话或邮箱
* <font color=red>管理员模式</font>
>> 通过特定用户名及密码进入  
>> 添加、删除、修改商品  
>> 查看用户信息
* <font color=red>商品详情</font>
>> .html文件
* <font color=red>个人中心</font>
>> 选择商品  
>> 购物车  
>>>> 删除商品  
>>>> 结算  
>> 个人信息  
>>>> 修改个人信息  
>>>> 注销  
* <font color=red>帮助</font>
>> 链入.html文件，system函数~  
>> 可以联系作者(附github项目地址)，或者查看使用说明  
* 退出
* 任意位置返回首页

*******  

*其它想法*
* **命令行模式？**
* 简单的过渡动画

