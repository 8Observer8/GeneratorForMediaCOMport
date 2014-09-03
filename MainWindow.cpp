
#include <QDebug>
#include <QMessageBox>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SettingsDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_sender = new Sender;
}

MainWindow::~MainWindow()
{
    delete m_sender;
    delete ui;
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog dialog;
    dialog.setModal( true );
    connect( &dialog, SIGNAL( signalSetSettings( QString, QString) ),
             this, SLOT( slotSetSettings(QString, QString ) ) );
    dialog.exec();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_playPauseSendButton_clicked()
{
    QString text = ui->playPauseLineEdit->text();
    sendData( text );
}

void MainWindow::on_stopSendButton_clicked()
{
    QString text = ui->stopLineEdit->text();
    sendData( text );
}

void MainWindow::on_backSendButton_clicked()
{
    QString text = ui->backLineEdit->text();
    sendData( text );
}

void MainWindow::on_nextSendButton_clicked()
{
    QString text = ui->nextLineEdit->text();
    sendData( text );
}

void MainWindow::on_muteSendButton_clicked()
{
    QString text = ui->muteLineEdit->text();
    sendData( text );
}

void MainWindow::on_volumeIncreaseSendButton_clicked()
{
    QString text = ui->volumeIncreaseLineEdit->text();
    sendData( text );
}

void MainWindow::on_volumeDecreaseSendButton_clicked()
{
    QString text = ui->volumeDecreaseLineEdit->text();
    sendData( text );
}

void MainWindow::slotSetSettings(const QString &portName,
                                 const QString &portSpeed)
{
    delete m_sender;

    QSerialPort::BaudRate convertedPortSpeed =
            static_cast<QSerialPort::BaudRate>( portSpeed.toInt() );

    m_sender = new Sender( portName, convertedPortSpeed );

    try {
        m_sender->open();
    } catch ( const PortError &e ) {
        QMessageBox::information( this, "Error", QString( e.what() ) );
    } catch ( ... ) {
        QMessageBox::information( this, "Error", "Error: unknown exception" );
    }
}

void MainWindow::sendData(const QString &text)
{
    QByteArray data;
    data.append( text );
    try {
        m_sender->send( data );
    } catch ( const PortError &e ) {
        QMessageBox::information( this, "Error", QString( e.what() ) );
        return;
    } catch ( ... ) {
        QMessageBox::information( this, "Error", "Error: unknown exception" );
        return;
    }
}
