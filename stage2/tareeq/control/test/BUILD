
cc_test (
    name = "unicycle_actuator_test",
    srcs = [
        "unicycle_driver_test.cc",
    ],
    deps = [    	
        "//tareeq/control:robot_motion_model",
	"//tareeq/mocks:robot_motion_mocks",
	"//tareeq/mocks:gpio_pins_mocks",
        "@gtest//:gtest",
        "@gtest//:gtest_main"
    ],
)

cc_test (
    name = "motor_test",
    srcs = [
        "motor_test.cc",
    ],
    deps = [
    	"//tareeq/mocks:gpio_pins_mocks",
        "//tareeq/control:robot_motion_model",
        "@gtest//:gtest",
        "@gtest//:gtest_main"
    ],
)
