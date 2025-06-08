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
    after_build(function (target)
      cprint("${cyan bright}[test project-euler] ${clear}Runnning tests in parallel!")
      os.runv(target:targetfile(), {"--order rand", "--shard-count 4","--shard-index 0", "--rng-seed 0xBEEF"})
      os.runv(target:targetfile(), {"--order rand", "--shard-count 4","--shard-index 1", "--rng-seed 0xBEEF"})
      os.runv(target:targetfile(), {"--order rand", "--shard-count 4","--shard-index 2", "--rng-seed 0xBEEF"})
      os.runv(target:targetfile(), {"--order rand", "--shard-count 4","--shard-index 3", "--rng-seed 0xBEEF"})
      cprint("${cyan bright}[test project-euler] ${clear}All test passed!")
    end)
