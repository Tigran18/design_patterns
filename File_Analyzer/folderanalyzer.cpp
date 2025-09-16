#include "folderanalyzer.h"

FolderAnalyzer::FolderAnalyzer(QObject *parent) : QObject(parent)
{
}

QMap<QString, qint64> FolderAnalyzer::analyzeFolder(const QString &path)
{
    QMap<QString, qint64> sizes;
    QDir dir(path);

    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList list = dir.entryInfoList();

    for (const QFileInfo &info : list) {
        if (info.isDir()) {
            QString subPath = info.absoluteFilePath();
            qint64 size = calculateFolderSize(subPath);
            sizes.insert(info.fileName(), size);
        }
    }

    return sizes;
}

qint64 FolderAnalyzer::calculateFolderSize(const QString &path)
{
    qint64 size = 0;
    QDir dir(path);

    dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList list = dir.entryInfoList();

    for (const QFileInfo &info : list) {
        if (info.isFile()) {
            size += info.size();
        } else if (info.isDir()) {
            size += calculateFolderSize(info.absoluteFilePath());
        }
    }

    return size;
}
