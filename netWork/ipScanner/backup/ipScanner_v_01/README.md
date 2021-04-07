# Main process of this project
1. nbtscan is an external network scanning application which will be used for scanning the particular ip range
   [official page](http://www.unixwiz.net/tools/nbtscan.html#download)
   (ping command from windows or linux built-in can be used too if possible)
2. append its output to the plaintextedit
3. save the output


# qt classes
* QPrcess (run the external program and return its value back to textedit or save it to an external text file)
  [example](https://stackoverflow.com/questions/19442400/qt-execute-external-program)
  [example2](https://www.programmersought.com/article/82083963243/)
* QThread (if ping is used)
  [example](https://cloud.tencent.com/developer/article/1417559)
* QFileDialog (saving the output)
  [example](https://www.it1352.com/1829427.html)
* QFile, QByteArray, QTextStream, QDataStream, QIODevice, etc.  (ouptut saving related)
  [example](https://www.cnblogs.com/xiangtingshen/p/10784109.html)
* QEventFilter(filtering the combobox event, e.g. the scanner will scan the particular range right after the range is choosed)
  [example](https://stackoverflow.com/questions/21997846/populate-qcombobox-on-drop-down-or-user-click)
  **The more redundant way is to get the current text content and then pass the text to a function then run the scanning**
  [example](https://stackoverflow.com/questions/6061893/how-do-you-get-the-current-text-contents-of-a-qcombobox)
* QHostInfo
  https://www.cnblogs.com/itrena/p/5938377.html


# Other reference
* [Port scanner](https://blog.csdn.net/weixin_30730151/article/details/95341709)
* [qcombobox](https://stackoverflow.com/questions/56557896/get-qcombobox-item-text-triggered-by-event-in-separate-class-method-function)
  [qcombobox2](https://forum.qt.io/topic/9411/how-to-set-focus-to-a-combo-box-on-a-key-press-event/2)
  [qcombobox3](http://qtexamples.com/combobox-signals-and-slots/)
* [ipscan](https://blog.csdn.net/qq78442761/article/details/89318382)
