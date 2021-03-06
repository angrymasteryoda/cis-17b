#ifndef TEXTARTDIALOG_H
#define TEXTARTDIALOG_H

#include <QDialog>
#include <QList>

class QDialogButtonBox;
class QDir;
class QListWidget;
class TextArtInterface;

class TextArtDialog : public QDialog
{
    Q_OBJECT

public:
    TextArtDialog(const QString &text, QWidget *parent = 0);

    QPixmap selectedPixmap() const;

private:
    static QDir directoryOf(const QString &subdir);
    void loadPlugins();
    void populateListWidget(const QString &text);

    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;
    QList<TextArtInterface *> interfaces;
};

#endif
