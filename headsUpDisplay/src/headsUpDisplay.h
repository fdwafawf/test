#pragma once
#include "ui_headsUpDisplay.h"
#include "systemMonitor.h"
#include <QMainWindow>

class headsUpDisplay : public QMainWindow {
    Q_OBJECT
    
public:
    headsUpDisplay(QWidget* parent = nullptr);
    ~headsUpDisplay();

//重写事件
public:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    Ui_headsUpDisplay* ui;

    systemMonitor *m_monitor; // 后端对象
    QTimer *m_timer;          // 定时器
    QPoint m_dragPosition;    // 记录鼠标拖拽位置

    // 存储显示的数据
    double m_cpuVal;
    QString m_memStr;
};