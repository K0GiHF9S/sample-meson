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

add_project_link_arguments('/MAP', language: ['c', 'cpp'])

subdir('src')

lib = static_library(
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
  link_with: lib,
)

subdir('tests')
