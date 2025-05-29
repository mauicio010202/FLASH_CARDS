#include "webviewwindow.hpp"
#include <QVBoxLayout>
#include <QFileInfo>
#include <QUrl>

WebViewWindow::WebViewWindow(QWidget *parent) : QWidget(parent) {
    view = new QWebEngineView(this);
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(view);
    setLayout(layout);

    basePath = "../assets/body/";
    baseUrl = QUrl::fromLocalFile(QFileInfo(basePath).absolutePath() + "/");
    indexPath = basePath + "index.html";
    cardPath = basePath + "card.html";

    resize(800, 600);
}

void WebViewWindow::loadHtml(const QString &filePath) {
    QString absPath = QFileInfo(filePath).absoluteFilePath();
    view->load(QUrl::fromLocalFile(absPath));
}

void WebViewWindow::loadQString(const QString &htmlString) {
    view->setHtml(htmlString, baseUrl);
}

void WebViewWindow::runJavaScript(const QString &code) {
    view->page()->runJavaScript(code);
}

void WebViewWindow::readHtml(QString &htmlTemplate){
    QFile htmlFile(indexPath);
    if (htmlFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&htmlFile);
        htmlTemplate = in.readAll();
        htmlFile.close();
    } else {
        qDebug() << "Failed to open HTML template file:" << htmlFile.errorString();
        return;
    }
}

WebViewWindow::~WebViewWindow() {
    delete view;
}