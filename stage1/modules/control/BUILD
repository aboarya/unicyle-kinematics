cc_library(
    name = "control",
    srcs = glob(["*.cc"]),	
    hdrs = glob(["*.h"]),
    linkopts = [
      "-pthread",
    ],
    deps = [
      "@linux_libs//:gpiod",
      "//tareeq/gpio:gpio"
    ],
    visibility = ["//visibility:public"],
)

