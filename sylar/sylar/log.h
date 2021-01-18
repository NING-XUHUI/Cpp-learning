//
// Created by 宁旭晖 on 2021/1/17.
//

#ifndef SYLAR_LOG_H
#define SYLAR_LOG_H

#include <string>
#include <cstdint>
#include <memory>
#include <list>
#include <fstream>
#include <vector>

namespace sylar {
    // 日志事件
    class LogEvent {
    public:
        typedef std::shared_ptr<LogEvent> ptr;

        LogEvent();

    private:
        const char *m_file = nullptr;   // 文件名
        int32_t m_line = 0;             // 行号
        uint32_t m_elapse = 0;          // 程序启动开始到现在的秒数
        uint32_t m_threadId = 0;        // 线程id
        uint32_t m_fiberId = 0;         // 协程id
        uint64_t m_time = 0;            // 时间戳
        std::string m_content;
    };

    // 日志级别
    class LogLevel {
    public:
        enum Level {
            DEBUG = 1,
            INFO = 2,
            WARN = 3,
            ERROR = 4,
            FATAL = 5
        };
    };

    // 日志格式器
    class LogFormatter {
    public:
        typedef std::shared_ptr<LogFormatter> ptr;

        LogFormatter(std::string  pattern);

        std::string format(LogEvent::ptr event);

    private:
        class FormatItem {
        public:
            typedef std::shared_ptr<FormatItem> ptr;

            virtual ~FormatItem() {}

            virtual void format(std::ostream& os, LogEvent::ptr event) = 0;
        };

        void init();
    private:
        std::string m_pattern;
        std::vector<FormatItem::ptr> m_items;
    };

    // 日志输出地
    class LogAppender {
    public:
        typedef std::shared_ptr<LogAppender> ptr;

        virtual ~LogAppender() {}

        virtual void log(LogLevel::Level level, LogEvent::ptr event) = 0;

        void setFormatter(const LogFormatter::ptr &val) { m_formatter = val; }

        LogFormatter::ptr getFormatter() const { return m_formatter; }

    protected:
        LogLevel::Level m_level;
        LogFormatter::ptr m_formatter;
    };

    // 日志器
    class Logger {
    public:
        typedef std::shared_ptr<Logger> ptr;

        explicit Logger(std::string name = "root");

        void log(LogLevel::Level level, const LogEvent::ptr &event);

        void debug(const LogEvent::ptr &event);

        void info(const LogEvent::ptr &event);

        void warn(const LogEvent::ptr &event);

        void error(const LogEvent::ptr &event);

        void fatal(const LogEvent::ptr &event);

        void addAppender(const LogAppender::ptr &appender);

        void delAppender(const LogAppender::ptr &appender);

        LogLevel::Level getLevel() const { return m_level; }

        void setLevel(LogLevel::Level val) { m_level = val; }

    private:
        std::string m_name;         // 日志名称
        LogLevel::Level m_level;    // 日志级别
        std::list<LogAppender::ptr> m_appenders;    // Appender集合
    };

    // 输出到控制台的Appender
    class StdoutLogAppender : public LogAppender {
    public:
        typedef std::shared_ptr<StdoutLogAppender> ptr;

        virtual void log(LogLevel::Level level, LogEvent::ptr event) override;
    };

    // 输出到文件的Appender
    class FileLogAppender : public LogAppender {
    public:
        typedef std::shared_ptr<FileLogAppender> ptr;

        FileLogAppender(std::string filename);

        virtual void log(LogLevel::Level level, LogEvent::ptr event) override;

        // 重新打开文件，文件打开成功，返回true
        bool reopen();
    private:
        std::string m_filename;
        std::ofstream m_filestream;
    };

}


#endif //SYLAR_LOG_H
