includes += include_directories('.')

# https://github.com/mesonbuild/meson/blob/0.54.2/docs/markdown/Reference-tables.md#operating-system-names
system = build_machine.system()

if system == 'windows'
  message('adding windows specific cpp files')
  sources += files(
    'IGraphicsWin.cpp',

  )
elif system == 'linux'
  message('adding linux specific cpp files')
  sources += files(
'IGraphicsLinux.cpp',
  )
else
  # can i just.. error/exception or something ?
  assert(false, 'Cannot handle system ' + system)
endif
