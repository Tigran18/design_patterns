#ifndef FOLDERANALYZER_H
#define FOLDERANALYZER_H

#include <QObject>
#include <QDir>
#include <QMap>

class FolderAnalyzer : public QObject
{
    Q_OBJECT

public:
    explicit FolderAnalyzer(QObject *parent = nullptr);
    QMap<QString, qint64> analyzeFolder(const QString &path);

private:
    qint64 calculateFolderSize(const QString &path);
};

#endif // FOLDERANALYZER_H
