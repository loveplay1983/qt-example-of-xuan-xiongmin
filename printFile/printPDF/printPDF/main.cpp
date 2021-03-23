#include <QCoreApplication>
#include <QPrinter>
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QPainter>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDialog w;

    w.setLayout(new QVBoxLayout());
    w.layout()->addWidget(new QLineEdit("text"));
    w.layout()->addWidget(new QPushButton("btn"));
    w.layout()->addWidget(new QPlainTextEdit("Lorem ipsum dolor sit amet, consectetur adipiscing elit."
                                             " Mauris rutrum magna semper nisi faucibus, at auctor dolor "
                                             "ullamcorper. Phasellus facilisis blandit augue sit amet placerat."
                                             " Aliquam nec imperdiet diam. Proin dignissim vulputate metus, nec "
                                             "tincidunt magna vulputate ac. Praesent vel felis ac dolor viverra "
                                             "tempus eu vitae neque. Nulla efficitur gravida arcu id suscipit. "
                                             "Maecenas placerat egestas velit quis interdum. Nulla diam massa, "
                                             "hendrerit vitae mi et, placerat aliquam nisl. Donec tincidunt lobortis"
                                             " orci, quis egestas augue tempus sed. Nulla vel dolor eget ipsum accumsan "
                                             "placerat ut at magna."));
    w.show();

    QPushButton btn("print");
    btn.show();

    QObject::connect(&btn, &QPushButton::clicked, [&w](){
        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("output.pdf");
        printer.setPageMargins(12, 16, 12, 20, QPrinter::Millimeter);
        printer.setFullPage(false);

        QPainter painter(&printer);

        double xscale = printer.pageRect().width() / double(w.width());
        double yscale = printer.pageRect().height() / double(w.height());
        double scale = qMin(xscale, yscale);
        painter.translate(printer.paperRect().center());
        painter.scale(scale, scale);
        painter.translate(-w.width()/ 2, -w.height()/ 2);
        w.render(&painter);
    });

    return a.exec();
}
