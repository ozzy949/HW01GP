#ifndef CONTACTUS_H
#define CONTACTUS_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class ContactUs : public QWidget {
    Q_OBJECT

public:
    explicit ContactUs(QWidget *parent = nullptr);
    ~ContactUs();

private:
    QLabel* label;  // Label to display text
};

#endif // CONTACTUS_H
