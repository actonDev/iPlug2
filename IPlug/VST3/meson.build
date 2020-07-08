includes += include_directories('.')

sources += files(
  'IPlugVST3.cpp',
  'IPlugVST3_ProcessorBase.cpp',

  # the following 2 are not stated in the IPlugControls project
  # 'IPlugVST3_Controller.cpp',
  # 'IPlugVST3_Processor.cpp',
)

system = build_machine.system()
if system == 'linux'
  sources += files(
    # from linux branch
    # 'IPlugVST3_RunLoop.cpp',
    )
endif
