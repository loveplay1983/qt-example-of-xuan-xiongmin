1. How to connect to sql server via qt and odbc
```
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3");

db.setDatabaseName("DRIVER={SQL Server};Server=ITPL_PC1;Database=Test;Uid=sa;Port=1433;Pwd=*******;WSID=.");

db.open();

QSqlQueryModel *model = new QSqlQueryModel;

QString query = "insert into qttable(PID) values('ARINDAM')";
model->setQuery(query, db);

db.close();
```

2. [sql server connection string references](https://docs.microsoft.com/en-us/sql/relational-databases/native-client/applications/using-connection-string-keywords-with-sql-server-native-client?view=sql-server-ver15)

3. QInputDialog example
```
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    bool ok;
    // Ask for birth date as a string.
    QString text = QInputDialog::getText(0, "Input dialog",
                                         "Date of Birth:", QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty()) {
        QDate date = QDate::fromString(text);
        int age = computeAge(date);
        // Show the age.
        QMessageBox::information (0, "The Age",
                                  QString("The age is %1").arg(QString::number(age)));
    }
    [..]
```
