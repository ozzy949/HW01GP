#include "contactus.h"

ContactUs::ContactUs(QWidget *parent)
    : QWidget(parent) {
    // Set the size and title of the new window
    setWindowTitle("Contact Us");
    resize(300, 200);

    // Create a label with more text
    label = new QLabel("For support, contact us at teamAI@hotmail.com", this);

    // Layout to manage widgets
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);
}

ContactUs::~ContactUs() {
    delete label;
}
