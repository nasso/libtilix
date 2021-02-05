local tek = require "@nasso/epine-tek/v0.1.0-alpha6"

tek:project "libtilix" {"libtilix.a"}

tek:static "libtilix" {
    libs = {tek:ref "libjzon", tek:ref "libmy"}
}

tek:binary "unit_tests" {
    srcs = {find "./tests/*.c"},
    libs = {tek:ref "libtilix", tek:ref "libjzon", tek:ref "libmy", "criterion"}
}

tek:pull "libmy" {git = "git@github.com:nasso/libmy"}
tek:pull "libjzon" {git = "git@github.com:nasso/libjzon"}

return tek:make()
