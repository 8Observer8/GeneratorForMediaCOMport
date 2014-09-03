#include "SettingsDialog.h"
#include "ui_SettingsDialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_okButton_clicked()
{
    QString portName = ui->portNameComboBox->currentText();
    QString portSpeed = ui->portSpeedComboBox->currentText();
    emit signalSetSettings( portName, portSpeed );

    this->close();
}

void SettingsDialog::on_cancelButton_clicked()
{
    this->close();
}
