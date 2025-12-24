#pragma once

#include <QObject>

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif


class systemMonitor: public QObject
{
    Q_OBJECT

public:
    explicit systemMonitor(QObject *parent = nullptr);

    //对外接口
    double getCpuUsage();       //获取CPU使用率
    double getMemoryUsage();    //获取内存使用率
    QString getMemoryStr();     //获取内存使用情况字符串

private:
    //讲FILETIME转换为quint64
    quint64 fileTimeToUInt64(const FILETIME &ft);

    //记录上一次CPU时间
    FILETIME m_preIdleTime;
    FILETIME m_preKernelTime;
    FILETIME m_preUserTime;
};
