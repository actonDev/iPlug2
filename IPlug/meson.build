includes += include_directories('.')

sources += files(
'IPlugAPIBase.cpp',
 'IPlugParameter.cpp',
 'IPlugPaths.cpp',
 'IPlugPluginBase.cpp',
 'IPlugProcessor.cpp',
 'IPlugTimer.cpp',
)

# checking IPLUG_TARGET
target = get_option('IPLUG_TARGET')
message('IPLUG_TARGET: ' + target)
if target == 'APP'
  subdir('APP')
elif target == 'VST3'
  subdir('VST3')
endif

# todo: do we always need Extras?
subdir('Extras')
