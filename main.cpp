#include "src/card.hpp"
#include <iostream>

#include <QApplication>
#include <QWebEngineView>


int main(int argc, char *argv[]){
    std::string d_front = "This is a dummy card!";
    std::string d_back = "Correct";
    std::string d_front_image_path = "";
    std::string d_back_image_path = "";
    std::string d_code = "";

    QApplication app(argc, argv);
    QWebEngineView view;

    view.setHtml("<h1>Hello, Flashcards!</h1><p>This is rendered by QWebEngineView.</p>");

    // Show the window
    view.resize(800, 600);
    view.show();

    return app.exec();

    // Card dummy(d_front, d_back, d_front_image_path, d_back_image_path, d_code);
    // std::cout << dummy.getFront() << "\n" << dummy.getBack() << std::endl;
    // return 0;
}