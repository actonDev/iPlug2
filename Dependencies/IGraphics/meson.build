message('iplug2/Dependencies/IGraphics dir')
system = host_machine.system()

includes += include_directories('./STB')

if igraphics.contains('IGRAPHICS_NANOVG')
  includes += include_directories('./NanoSVG/src')
  includes += include_directories('./NanoVG/src')
endif

if igraphics.contains('IGRAPHICS_GL3')
  message('adding glad_GL3')
  includes += include_directories('./glad_GL3/include')
endif

