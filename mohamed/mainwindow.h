#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "billet.h"
#include <QMainWindow>
#include "voyageur.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_ajouterbillet_clicked();

    void on_supprimerbillet_clicked();

    void on_ajoutervoyageur_clicked();

    void on_supprimervoyageur_clicked();

    void on_pushButton_2_clicked();



    void on_pushButton_3_clicked();



    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    billet tmpBillet;
    voyageur tmpvoyageur;
};
#endif // MAINWINDOW_H
