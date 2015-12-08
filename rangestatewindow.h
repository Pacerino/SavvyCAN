#ifndef RANGESTATEWINDOW_H
#define RANGESTATEWINDOW_H

#include <QDialog>
#include "can_structs.h"

namespace Ui {
class RangeStateWindow;
}

class RangeStateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RangeStateWindow(const QVector<CANFrame> *frames, QWidget *parent = 0);
    ~RangeStateWindow();
    void showEvent(QShowEvent*);

private slots:
    void updatedFrames(int);
    void recalcButton();

private:
    Ui::RangeStateWindow *ui;
    const QVector<CANFrame> *modelFrames;
    QVector<CANFrame> frameCache;
    QHash<int, bool> idFilters;

    void refreshFilterList();
    void closeEvent(QCloseEvent *event);
    void readSettings();
    void writeSettings();
    void signalsFactory();
    void processSignal(int startBit, int bitLength, int sensitivity, bool bigEndian, bool isSigned);
    void createGraph(QVector<int> values);
};

#endif // RANGESTATEWINDOW_H
