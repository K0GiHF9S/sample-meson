gtest_dep = dependency('gtest')
gmock_dep = dependency('gmock', main: true, fallback: ['gtest', 'gmock_main_dep'])
test_deps = [gtest_dep, gmock_dep]

coverage = find_program('OpenCppCoverage', required: false)
if coverage.found()
    add_test_setup(
        'coverage',
        exe_wrapper: [
            coverage,
            '--quiet',
            '--source', join_paths(meson.project_source_root(), 'src').replace('/', '\\'),
            '--export', 'binary',
            '--',
        ],
        is_default: true,
    )
endif

dbghelp = meson.get_compiler('c').find_library('Dbghelp')
sample1_test = executable(
    'sample1_test',
    ['sample1Test.cpp', 'sample2Mock.cpp'],
    include_directories: inc,
    implicit_include_directories: false,
    dependencies: test_deps + dbghelp,
    link_with: both_libs.get_static_lib(),
)

test('sample1 test', sample1_test, protocol: 'gtest')
