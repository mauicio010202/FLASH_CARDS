#ifndef WEBVIEWWINDOW_HPP
#define WEBVIEWWINDOW_HPP

#include <QWidget>
#include <QWebEngineView>
#include <QWebChannel>

class WebViewWindow : public QWidget {
    Q_OBJECT

public:
    explicit WebViewWindow(QWidget *parent = nullptr);
    ~WebViewWindow();

    void loadHtml(const QString &filePath);
    void runJavaScript(const QString &code);

private:
    QWebEngineView *view;
};

#endif