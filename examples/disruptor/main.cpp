#include "MyProcess.h"
#include "process/MidasMain.h"
#include "utils/log/Log.h"

int main(int argc, char *argv[]) { return midas::MidasMain<MyProcess>(argc, argv); }
