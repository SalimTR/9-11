#ifndef MAINWINDOWBC_H
#define MAINWINDOWBC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowBC; }
QT_END_NAMESPACE

class MainWindowBC : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowBC(QWidget *parent = nullptr);
    ~MainWindowBC();

private slots:
    void on_butBag_clicked();

    void on_butAjout_clicked();

    void on_pushButton_2_clicked();

    void on_butModif_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_butAff_clicked();

    void on_pushButton_3_clicked();

    void on_sup_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_7_clicked();

    void on_butCol_clicked();

    void on_butretourc_clicked();

    void on_butAjoutc_clicked();

    void on_pushButton_11_clicked();

    void on_butAffichc_clicked();

    void on_butConfAjoutC_clicked();

    void on_pushButton_14_clicked();

    void on_butsupprc_clicked();

    void on_butSupprc_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_butmodifc_clicked();

    void on_toColis_clicked();

    void on_pushButton_17_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_ddd_clicked();

    void on_ccc_clicked();

    void on_butTri_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_buttriC_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_butStat_clicked();

private:
    Ui::MainWindowBC *ui;
};
#endif // MAINWINDOWBC_H
