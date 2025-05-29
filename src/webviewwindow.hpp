#ifndef WEBVIEWWINDOW_HPP
#define WEBVIEWWINDOW_HPP

#include <QWidget>
#include <QWebEngineView>
#include <QWebChannel>

#include <QFile>

class WebViewWindow : public QWidget {
    Q_OBJECT

public:
    explicit WebViewWindow(QWidget *parent = nullptr);
    ~WebViewWindow();

    void loadHtml(const QString &filePath);
    void loadQString(const QString &htmlString);
    void readHtml(QString &htmlTemplate);
    void runJavaScript(const QString &code);

private:
    QWebEngineView *view;
    QString basePath;
    QString indexPath;
    QString cardPath;
    QUrl baseUrl;
};

#endif