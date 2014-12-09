#include <QApplication>

#include "testWidget.h"

int main( int argc, char* argv[] ){
    QApplication app( argc, argv );
    NewsPage news;
    news.show();
    return app.exec();
}
