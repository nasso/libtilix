local tek = require "@nasso/epine-tek/v0.1.0-alpha3"

tek:project "libmy" {"libmy.a"}

tek:static "libmy.a" {
    language = "C",
    defines = {
        "MY_ALLOW_FUN_MALLOC",
        "MY_ALLOW_FUN_FREE",
        "MY_ALLOW_FUN_WRITE"
    }
}

tek:binary "unit_tests" {
    prerequisites = {"libmy.a"},
    srcs = {find "./tests/*.c"},
    libs = {"my", "criterion"}
}

return tek:make()
