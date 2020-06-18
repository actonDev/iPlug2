includes += include_directories('.')
includes += include_directories('lice')
includes += include_directories('libpng')
includes += include_directories('zlib')

system = build_machine.system()
if system == 'linux'
  # linux needs swell
  subdir('swell')
endif
