#include <QApplication>
#include "download_mgr.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    download_mgr w;
    w.show();
    
    return a.exec();
}
