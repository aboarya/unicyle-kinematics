
cc_library(
    name = "robot_motion_model",
    srcs = glob([

        "motor.h",
        "motor.cc",
                
	"unicycle_model.h",
	"unicycle_model.cc",
	
	"unicycle_driver.h",
        "unicycle_driver.cc",

    ]),
    hdrs = glob([
        "interfaces/state.h",	
	"interfaces/sensor.h",
	"interfaces/actuator.h",
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
	"//tareeq/control:robot_motion_model"
    ],
)
