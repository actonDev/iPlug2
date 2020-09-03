includes += include_directories('.', 'Extras',
'ReaperExt' # in case of reaper extension
)

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

sources_RPR = files(
    # damn, ReaperExt_include_in_plug_src.h has
    # #include "ReaperExtBase.cpp"

    # 'ReaperExt/ReaperExtBase.cpp'
 'IPlugParameter.cpp',
 'IPlugPaths.cpp',
 'IPlugTimer.cpp',
)