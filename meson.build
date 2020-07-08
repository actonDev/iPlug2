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
if system == 'windows'
  # just copied that from the provided examples
  # link_args += '/DYNAMICBASE "dsound.lib" "winmm.lib" "wininet.lib" "comctl32.lib" "Shlwapi.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib"'
  # link_args += '/TLBID:1'

  # so turns out that imgui subproject builds a library
  # and it has to be linked against opengl32.lib
  # it dones't just work if I add this link arg in my vst/exe target
  # add_global_link_arguments('/DYNAMICBASE "opengl32.lib"', language: 'cpp')
elif system == 'linux'
  link_args += [
    '-lpthread',
    '-lxcb',
    '-ldl',
    '-lGL',
    '-lfontconfig',
    # '-lpulse',
    # '-lpulse-simple',
  ]
  # extra_args += ['-fpermissive']
endif


# TODO make 2 static libraries and then
# declare_dependency that link to them

iplug2_APP_dep = declare_dependency(
  include_directories: includes,
  sources: sources + sources_APP,
  compile_args: args_common + args_APP,
  link_args: link_args + [
    '-lpulse',
    '-lpulse-simple',
    ]
)

# todo make this optional.. no need to download VST3 sdk if we only want APP..
iplug2_VST3_dep = declare_dependency(
  include_directories: includes,
  sources: sources + sources_VST3,
  compile_args: args_common + args_VST3,
  link_args: link_args,
)
