//
// Created by 宁旭晖 on 2021/1/17.
//

#include "log.h"

#include <utility>
#include <iostream>
#include <sstream>

namespace sylar {
/**********************Logger***************************/
    Logger::Logger(std::string name)
            : m_name(std::move(name)) {}

    void Logger::addAppender(const LogAppender::ptr &appender) {
        m_appenders.push_back(appender);
    }

    void Logger::delAppender(const LogAppender::ptr &appender) {
        for (auto it = m_appenders.begin(); it != m_appenders.end(); it++) {
            if (*it == appender) {
                m_appenders.erase(it);
                break;
            }
        }
    }

    void Logger::log(LogLevel::Level level, const LogEvent::ptr &event) {
        if (level > m_level) {
            for (auto &i : m_appenders) {
                i->log(level, event);
            }
        }
    }

    void Logger::debug(const LogEvent::ptr &event) {
        log(LogLevel::DEBUG, event);
    }

    void Logger::info(const LogEvent::ptr &event) {
        log(LogLevel::INFO, event);
    }

    void Logger::warn(const LogEvent::ptr &event) {
        log(LogLevel::WARN, event);
    }

    void Logger::error(const LogEvent::ptr &event) {
        log(LogLevel::ERROR, event);
    }

    void Logger::fatal(const LogEvent::ptr &event) {
        log(LogLevel::FATAL, event);
    }


/**********************Appender***************************/
    FileLogAppender::FileLogAppender(std::string filename) : m_filename(std::move(filename)) {}

    void StdoutLogAppender::log(LogLevel::Level level, LogEvent::ptr event) {
        if (level >= m_level) {
            std::cout << m_formatter->format(event);
        }
    }

    void FileLogAppender::log(LogLevel::Level level, LogEvent::ptr event) {
        if (level >= m_level) {
            m_filestream << m_formatter->format(event);
        }
    }

    bool FileLogAppender::reopen() {
        if (m_filestream) {
            m_filestream.close();
        }
        m_filestream.open(m_filename);
        return !!m_filestream;
    }

/**********************Formatter***************************/
    LogFormatter::LogFormatter(std::string pattern) : m_pattern(std::move(pattern)) {}

    // %xxx %xxx(xxx) %%
    void LogFormatter::init() {
        std::vector<std::tuple<std::string, std::string, int> > vec;
        std::string nstr;
        for (char i : m_pattern) {
            if (i == '%') {
                if (m_pattern[i] != '%') {
                    str.append(1, m_pattern[i]);
                    continue;
                }

                if ((i + 1) < m_pattern.size()) {
                    if (m_pattern[i + 1] == '%') {
                        nstr.append(1, '%');
                        continue;
                    }
                }

                size_t n = i + 1;
                int fmt_status = 0;
                size_t fmt_begin = 0;

                std::string str;
                std::string fmt;
                while (n < m_pattern.size()) {
                    if (isspace(m_pattern[n])) {
                        break;
                    }
                    if (fmt_status == 0) {
                        if (m_pattern[n] == '{') {
                            str = m_pattern.substr(i + 1, n - i);
                            fmt_status = 1; // 解析格式
                            n++;
                            fmt_begin = n;
                            continue;
                        }
                    }
                    if (fmt_status == 1) {
                        if (m_pattern[n] == '}') {
                            fmt = m_pattern.substr(fmt_begin + 1, n - fmt_begin - 1);
                            fmt_status = 2;
                            break;
                        }
                    }
                }
                if (fmt_status == 0) {
                    if (!nstr.empty()) {
                        vec.push_back(std::make_tuple(nstr, "", 0));
                    }
                    str = m_pattern.substr(i + 1, n - i - 1);
                    vec.push_back(std::make_tuple(str, fmt, 1));
                    i = n;
                } else if (fmt_status == 1) {
                    std::cout << "pattern parse error: " << m_pattern << " - " << m_pattern.substr(i) << std::endl;
                    vec.push_back(std::make_tuple("<<pattern_error>>", fmt, 0));
                } else if (fmt_status == 2) {
                    vec.push_back(std::make_tuple(str, fmt, 1));
                    i = n;
                }
            }
        }
        if (!nstr.empty()) {
            vec.push_back(std::make_tuple(nstr, "", 0));
        }
        // %m -- 消息体
        // %p -- level
        // %r -- 启动后的事件
        // %c -- 日志名称
        // %t -- 线程id
        // %n -- 回车换行
        // %d -- 事件
        // %f --
    }

    std::string LogFormatter::format(LogEvent::ptr event) {
        std::stringstream ss;
        for (auto &i : m_items) {
            i->format(ss, event);
        }
        return ss.str();
    }
}