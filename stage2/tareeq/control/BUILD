#cc_library(
#    name = "control",
#    srcs = glob(["*.cc"]),	
#    hdrs = glob(["*.h"]),
#    linkopts = [
#      "-pthread",
#    ],
#    deps = [
#      "@linux_libs//:gpiod",
#      "//tareeq/gpio:gpio"
#    ],
#    visibility = ["//visibility:public"],
#)

cc_library(
    name = "unicycle_actuator",
    srcs = glob([
        "motor.h",
        "motor.cc",
        "unicycle_driver.cc",
        "unicycle_driver.h",
    ]),
    hdrs = glob([
        "interfaces/actuators.h"
    ]),
    deps = [
        "//tareeq/gpio:gpio"
    ],
    visibility = [
        "//visibility:public",
    ],
)

cc_binary(
    name = "agent",
    srcs = ["agent.h", "agent.cc"],
    linkstatic=False,
    deps = [
	"//tareeq/control:actuators"
    ],
)