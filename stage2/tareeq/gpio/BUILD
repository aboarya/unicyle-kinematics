cc_library(
    name = "gpio",
    srcs = glob(["*.cc"]),	
    hdrs = glob(["*.h"]),
    linkopts = [
      "-pthread",
    ],
    deps = [
      "@linux_libs//:gpiod",
    ],
    visibility = ["//visibility:public"],
)
