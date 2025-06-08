-- stylua: ignore start
add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = "."})

add_includedirs("src")

add_requires("range-v3")
add_requires("fmt")

add_packages("range-v3")
add_packages("fmt")


set_languages("c++26")

for _, file in ipairs(os.files("test/test_*.cpp")) do
     local name = path.basename(file)
     target(name)
         set_kind("binary")
         add_files("test/" .. name .. ".cpp")
         set_default(false)
         add_tests("default")
end
