#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //creating s string -> path to the text file
    QString ofile = "/home/berk/text.txt";
    //Telling to look for ofile = text.txt and that it is a file
    QFile file(ofile);
    //opening file to write text and checking whether errors have occured
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        //QDebug -> for error output
        qDebug ()<< "Error opening the file";
        return -1;
    }

    //qtin for user input
    QTextStream qtin(stdin);
    //qtin.readLine() to read the whole line (user input)
    QString s = qtin.readLine();
    //out into the file
    QTextStream out(&file);
    //wrinting the string s into file
    out<< s;

    //flushing, to make sure everything is closed/cleaned up
    file.flush();
    //closing the file
    file.close();

    return a.exec();

}
