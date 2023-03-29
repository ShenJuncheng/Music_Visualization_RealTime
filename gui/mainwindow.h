#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QUrl>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMainWindow>
#include <QMediaPlaylist>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QMediaPlaylist *medialist;

public slots:
    void startVideo_1();
    void startVideo_2();
    void pauseVideo();
    void closeVideo();
    void resumeVideo();
};
#endif // MAINWINDOW_H
