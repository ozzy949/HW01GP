#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "contactus.h"  // Include the ContactUs header
#include "mainwindow.h"  // Include the MainWindow header

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->EmptyNameWarning->setVisible(false);

    // Connect the "Contact Us" button to the slot
    connect(ui->contactUsButton, &QPushButton::clicked, this, &LoginWindow::on_contactUsButton_clicked);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    QString userName = ui->NameLineEdit->text();
    if (userName.size() == 0) {
        ui->EmptyNameWarning->setVisible(true);  // Show warning if username is empty
    } else {
        // Proceed with the login process (hide the login window and show the main window)
        this->hide();
        MainWindow *mainwindow = new MainWindow();  // Create the MainWindow object
        mainwindow->show();  // Show the MainWindow
    }
}

void LoginWindow::on_contactUsButton_clicked()
{
    // Create the ContactUs window when the Contact Us button is clicked
    ContactUs *contactWindow = new ContactUs(this);

    // Get the position of the ContactUsButton relative to the main window
    QPoint buttonPos = ui->contactUsButton->mapToGlobal(ui->contactUsButton->pos());

    // Set the position of the ContactUs window relative to the button
    int x = buttonPos.x();  // X position
    int y = buttonPos.y() - contactWindow->height();  // Y position, above the button

    // Move the ContactUs window to the calculated position
    contactWindow->move(250, 400);

    // Show the window
    contactWindow->show();
}
