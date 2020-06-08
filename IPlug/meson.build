includes += include_directories('.')

sources += files(
'IPlugAPIBase.cpp',
 'IPlugParameter.cpp',
 'IPlugPaths.cpp',
 'IPlugPluginBase.cpp',
 'IPlugProcessor.cpp',
 'IPlugTimer.cpp',
)

sources_common = sources

sources = sources_APP
subdir('APP')
sources_APP = sources

sources = sources_VST3
subdir('VST3')
sources_VST3 = sources

sources = sources_common

subdir('Extras')
