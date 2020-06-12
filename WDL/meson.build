includes += include_directories('.')
includes += include_directories('lice')
includes += include_directories('libpng')
includes += include_directories('zlib')

system = build_machine.system()
if system == 'linux'
  # cause we build also swell
  subdir('swell')
elif system == 'windows'
  # in windows it's not built.. but needed for some headers..?
  includes += include_directories('swell')
endif
