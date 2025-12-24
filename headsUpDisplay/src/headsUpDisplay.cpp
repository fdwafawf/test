#include "headsUpDisplay.h"
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>


headsUpDisplay::headsUpDisplay(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_headsUpDisplay)
{
    ui->setupUi(this);

    // 1. 窗口设置 (核心)
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);

    // 设置窗口大小
    resize(200, 100);

    // 2. 初始化后端
    m_monitor = new systemMonitor(this);

    // 3. 启动定时器，每 1000 毫秒（1秒）刷新一次
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, [=](){
        // 获取数据
        m_cpuVal = m_monitor->getCpuUsage();
        m_memStr = m_monitor->getMemoryStr();
        // 触发重绘 (调用 paintEvent)
        update(); 
    });
    m_timer->start(1000);
}

headsUpDisplay::~headsUpDisplay()
{
    delete ui; 
}

void headsUpDisplay::paintEvent(QPaintEvent* event)
{
Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿

    // 1. 画背景 (半透明黑色圆角矩形)
    painter.setBrush(QColor(0, 0, 0, 150)); // R,G,B, Alpha(透明度0-255)
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect(), 10, 10); // 10是圆角半径

    // 2. 画 CPU 文字
    painter.setPen(Qt::white);
    QFont font("Arial", 12, QFont::Bold);
    painter.setFont(font);

    // 这里简单排版一下
    painter.drawText(20, 30, QString("CPU: %1%").arg(QString::number(m_cpuVal, 'f', 1)));
    
    // 3. 画 内存 文字
    painter.drawText(20, 60, "RAM: " + m_memStr);
    
    // 4. 如果 CPU 占用过高，画个红点警告
    if (m_cpuVal > 80.0) {
        painter.setBrush(Qt::red);
        painter.drawEllipse(170, 15, 10, 10);
    }
}

void headsUpDisplay::mousePressEvent(QMouseEvent* event)
{
if (event->button() == Qt::LeftButton) {
        // 记录按下时，鼠标相对于窗口左上角的偏移
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    // 添加右键退出功能
    else if (event->button() == Qt::RightButton) {
        QMenu menu;
        menu.addAction("退出", qApp, &QApplication::quit);
        menu.exec(event->globalPos());
    }
}

void headsUpDisplay::mouseMoveEvent(QMouseEvent* event)
{
if (event->buttons() & Qt::LeftButton) {
        // 移动窗口
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}