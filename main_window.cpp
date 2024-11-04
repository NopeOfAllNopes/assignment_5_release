#include "main_window.h"
#include "clickable_label.h"
#include "./ui_main_window.h"
#include <filesystem>
#include <qwindowdefs.h>
#include <iostream>
#include <QString>
#include <QtWidgets>
#include <QPixmap>

using namespace std;
namespace fs = filesystem;

//set a image storage path for testing
//later this will have it's contents changed based on search parameters
filesystem::path STORAGE_PATH = "C:/Users/dillo/Documents/TestProject/placeholder_image_repository";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_home_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_action_browse_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
    populate_table(3,3);
}

void MainWindow::on_action_view_image_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::populate_table(int max_rows, int max_cols){
    ui->tableWidget->setColumnCount(max_cols);
    ui->tableWidget->setRowCount(max_rows);
    int imgSize = ui->tableWidget->width() / max_cols;
    cout << imgSize << endl;

    int i,j = -1;
    cout << "got files, loading" << endl;
    for (const auto & image : fs::directory_iterator(STORAGE_PATH)){
        cout << "loading file: " << image.path().generic_string() << endl;
        QString final_path = QString::fromStdString(image.path().generic_string());
        QPixmap pixmap;
        pixmap.load(final_path);

        QLabel *displayImage = new ClickableLabel(this);

        displayImage->setPixmap(pixmap.scaled(imgSize,imgSize));

        ui->tableWidget->setCellWidget(i, j, displayImage);

        QTableView *tableView = ui->tableWidget;
        tableView->resizeRowsToContents();
        tableView->resizeColumnsToContents();

        //connect label to click event to move image to image view page
        connect(displayImage, SIGNAL(clicked(newPixmap)), this, SLOT(on_image_cell_clicked(newPixmap)));

        i++;
        if (i > max_cols + 1){
            i = -1;
            j++;
        }
        if (j > max_rows){
            break;
        }
    }
}

void MainWindow::on_image_cell_clicked()
{
    cout << "clicked label" << endl;
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_row_count_valueChanged(int arg1)
{
    ui->tableWidget->setRowCount(arg1);
}


void MainWindow::on_column_count_valueChanged(int arg1)
{
    ui->tableWidget->setColumnCount(arg1);
}

