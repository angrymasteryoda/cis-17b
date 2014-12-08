#include "save.h"


Save::Save( QString file ) {
    saveFile = file;
    boardSize = 81;
}

void Save::saveGame( int* mask, int *board, int time, int level ){
    Settings settings( saveFile );

    settings.saveSetting( "mask", arrayToJson( mask ) );
    settings.saveSetting( "board", arrayToJson( board ) );
    settings.saveSetting( "time", QString::number( time ) );
    settings.saveSetting( "level", QString::number( level ) );
}

QString Save::arrayToJson( int *array ){
    QString str = "[";
    for( int i = 0; i < boardSize; i++ ){
        str.append( QString::number( array[i] ) );
        if( i < boardSize - 1 ){
            str += ",";
        }
    }
    str.append( "]" );
    return str;
}

int* Save::jsonToArray( QString str ){
    str = str.replace( QRegExp( "\\[([0-9,]+)\\]" ), "\\1" );
    QStringList list = str.split( "," );
    int* res = new int[ list.size() ];
    for( int i = 0; i < list.size(); i++ ){
        res[0] = list[i].toInt();
    }
    return res;
}

GameSave Save::load(){
    Settings settings( saveFile );
    GameSave game( jsonToArray( settings.getSetting( "mask" ) ),
                   jsonToArray( settings.getSetting( "board" ) ),
                   settings.getSetting( "level" ).toInt(),
                   settings.getSetting( "time" ).toInt()
                   );
    return game;
}
