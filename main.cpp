#include "src/card.hpp"
#include "src/database.hpp"
#include "webviewwindow.hpp"
#include <iostream>

#include <QApplication>


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

    // std::cout << "Enter the front: " << std::endl;
    // std::cin >> d_front;
    // std::cout << "Enter the back: " << std::endl;
    // std::cin >> d_back;
    // std::cout << "Enter the front image: " << std::endl;
    // std::cin >> d_front_image_path;
    // std::cout << "Enter the back image: " << std::endl;
    // std::cin >> d_back_image_path;
    // std::cout << "Enter the code: " << std::endl;
    // std::cin >> d_code;

    Card dummy(d_front, d_back, d_front_image_path, d_back_image_path, d_code);
    if (!db.addCard(dummy)) {
        qDebug() << "Failed to add card";
    }

    auto allCards = db.getAllCards();
    for (const auto &card : allCards) {
        qDebug() << "Q:" << QString::fromStdString(card.getFront()) << "A:" << QString::fromStdString(card.getBack());
    }

    window.loadHtml("../assets/body/index.html");
    window.show();

    return app.exec();
}