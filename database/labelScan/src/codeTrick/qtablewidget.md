**1 均分各列**

```
1  tableWidget->horizontalHeader()->setStretchLastSection(true); //就是这个地方
2  tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
```

**2  整行选中：**

```
1 tableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
2 tableWidget->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
```

**3 删除\**选中的\*\*整行\*\**\***

```
1  int rowIndex = m_pAttrbuteList->currentRow();
2  if (rowIndex != -1)
3      tableWidget->removeRow(rowIndex);
```

 

​    为了将数据能够在界面中显示的更清楚一些，在这里应用到了tableWidget控件，现将该控件中删除指定行的代码介绍如下：

 QTable里有一个removeRow(int i)函数用来删除当前行，但是如果我们没有对于table进行任何的选中，那么QTable是如何返回的呢？
 用Qt Creator里拖了一个tableWidget,加一个按钮，点击删除后执行

```
1  int i = ui->tableWidget->currentRow();
2  QMessageBox msg;
3  msg.setText(QString::number(i));
4  msg.exec();
5  ui->tableWidget->removeRow(i);
```

 在不选择行的情况下发现每次点击后删除的都是第一行，i的输出都是0.


    原因其实很简单，就是因为table的当前焦点在第一样的第一个单元格所导致的，解决的办法就是让table失去焦点，在构造函数里面添加ui->tableWidget->setFocusPolicy(Qt::NoFocus);
然后再试，发现点击删除按钮如果不选中行的话是不能删除的，返回的i此时是-1。

控件刚开始的时候左边默认自带序列号，如果想去掉左边的行号，加上下面的代码就可以了。

```
1       QHeaderView* headerView = table的名字->verticalHeader();
2       headerView->setHidden(true);
```

 

**4 添加整行**

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```
 1 int rowIndex = m_pAttrbuteList->rowCount();
 2  tableWidget->setRowCount(rowIndex + 1);//总行数增加1
 3 
 4  tableWidget->setRowHeight(rowIndex, 24);//设置行的高度
 5 
 6 --------------------------------------------------------------------------------
 7 
 8 QTableWidget *table = new QTableWIdget(this);
 9 
10 table->setColumnCount(5);    //设置列数
11 
12 table->setRowCount(3);        //设置行数/
13 
14 /*设置列名*/
15 
16 QStringList headers;
17 
18 headers<<"列名1"<<"列名2"<<"列名3";
19 
20 table->setHorizontalHeaderLabels(headers);
21 
22 /*给单元格添加内容*/
23 
24 void addItemContent(int row, int column, QString content)
25 
26 {
27 
28       QTableWidgetItem *item = new QTableWidgetItem (content);
29 
30       table->setItem(row, column, item);
31 
32 }
33 
34 /*给单元格中增加图标*/
35 
36 QTableWidgetItem *item = new QTableWidgetItem(QIcon("myImage.jpg"), NULL);  //只加入图标，没有字符串
37 
38 QTableWidgetItem *item = new QTableWidgetItem(QIcon("myImage.jpg"), myString);   //加入图标和字符串
39 
40 table->setItem(row, column, item);
41 
42 /*插入一行*/
43 
44 int row = table->rowCount();
45 
46 table->insertRow(row);
47 
48 /*插入一列*/
49 
50 int column = table->columnCount();
51 
52 table->insertColumn(column);
53 
54  //使行列头自适应宽度，最后一列将会填充空白部分
55 
56 table->horizontalHeader()->setStretchLastSection(true);          
57 
58 //使行列头自适应宽度，所有列平均分来填充空白部分            
59 
60 table->horizontalHeader()->setResizeMode(QHeaderView::Strtch);       
61 
62 //使行自适应高度，假如行很多的话，行的高度不会一直减小，当达到一定值时会自动生成一个QScrollBar
63 
64 table->verticalHeader()->setResizeMode(QHeaderView::Strtch);
65 
66 //设置单击选择一行
67 
68 table->setSelectionBehuavior(QAbstractItemView::SelectRows);
69 
70 //设置每行内容不可编辑
71 
72 table->setEditTriggers(QAbstractItemView::NoEditTriggers);
73 
74 //设置只能选择一行，不能选择多行
75 
76 table->setSelectionMode(QAbstractItemView::SingleSelection);
77 
78 /*去掉每行的行号*/
79 
80 QHeaderView *headerView = table->verticalHeader();
81 
82 headerView->setHidden(true);
83 
84 /*设置让某个单元格或某行选中*/
85 
86 选中单元格：table->setCurrentCell(row, column, QItemSelectionModel::Select);
87 
88 选中一行：table->setCurrentCell(row, QItemSelectionModel::Select);(注意此处的列没有值)
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)