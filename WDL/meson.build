includes += include_directories('.')
includes += include_directories('lice')
includes += include_directories('libpng')
includes += include_directories('zlib')

if build_machine.system() == 'linux'
  # cause we build also swell
  subdir('swell')
else
  # in windows it's not built.. but needed for some headers..?
  includes += include_directories('swell')
endif
