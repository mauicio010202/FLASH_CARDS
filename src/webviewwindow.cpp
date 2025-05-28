#include "webviewwindow.hpp"
#include <QVBoxLayout>
#include <QFileInfo>
#include <QUrl>

WebViewWindow::WebViewWindow(QWidget *parent) : QWidget(parent) {
    view = new QWebEngineView(this);
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(view);
    setLayout(layout);

    resize(800, 600);
}

void WebViewWindow::loadHtml(const QString &filePath) {
    QString absPath = QFileInfo(filePath).absoluteFilePath();
    view->load(QUrl::fromLocalFile(absPath));
}

void WebViewWindow::runJavaScript(const QString &code) {
    view->page()->runJavaScript(code);
}

WebViewWindow::~WebViewWindow() {
    delete view;
}