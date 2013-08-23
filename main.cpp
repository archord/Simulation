

#include <QApplication>

#include "dialog.h"
#include "inputdefaultfile.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
        /*
    Dialog w;
    w.show();
        */

    InputDefaultFile *inputfile = new InputDefaultFile;
    inputfile->readFile();
    inputfile->replaceValue("ra","1234567");
    inputfile->replaceValue("convert_paras","123asd4567");
    inputfile->writeFile();

    return a.exec();
}
