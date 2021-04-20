# Project Note
* How it works
    1. Program will be started in the form of systemTray(QSystemTrayIcon)
    2. A simple "Hello World" window will show up once user clicked the systemTrayIcon
    3. During the systemTrayIcon is running, the background algorithm keep detecting the specified "Process",
    will restart the "Program" again once this program detects the specified "Process" is gone


* Key Components
    1. QTimer (Timer for checking the specified "Process")
    2. QSystemTrayIcon (The systemTray program)
    3. QProcess and QString (Determine whether the specified program is running)
    4. tasklist(windows built-in command which outputs the entire process list in the current system memory)


* Code Structure
```
---QWidget
    |______ Starting the program and keep it is running hidden
                        |___________  QSystemTrayIcon (Simple actions: quite, restore)
                        |                                                       |__________ Showing "Hello world" and relative messages
                        |____________ Keep running the detection algorithm in the background periodically(e.g. 5 Seconds)
                        |                                  |________ tasklist (windows built-in)    |_______QTimer
                        |                                  |________ QProcess, QString
                        |___________Restart the program again once the detection is spotted
                                       |___________QProcess
```


