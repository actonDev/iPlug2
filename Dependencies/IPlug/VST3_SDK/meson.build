# note, no subdirs here, since th subfolders are coming from uzniping the sdk

message('in VST3_SDK dir')
res = run_command('bash', 'config.sh')
message('VST3 sdk download: \n' + res.stdout().strip())

# not sure at the end if the rest are needed
includes += include_directories('.')

# includes += include_directories('public.sdk/source/vst/')
sources += files(
  'public.sdk/source/vst/vstaudioeffect.cpp',
 'public.sdk/source/vst/vstbus.cpp',
 'public.sdk/source/vst/vstcomponent.cpp',
 'public.sdk/source/vst/vstcomponentbase.cpp',
 # 'public.sdk/source/vst/vsteditcontroller.cpp',
 # 'public.sdk/source/vst/vstgui_win32_bundle_support.cpp',
 # 'public.sdk/source/vst/vstguieditor.cpp',
 'public.sdk/source/vst/vstinitiids.cpp',

 'public.sdk/source/vst/vstparameters.cpp',
 # these next ones are not in the iplugControls project
 # 'public.sdk/source/vst/vstnoteexpressiontypes.cpp',
 # 'public.sdk/source/vst/vstpresetfile.cpp',
 # 'public.sdk/source/vst/vstrepresentation.cpp',
 
 'public.sdk/source/vst/vstsinglecomponenteffect.cpp',
)

sources += files(
  'public.sdk/source/common/commoniids.cpp',
 'public.sdk/source/common/memorystream.cpp',
 'public.sdk/source/common/pluginview.cpp',
 # 'public.sdk/source/common/threadchecker_linux.cpp',
 # 'public.sdk/source/common/threadchecker_win32.cpp',
)

sources += files(
  'public.sdk/source/main/dllmain.cpp',
  # TODO check this for linux
 # 'public.sdk/source/main/linuxmain.cpp',
 # 'public.sdk/source/main/macmain.cpp',
 'public.sdk/source/main/pluginfactory.cpp',
  
)

sources += files(
  'base/source/baseiids.cpp',
 'base/source/fbuffer.cpp',
 'base/source/fdebug.cpp',
 'base/source/fdynlib.cpp',
 'base/source/fobject.cpp',
 'base/source/fstreamer.cpp',
 'base/source/fstring.cpp',
 'base/source/timer.cpp',
 'base/source/updatehandler.cpp',
)

sources += files(
'base/thread/source/fcondition.cpp',
 'base/thread/source/flock.cpp',
  )

sources += files(
'pluginterfaces/base/conststringtable.cpp',
 'pluginterfaces/base/coreiids.cpp',
 'pluginterfaces/base/funknown.cpp',
 'pluginterfaces/base/ustring.cpp',

  )
