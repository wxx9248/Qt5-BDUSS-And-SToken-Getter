#include "cookiewidget.hpp"

#include <QClipboard>

CookieWidget::CookieWidget(const QNetworkCookie &cookie, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CookieWidget)
{
    ui->setupUi(this);

    // Text boxes setup
    ui->lineEditName->setText(cookie.name());
    ui->lineEditValue->setText(cookie.value());
    ui->lineEditDomain->setText(cookie.domain());

    // Event binding
    connect(ui->buttonCopyName, &QPushButton::clicked, this, &CookieWidget::onCopyNameButtonClicked);
    connect(ui->buttonCopyValue, &QPushButton::clicked, this, &CookieWidget::onCopyValueButtonClicked);
    connect(ui->buttonCopyDomain, &QPushButton::clicked, this, &CookieWidget::onCopyDomainButtonClicked);
}

void CookieWidget::onCopyNameButtonClicked()
{
    copyToClipboard(ui->lineEditName->text());
}

void CookieWidget::onCopyValueButtonClicked()
{
    copyToClipboard(ui->lineEditValue->text());
}

void CookieWidget::onCopyDomainButtonClicked()
{
    copyToClipboard(ui->lineEditDomain->text());
}

void CookieWidget::copyToClipboard(const QString &string)
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(string);
}
