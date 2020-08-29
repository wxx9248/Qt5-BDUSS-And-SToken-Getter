#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QWebEngineProfile>

#include "cookiewidget.hpp"

MainWindow::MainWindow(const QUrl url)
    : QMainWindow(),
    ui(new Ui::MainWindow),
    widgetCookieContainer(),
    layoutVerticalCookieContainer(),
    defaultURL(url),
    webEngineCookieStore(nullptr),
    cookies()
{
    // Setup
    ui->setupUi(this);
    // User agent
    ui->webEngineViewMain->page()->profile()->setHttpUserAgent("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.83 Safari/537.36");
    // Cookie storage
    webEngineCookieStore = ui->webEngineViewMain->page()->profile()->cookieStore();
    widgetCookieContainer.setLayout(&layoutVerticalCookieContainer);
    ui->scrollAreaCookie->setWidget(&widgetCookieContainer);
    // Layout
    layoutVerticalCookieContainer.addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layoutVerticalCookieContainer.setContentsMargins(0, 0, 0, 0);
    layoutVerticalCookieContainer.setSpacing(0);

    // Event binding
    // WebEngineView
    connect(ui->webEngineViewMain, &QWebEngineView::urlChanged, this, &MainWindow::onURLChanged);
    // Buttons
    connect(ui->buttonDefaultPage, &QPushButton::clicked, this, &MainWindow::onDefaultPageButtonClicked);
    connect(ui->buttonRefresh, &QPushButton::clicked, this, &MainWindow::onRefreshButtonClicked);
    connect(ui->buttonClearCookies, &QPushButton::clicked, this, &MainWindow::onClearCookiesButtonClicked);
    // Cookie storage
    connect(webEngineCookieStore, &QWebEngineCookieStore::cookieAdded, this, &MainWindow::onCookieAdded);

    // Load
    webEngineCookieStore->loadAllCookies();
    ui->webEngineViewMain->load(url);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onURLChanged(const QUrl url)
{
    if (url.host().contains("baidu.com"))
        ui->lineEditURL->setText(url.toString());
    else
    {
        QMessageBox::information(nullptr, u8"你好像丢了", u8"<font face=\"Microsoft Yahei UI\">按确定跳转回贴吧首页</font>");
        onDefaultPageButtonClicked();
    }
}

void MainWindow::onDefaultPageButtonClicked()
{
    ui->webEngineViewMain->load(defaultURL);
}

void MainWindow::onCookieAdded(const QNetworkCookie cookie)
{
    if (cookieFilter(cookie))
    {
        CookieWidget *cookieWidget = new CookieWidget(cookie, this);
        cookies.append(cookie);
        layoutVerticalCookieContainer.insertWidget(0, cookieWidget);
    }
}

void MainWindow::onRefreshButtonClicked()
{
    ui->webEngineViewMain->reload();
}

void MainWindow::onClearCookiesButtonClicked()
{
    webEngineCookieStore->deleteAllCookies();

    for (int i = layoutVerticalCookieContainer.count() - 1; i >= 0; --i)
        delete layoutVerticalCookieContainer.itemAt(i)->widget();

    cookies.clear();
}

bool MainWindow::cookieFilter(QNetworkCookie cookie)
{
    if (cookie.name() == "STOKEN" && cookie.domain().contains("tieba.baidu.com"))
        return true;
    else if (cookie.name() == "BDUSS" && cookie.domain().contains("baidu.com"))
        return true;
    else
        return false;
}
