project(
  'sample-meson',
  ['c', 'cpp'],
  version: '0.1',
  default_options: [
    'warning_level=3',
    'cpp_std=c++14',
  ],
)

main_src = []
src = []
inc = include_directories('include')

subdir('src')

both_lib = both_libraries(
    'sample-meson',
    src,
    include_directories: inc,
    implicit_include_directories: false,
)
executable(
  'sample-meson',
  main_src,
  include_directories: inc,
  implicit_include_directories: false,
  install: true,
  link_with: both_lib.get_shared_lib(),
)

# subdir('tests')
