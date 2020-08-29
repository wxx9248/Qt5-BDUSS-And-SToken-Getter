#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QWebEngineView>
#include <QNetworkCookie>
#include <QWebEngineCookieStore>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(const QUrl url);
    virtual ~MainWindow();

public slots:
    // Event Handlers
    // WebEngine
    void onURLChanged(const QUrl url);
    void onCookieAdded(const QNetworkCookie cookie);
    // Buttons
    void onDefaultPageButtonClicked();
    void onRefreshButtonClicked();
    void onClearCookiesButtonClicked();

private:
    // Fields
    Ui::MainWindow *ui;
    QWidget widgetCookieContainer;
    QVBoxLayout layoutVerticalCookieContainer;
    const QUrl defaultURL;
    QWebEngineCookieStore *webEngineCookieStore;
    QVector<QNetworkCookie> cookies;

    // Methods
    bool cookieFilter(QNetworkCookie cookie);
};
#endif // MAINWINDOW_HPP
