-- stylua: ignore start
add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = "."})

add_requires("range-v3")
add_requires("fmt")
add_requires("catch2")

add_packages("range-v3")
add_packages("fmt")
add_packages("catch2")


set_languages("c++26")

target("project-euler")
    set_kind("binary")
    add_files("src/*.cpp")
