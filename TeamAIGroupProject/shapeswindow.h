#ifndef SHAPESWINDOW_H
#define SHAPESWINDOW_H

#include <QMainWindow>

namespace Ui {
class shapesWindow;
}

class shapesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit shapesWindow(QWidget *parent = nullptr);
    ~shapesWindow();

private:
    Ui::shapesWindow *ui;
};

#endif // SHAPESWINDOW_H
