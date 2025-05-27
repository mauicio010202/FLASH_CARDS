#include "src/card.hpp"
#include <iostream>

#include <QApplication>
#include <QWebEngineView>
#include <QUrl>
#include <QFile>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


int main(int argc, char *argv[]){
    qputenv("QTWEBENGINE_DISABLE_SANDBOX", "1"); // required for WSL

    std::string d_front = "This is a dummy card!";
    std::string d_back = "Correct";
    std::string d_front_image_path = "";
    std::string d_back_image_path = "";
    std::string d_code = "";

    QApplication app(argc, argv);
    QWebEngineView view;

    QString filePath = "../assets/body/index.html";
    filePath = QFileInfo(filePath).absoluteFilePath();

    QUrl url = QUrl::fromLocalFile(filePath);
    view.load(url);

    // Show the window
    view.resize(800, 600);
    view.show();

    return app.exec();
}