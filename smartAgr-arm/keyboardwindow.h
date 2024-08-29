#ifndef KEYBOARDWINDOW_H
#define KEYBOARDWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
class KeyBoardWindow;
}

class KeyBoardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit KeyBoardWindow(QWidget *parent = 0);
    ~KeyBoardWindow();
    static KeyBoardWindow& getKeyBoard()
    {
        static KeyBoardWindow kbf;
        return kbf;
    }


private slots:
    void onButtonClicked(int id);
    void on_btn_shift_clicked(bool checked);

    void on_btn_hide_clicked();

private:
    Ui::KeyBoardWindow *ui;
};

#endif // KEYBOARDWINDOW_H
