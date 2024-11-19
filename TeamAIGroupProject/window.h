#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>

#include "shapeswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class window;
}
QT_END_NAMESPACE

class window : public QMainWindow
{
    Q_OBJECT

public:
    window(QWidget *parent = nullptr);
    ~window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::window *ui;
};
#endif // WINDOW_H
