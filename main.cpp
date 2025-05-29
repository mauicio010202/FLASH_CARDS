#include "src/card.hpp"
#include "src/database.hpp"
#include "webviewwindow.hpp"
#include <iostream>

#include <QApplication>
#include <QFile>
#include <QFileInfo>


int main(int argc, char *argv[]){
    qputenv("QTWEBENGINE_DISABLE_SANDBOX", "1"); // required for WSL
    QApplication app(argc, argv);
    WebViewWindow window;

    Database db;
    if (!db.initialize()) {
        return -1;
    }

    std::string d_front = "This is a dummy card!";
    std::string d_back = "Correct";
    std::string d_front_image_path = "";
    std::string d_back_image_path = "";
    std::string d_code = "";

    // Card dummy(d_front, d_back, d_front_image_path, d_back_image_path, d_code);
    // if (!db.addCard(dummy)) {
    //     qDebug() << "Failed to add card";
    // }

    QString temp;
    auto allCards = db.getAllCards();
    for (const auto &card : allCards) {
        qDebug() << "Q:" << QString::fromStdString(card.getFront()) << "A:" << QString::fromStdString(card.getBack());
        temp = QString::fromStdString(card.getFront());
    }

    
    QString htmlTemplate;
    window.readHtml(htmlTemplate);
   
    QString finalHtml = htmlTemplate.replace("%/USERNAME%", temp);

    window.loadQString(finalHtml);
    window.show();

    return app.exec();
}