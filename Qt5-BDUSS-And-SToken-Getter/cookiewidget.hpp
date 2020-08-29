#ifndef COOKIEWIDGET_HPP
#define COOKIEWIDGET_HPP

#include "ui_cookiewidget.h"

#include <QWidget>
#include <QNetworkCookie>

class CookieWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CookieWidget(const QNetworkCookie &cookie, QWidget *parent = nullptr);

public slots:
    void onCopyNameButtonClicked();
    void onCopyValueButtonClicked();
    void onCopyDomainButtonClicked();

private:
    // Fields
    Ui::CookieWidget *ui;

    // Methods
    void copyToClipboard(const QString &string);
};

#endif // COOKIEWIDGET_HPP
