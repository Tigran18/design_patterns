#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QChartView>
#include "folderanalyzer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_analyzeButton_clicked();
    void on_folderTree_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *fileModel;
    FolderAnalyzer *analyzer;
    QtCharts::QChartView *chartView;
    void updateChart(const QString &path);
};
#endif // MAINWINDOW_H
