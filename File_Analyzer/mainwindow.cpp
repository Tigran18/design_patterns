#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDir>
#include <QFileSystemModel>
#include <QTreeView>
#include <QPushButton>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fileModel(new QFileSystemModel(this))
    , analyzer(new FolderAnalyzer(this))
{
    ui->setupUi(this);

    // Setup file system model
    fileModel->setRootPath(QDir::homePath());
    ui->folderTree->setModel(fileModel);
    ui->folderTree->setRootIndex(fileModel->index(QDir::homePath()));

    // Setup chart
    chartView = new QtCharts::QChartView(this);
    ui->chartLayout->addWidget(chartView);

    connect(ui->analyzeButton, &QPushButton::clicked, this, &MainWindow::on_analyzeButton_clicked);
    connect(ui->folderTree, &QTreeView::clicked, this, &MainWindow::on_folderTree_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete chartView;
}

void MainWindow::on_analyzeButton_clicked()
{
    QModelIndex index = ui->folderTree->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Error", "Please select a folder first");
        return;
    }

    QString path = fileModel->filePath(index);
    updateChart(path);
}

void MainWindow::on_folderTree_clicked(const QModelIndex &index)
{
    QString path = fileModel->filePath(index);
    if (QDir(path).exists()) {
        updateChart(path);
    }
}

void MainWindow::updateChart(const QString &path)
{
    QMap<QString, qint64> sizes = analyzer->analyzeFolder(path);

    QtCharts::QPieSeries *series = new QtCharts::QPieSeries();
    for (auto it = sizes.constBegin(); it != sizes.constEnd(); ++it) {
        series->append(it.key(), it.value() / (1024.0 * 1024.0)); // Convert to MB
    }

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Folder Size Distribution (MB)");
    chartView->setChart(chart);
}
