project('iPlug2', 'cpp', 'c')
system = host_machine.system()

sources = []
includes = []

sources_APP = []
sources_VST3 = []

message('iplug2: igraphics option is ' + ', '.join(get_option('IGRAPHICS')))
igraphics = get_option('IGRAPHICS')

# https://mesonbuild.com/Reference-manual.html#array-object
if igraphics.contains('NO_IGRAPHICS')
  assert(igraphics.length() == 1, 'in the case of NO_IGRAPHICS you cannot pass more options in the IGRAPHICS option')
else
  assert(system == 'windows', 'graphics only implemented for windows at the moment')
  assert(igraphics.length() > 0, 'please pass an IGRAPHICS backend')
  subdir('IGraphics')
endif

args_base = [] # even for reaper-extension
args_common = [] # app, vst3

foreach igraphic : igraphics
  argument = '-D'+igraphic
  message('adding argument ' + argument)
  args_base += argument
endforeach

args_base += '-DNOMINMAX'

# default ones, hardcoded for now
args_common += [
  '-DIPLUG_DSP=1',
  '-DIPLUG_EDITOR=1',
]

if system == 'windows'
  args_common += [
    '-D__WINDOWS_ASIO__',
    '-D__WINDOWS_MM__',
    '-D__WINDOWS_DS__',
  ]
elif system == 'linux'
    args_common += [
    '-Dlinux', # seen in IPlugPlatform.h
    '-DOS_LINUX',
    '-D__LINUX_PULSE__',
    # '-D__LINUX_ALSA__',
    # '-DSWELL_PROVIDED_BY_APP',
    # '-DSWELL_LOAD_SWELL_DYLIB',
  ]
endif


args_APP = [
  '-DAPP_API',
]

args_VST3 = [
  '-DVST3_API'
]

# VST needs some definitions
# fdebug.h:69:4: error: #error DEVELOPMENT, RELEASE, _DEBUG, or NDEBUG must be defined!
# TODO dev vs release, in flags..?
args_VST3 += ['-DDEVELOPMENT']

if system == 'windows'
  args_VST3 += [
    '-D_WIN32',
    '-D_WINDLL',
  ]
elif system == 'linux'
  # SMTG_PTHREADS ??
  # SMTG_OS_LINUX
  args_VST3 += ['-DSMTG_OS_LINUX']
endif

subdir('IPlug')
subdir('Dependencies')
subdir('WDL')


system = host_machine.system()
link_args = []
compiler_id = meson.get_compiler('cpp').get_id()
if system == 'windows'
  # hm.. dsound I guess is only for the standalone. maybe separate in the future

  if compiler_id == 'gcc'
    # mingw
    link_args += ['-ldsound', '-lwinmm', '-lshlwapi', '-lcomctl32']
  else
    # msvc
    link_args += ['dsound.lib', 'winmm.lib', 'Shlwapi.lib', 'comctl32.lib']
  endif
elif system == 'linux'
  link_args += [
    '-lpthread',
    # '-lxcb',
    '-ldl',
    # '-lGL',
    '-lfontconfig',
    '-lpulse',
    '-lpulse-simple',
  ]
endif


# TODO make 2 static libraries and then
# declare_dependency that link to them
# or.. not. Right now we just 'inject' the sources
# in the project that uses iplug2
#
# Don't know how could I handle the config.h, include_in_src files etc

iplug2_APP_dep = declare_dependency(
  include_directories: includes,
  sources: sources + sources_APP,
  compile_args: args_base + args_common + args_APP,
  link_args: link_args,
)

# todo make this optional.. no need to download VST3 sdk if we only want APP..
iplug2_VST3_dep = declare_dependency(
  include_directories: includes,
  sources: sources + sources_VST3,
  compile_args: args_base + args_common + args_VST3,
  link_args: link_args,
)

if system == 'linux'
  sources_RPR += sources_SWELL
endif
iplug2_RPR_dep = declare_dependency(
  include_directories: includes,
  sources: sources_RPR,
  compile_args: args_base,
  link_args: link_args,
)
