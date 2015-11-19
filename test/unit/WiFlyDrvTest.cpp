#include "WiFlyDrvTest.h"
#include "utility/WiFlyDrv.h"
#include "mock/FakeUartWrapper.h"
#include "utility/WiFlyDrv.h"

Comm::FakeUartWrapper f_uart_;
Comm::WiFlyDrv drv_(&f_uart_);

using namespace Comm;

void WiFlyDrvTest::TestInit() {
    drv_.Init();

}

void WiFlyDrvTest::setup() {
}

void WiFlyDrvTest::once() {
}
