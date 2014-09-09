#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication prog(argc, argv);
    QPushButton *button = new QPushButton( "quit the program" );
    QObject::connect( button, SIGNAL(clicked()), &prog, SLOT(quit()) );

    button->show();
    return prog.exec();
}
