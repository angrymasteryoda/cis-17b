#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char *argv[])
{
    QApplication prog(argc, argv);

    QWidget *mainWindow = new QWidget;
    mainWindow->setWindowTitle( "How many chicken wings?" );

    QSpinBox *spinner = new QSpinBox;
    QSlider *slider = new QSlider( Qt::Horizontal );

    spinner->setRange( 1, 50 );
    slider->setRange( 1, 50 );

    QObject::connect( spinner, SIGNAL( valueChanged( int ) ), slider, SLOT( setValue( int ) ) );
    QObject::connect( slider, SIGNAL( valueChanged( int ) ), spinner, SLOT( setValue( int ) ) );

    spinner->setValue( 10 );
    slider->setValue( 10 );

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget( slider );
    layout->addWidget( spinner );
    mainWindow->setLayout( layout );
    mainWindow->show();

    return prog.exec();
}
