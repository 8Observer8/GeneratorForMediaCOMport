#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Sender.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSettings_triggered();

    void on_actionExit_triggered();

    void on_playPauseSendButton_clicked();

    void on_stopSendButton_clicked();

    void on_muteSendButton_clicked();

    void on_volumeIncreaseSendButton_clicked();

    void on_volumeDecreaseSendButton_clicked();

    void slotSetSettings( const QString &portName,
                          const QString &portSpeed );

    void on_backSendButton_clicked();

    void on_nextSendButton_clicked();

private:
    void sendData( const QString &text );

private:
    Ui::MainWindow *ui;
    Sender *m_sender;
};

#endif // MAINWINDOW_H
