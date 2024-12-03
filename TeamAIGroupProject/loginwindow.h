#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "contactus.h"  // Include the new ContactUs header

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;
}
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_pushButton_clicked();  // Slot to handle login button click
    void on_contactUsButton_clicked();  // Slot to handle Contact Us button click

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
