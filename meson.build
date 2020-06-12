project('iPlug2', 'cpp', 'c')
system = build_machine.system()

message('iPlug2 linux...')

sources = []
includes = []

sources_APP = []
sources_VST3 = []

message('in iplug2 project..')
message('igraphics option is ' + ', '.join(get_option('IGRAPHICS')))
igraphics = get_option('IGRAPHICS')

# https://mesonbuild.com/Reference-manual.html#array-object
if igraphics.contains('NO_IGRAPHICS')
  assert(igraphics.length() == 1, 'in the case of NO_IGRAPHICS you cannot pass more options in the IGRAPHICS option')
else
  assert(system == 'windows', 'graphics only implemented for windows at the moment')
  assert(igraphics.length() > 0, 'please pass an IGRAPHICS backend')
  subdir('IGraphics')
  subdir('Dependencies/IGraphics')
endif

args_common = []
foreach igraphic : igraphics
  argument = '-D'+igraphic
  message('adding argument ' + argument)
  args_common += argument
endforeach

# default ones, hardcoded for now
args_common += [
  '-DIPLUG_DSP=1',
  '-DIPLUG_EDITOR=1',
  '-DNOMINMAX',
]

if system == 'windows'
  args_common += [
    '-D__WINDOWS_ASIO__',
    '-D__WINDOWS_MM__',
    '-D__WINDOWS_DS__',
  ]
elif system == 'linux'
  # can i just.. error/exception or something ?
  # assert(false, 'Cannot handle system ' + system)
    args_common += [
    '-Dlinux', # seen in IPlugPlatform.h
    '-DOS_LINUX',
    '-D__LINUX_PULSE__',
    # '-D__LINUX_ALSA__',
    # '-DSWELL_PROVIDED_BY_APP',
    # '-DSWELL_LOAD_SWELL_DYLIB',
  ]
endif


# target = get_option('IPLUG_TARGET')
args_APP = [
  '-DAPP_API',
]

args_VST3 = [
  '-DVST3_API'
]


if system == 'windows'
  args_VST3 += [
    '-D_WIN32',
    '-D_WINDLL',
  ]
endif

subdir('IPlug')
subdir('Dependencies')
subdir('WDL')

iplug2_APP_dep = declare_dependency(
  include_directories: includes,
  sources: sources + sources_APP
)

# todo make this optional.. no need to download VST3 sdk if we only want APP..
iplug2_VST3_dep = declare_dependency(
  include_directories: includes,
  sources: sources + sources_VST3
)
