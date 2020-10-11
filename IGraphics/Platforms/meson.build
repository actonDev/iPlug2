includes += include_directories('.')

# https://github.com/mesonbuild/meson/blob/0.54.2/docs/markdown/Reference-tables.md#operating-system-names
system = host_machine.system()

if system == 'windows'
  message('adding windows specific cpp files')
  sources += files(
    'IGraphicsWin.cpp',

  )
else
  error('IGraphics: Cannot handle system ' + system)
endif
