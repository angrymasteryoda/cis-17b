#include "testWidget.h"
#include <QFile>

NewsPage::NewsPage(QWidget *parent) : QWidget (parent),ui(new Ui::NewsPage){
    ui->setupUi(this);

    QDomDocument xml;
    QFile xmlFime( ":/newsArticles.xml" );
    xml.setContent( &xmlFime );

    QDomElement root = xml.firstChildElement();
    QDomNodeList articlePath = root.elementsByTagName( "Articles" ).at( 0 ).childNodes();
}
