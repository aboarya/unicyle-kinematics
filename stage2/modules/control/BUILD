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
    name = "actuators",
    srcs = ["unicycle_driver.cc"],	
    hdrs = ["actuators.h"],
    deps = [
      "//tareeq/gpio:gpio"
    ],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "agent",
    srcs = ["agent.h", "agent.cc"],
    linkstatic=False,
    deps = [
	"//modules/control:actuators"
    ],
)