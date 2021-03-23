#### 我的qt版本为5.12，32位，mysql版本为8+，64位，我想使用qt连接远程服务器的mysql。

##### 1.首先进行测试，报错QSqlDatabase: QMYSQL driver not loaded。

（1）首先新建一个qt 控制台文件，在.pro文件中添加`QT += sql`，在main.cpp中编写代码如下：

```cpp
QCoreApplication a(argc, argv);
//打开mysql
QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
db.setDatabaseName("your database name");
db.setHostName("xxxx");
//db.setPort(3306);
db.setUserName("user name");
db.setPassword("your password");
if (!db.open())
    qDebug() << "打开数据库失败！";
else qDebug() <<"打开数据库成功！";
1234567891011
```

（2）之后程序输出QSqlDatabase: QMYSQL driver not loaded，这是因为没有驱动。通过查阅资料，这里需要两个东西：

1. 第一个是qt中需要有qsqlmysql.dll和qsqlmysqld.dll两个文件，在我的qt中其路径为：C:\Qt\Qt5.12.8\5.12.8\mingw73_32\plugins\sqldrivers，注意，这里就算是qt中有这两个文件，也不一定成功。我的qt中直接没有这两个文件。
2. 第二个是，我们需要mysql中的libmysql.dll，应该是在mysql中的lib文件夹内。这里要注意，根据我查的资料，假如我们本机根本没装mysql或者我们安装的mysql位数与qt不同，那么我们只需要下载一个mysql-connector文件，位数要与qt相同。比如我的mysql 是64位，qt是32位，那么我需要下载一个32位的mysql-connector，地址如下：[下载地址](https://downloads.mysql.com/archives/c-c/)。

##### 2.首先尝试一下

（1）假如我们的qt中有qsqlmysql.dll和qsqlmysqld.dll两个文件，我们可以将libmysql.dll文件复制打qt的bin文件夹中（我的路径是：C:\Qt\Qt5.12.8\5.12.8\mingw73_32\bin），尝试一下，如果不成功，或者qt中没有qsqlmysql.dll和qsqlmysqld.dll两个文件，那么我们需要自己编译正确的qsqlmysql.dll和qsqlmysqld.dll两个文件。

##### 3.编译qsqlmysql.dll和qsqlmysqld.dll

（1）编译需要使用qt的源代码，qt中没有的话可以去下载，需要下载qt-everywhere-src，qt官网找就行。
（2）之后，用qt creator打开下载的qt源码中的qtbase/src/plugins/sqldrivers/mysql/mysql.pro，之后添加代码：

```cpp
INCLUDEPATH += "mysql路径/include"
LIBS += "mysql路径/lib/libmysql.llib"
12
```

（3）在这里，如果我们是下载的mysql connector，那就是该文件中的include文件路径和libmysql.dll的路径。**注意：有的资料说这里的文件路径不要有空格**。
（4）为了输出方便，我们可以添加`DESTDIR = ../mysql/lib`，这样就可以直接在mysql.pro同级目录中的lib文件夹内找到需要的文件。
最后，编译mysql.pro，这里应该是需要选择一下编译器？反正捣鼓一下，让它成功编译就行。不行的话可以看看这个教程：[教程](https://blog.csdn.net/Agou_66/article/details/51969836?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase)（我没试过）。
（5）我编译时遇到问题，将mysql.pro中的`QMAKE_USE += mysql`注释掉就好了。最后，应该是生成了四个文件：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200622000650154.png)
（6）我们将后两个复制到C:\Qt\Qt5.12.8\5.12.8\mingw73_32\plugins\sqldrivers，然后将mysql中的那个libmysql.dll复制到C:\Qt\Qt5.12.8\5.12.8\mingw73_32\bin中，再次运行数据库连接实验代码，就可以看到此时已经有了mysql的驱动，也就是可以连接mysql了。

##### 4.连接数据库时遇到QSqlError(“2059”, “QMYSQL: Unable to connect”, "Authentication plugin ‘caching_sha2_password’ cannot be loaded问题

（1）通过查阅资料，应该是mysql8以上的版本验证方式不同？我们可以在我们要连接的mysql数据库上执行：

```cpp
ALTER USER 'your user name'@'ip' IDENTIFIED WITH mysql_native_password BY 'password';
FLUSH PRIVILEGES;
12
```

例如我想要使用的用户名是temp，任何ip均可连接，那么就在我的远程服务器的mysql中执行：

```cpp
ALTER USER 'temp'@'%' IDENTIFIED WITH mysql_native_password BY 'password';
FLUSH PRIVILEGES;
12
```

（2）这里我只找到了改变mysql验证方式的解决方法，没有找到qt层面的解决方法。

##### 全部完成后，我就可以使用qt连接我的远程服务器的mysql了！

#### 参考资料：

https://blog.csdn.net/u012532263/article/details/83071741
https://www.cnblogs.com/szitcast/p/11105899.html
[参考三](https://blog.csdn.net/Agou_66/article/details/51969836?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase)
https://www.cnblogs.com/anloveslife/p/12296063.html
[参考五](https://blog.csdn.net/vkingnew/article/details/80105323?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase)