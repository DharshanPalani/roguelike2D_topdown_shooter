#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

env.Append(CPPPATH=["src/"])

sources = []
for root, dirs, files in os.walk("src"):
    for f in files:
        if f.endswith(".cpp"):
            sources.append(os.path.join(root, f))

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "demo/bin/libgdexample.{}.{}.framework/libgdexample.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
elif env["platform"] == "ios":
    if env["ios_simulator"]:
        library = env.StaticLibrary(
            "demo/bin/libgdexample.{}.{}.simulator.a".format(env["platform"], env["target"]),
            source=sources,
        )
    else:
        library = env.StaticLibrary(
            "demo/bin/libgdexample.{}.{}.a".format(env["platform"], env["target"]),
            source=sources,
        )
else:
    library = env.SharedLibrary(
        "demo/bin/gdcpp{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
