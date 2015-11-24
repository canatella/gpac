find_package (android)
find_package (PkgConfig)
find_package (ffmpeg)
pkg_check_modules(FAAD2 REQUIRED faad2)

include (gpac-targets)
