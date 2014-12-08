#ifndef SAVE_H
#define SAVE_H

#include <QtCore>
#include <QDebug>
#include "settings.h"
#include "gamesave.h"

class Save {
public:
    Save( QString );
    void saveGame( int*, int*, int, int );
    GameSave load();
private:
    QString arrayToJson( int* );

    int boardSize;
    int* jsonToArray( QString str );
    QString saveFile;
};

#endif // SAVE_H
