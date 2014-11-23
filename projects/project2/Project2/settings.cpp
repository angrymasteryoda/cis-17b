#include "settings.h"

#include <QtCore>
/*
 * How to use me
 *
 * Settings settings( app.applicationDirPath() + "/config.ini", true, ":/res/config/config.ini" );
    settings.loadSettings();
    qDebug() << settings.getSetting( "go" );
    settings.saveSetting( "go", "derp" );
    qDebug() << settings.getSetting( "go" );
*/
/**
 * to use settings follow this rough pattern
 * Settings settings( app.applicationDirPath() + "/config.ini", true, ":/res/config/config.ini" );
 * settings.loadSettings();
 *
 * @brief Settings::Settings
 * @param file (can not be in the resource folder)
 * @param useDefault ( if true will copy the config file from default location to new file)
 * @param defaultFile
 */
Settings::Settings( QString file, bool useDefault, QString defaultFile ) {
    filename = file;
    QFile configFile( filename );
    qDebug() << configFile.exists();
    if( !configFile.exists() && useDefault ){
        if ( !QFile::copy( defaultFile, filename ) ) {
            qDebug() << "file exists shit broke";
        } else{
            //it coppied make it writable
            configFile.setPermissions( QFile::WriteOther );
        }

    }
    else if ( !configFile.exists() && !useDefault ){
        qDebug() << "No file to load, not loading fallback";
    }
    qSettings = new QSettings( filename, QSettings::IniFormat );
    isLoaded = false;
    configFile.close();
}

/**
 * @brief Settings::~Settings
 */
Settings::~Settings() {
    delete qSettings;
}

/**
 * load the settings and save them into a map
 * @brief Settings::loadSettings
 * @return isLoaded
 */
bool Settings::loadSettings(){
    QFile configFile( filename );
    if( configFile.exists() ){
        const QStringList childKeys = qSettings->childKeys();
        foreach( const QString &childKey, childKeys ){
            settings.insert( childKey, qSettings->value( childKey ).toString() );
        }
        isLoaded = true;
    }
    else {
        qDebug() << "couldn't find file.";
    }
    configFile.close();
    return isLoaded;
}

/**
 * get a value from the settings map
 * @brief Settings::getSetting
 * @param key
 * @return QString value
 */
QString Settings::getSetting( QString key ){
    if( !isLoaded ){
        loadSettings();
    }
    return settings.value( key, "" );
}

/**
 * change a setting and save it to the file
 * @brief Settings::saveSetting
 * @param key
 * @param value
 */
void Settings::saveSetting( QString key, QString value ){
    if( !isLoaded ){
        loadSettings();
    }
    if( settings.contains( key ) ){
        settings.insert( key, value );
    }
    qSettings->setValue( key, value );
    qSettings->sync();
    qDebug() << "status:" << qSettings->status();
}

/**
 * get the settings map
 * @brief Settings::getSettings
 * @return
 */
QMap<QString, QString> Settings::getSettings(){
    if( !isLoaded ){
        loadSettings();
    }
    return settings;
}

/**
 * are the settings loading
 * @brief Settings::getIsLoaded
 * @return
 */
bool Settings::getIsLoaded() {
    return isLoaded;
}
