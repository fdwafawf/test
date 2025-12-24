#include "systemMonitor.h"

systemMonitor::systemMonitor(QObject *parent)
    : QObject{parent}
{
    GetSystemTimes(&m_preIdleTime, &m_preKernelTime, &m_preUserTime);
}

double systemMonitor::getCpuUsage()  
{
    FILETIME curIdleTime, curKernelTime, curUserTime;
    if(!GetSystemTimes(&curIdleTime, &curKernelTime, &curUserTime))
    {
        return 0.0;
    }

    quint64 preIdle = fileTimeToUInt64(m_preIdleTime);
    quint64 preKernel = fileTimeToUInt64(m_preKernelTime);
    quint64 preUser = fileTimeToUInt64(m_preUserTime);

    quint64 curIdle = fileTimeToUInt64(curIdleTime);
    quint64 curKernel = fileTimeToUInt64(curKernelTime);
    quint64 curUser = fileTimeToUInt64(curUserTime);

    quint64 idleDiff = curIdle - preIdle;
    quint64 kernelDiff = curKernel - preKernel;
    quint64 userDiff = curUser - preUser;

    m_preIdleTime = curIdleTime;
    m_preKernelTime = curKernelTime;
    m_preUserTime = curUserTime;

    quint64 totalSys = kernelDiff + userDiff;
    if (totalSys == 0) {
        return 0.0;
    }
    return (double)(totalSys - idleDiff) * 100.0 / totalSys;
}

double systemMonitor::getMemoryUsage() 
{
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    
    GlobalMemoryStatusEx(&memInfo);

    return (double)memInfo.dwMemoryLoad;
}

QString systemMonitor::getMemoryStr()     
{
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);

    double totalGB = memInfo.ullTotalPhys / (1024.0 * 1024.0 * 1024.0);
    double freeGB = memInfo.ullAvailPhys / (1024.0 * 1024.0 * 1024.0);
    double usedGB = totalGB - freeGB;

    return QString::asprintf("%.1f / %.1f GB", usedGB, totalGB);
}

quint64 systemMonitor::fileTimeToUInt64(const FILETIME &ft)
{
    return (static_cast<quint64>(ft.dwHighDateTime) << 32) | static_cast<quint64>(ft.dwLowDateTime);
}