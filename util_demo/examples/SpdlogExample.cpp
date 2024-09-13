#include <spdlog/spdlog.h>
#include <spdlog/sinks/hourly_file_sink.h>
#include <spdlog/fmt/ostr.h>

#include <iostream>

void HourFileSink() {
    std::string logName = "log/hour_file_sink.log";
    auto sink = std::make_shared<spdlog::sinks::hourly_file_sink_mt>(logName);
    auto logger = spdlog::logger("test", sink);
    spdlog::set_level(spdlog::level::warn);

    logger.trace("trace msg");
    logger.info("info msg");
    logger.warn("warn msg");
    SPDLOG_TRACE("trace msg by macro");
    SPDLOG_INFO("info msg by macro");
    SPDLOG_WARN("warn msg by macro");
}

class some_class {};
std::ostream& operator<<(std::ostream& os, const some_class& c)
{ 
    return os << "some_class"; 
}

// fmt v10 and above requires `fmt::formatter<T>` extends `fmt::ostream_formatter`.
// See: https://github.com/fmtlib/fmt/issues/3318
template <> struct fmt::formatter<some_class> : fmt::ostream_formatter {};

void custom_class_example()
{
    some_class c;
    SPDLOG_INFO("{}", c);
}

int main() {
    // HourFileSink();
    custom_class_example();
    return 0; 
}