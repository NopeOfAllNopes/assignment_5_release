#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QtWidgets>

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
    void on_action_home_triggered();
    void on_action_browse_triggered();
    void on_action_view_image_triggered();
    void on_image_cell_clicked();
    void on_row_count_valueChanged(int arg1);
    void on_column_count_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    void populate_table(int max_rows, int max_cols);
};
#endif // MAIN_WINDOW_H
