#define GLOG_NO_ABBREVIATED_SEVERITIES
#include "core/engine.h"
#include <glog/logging.h>
#include "serial/controller.h"
#include <tcp/controller.h>
#include "machine/manager.h"
#include "config.h"
int main()
{
    FLAGS_alsologtostderr = 1;
    google::InitGoogleLogging("bj");
    FLAGS_log_dir = "log";
    mkdir("log", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    /* create folder files */
    mkdir(TEMPORARY_PATH, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    auto engine = core::Engine::instance();
    engine->registerComponent<tcp::Controller>();
    engine->registerComponent<serial::Controller>();
    engine->registerComponent<kit::Manager>();
    engine->start();

    return 0;
}