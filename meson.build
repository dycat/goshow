project('goshow', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

deps = [dependency('glib-2.0')]

exe = executable('goshow', 'goshow.c',
  install : true, dependencies: deps)

test('basic', exe)
