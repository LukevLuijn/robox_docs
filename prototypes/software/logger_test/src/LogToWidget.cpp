//
// Created by luke on 16-05-22.
//



#include "LogToWidget.h"
#include "ScrolledLogWindow.h"

namespace Utils
{
    void LogToWidget::Log(const Utils::LogMessage& message)
    {
#if USING_WIDGETS
        Widgets::ScrolledLogWindow::AddMessage(message);
#else
        (void)message;
#endif
    }
}

