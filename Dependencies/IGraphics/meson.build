message('iplug2/Dependencies/IGraphics dir')

includes += include_directories('./STB')

if igraphics.contains('IGRAPHICS_NANOVG')
  includes += include_directories('./NanoSVG/src')
  includes += include_directories('./NanoVG/src')
endif

if igraphics.contains('IGRAPHICS_GL2')
  message('adding glad_GL2')
  includes += include_directories('./glad_GL2/include')
  includes += include_directories('./glad_GL2/src')
  # about glad_GL2/src/glad.c
  # there is the #include "glad.c" line in IGraphicsWin.cpp ...
endif

if igraphics.contains('IGRAPHICS_GL3')
  message('adding glad_GL3')
  includes += include_directories('./glad_GL3/include')
endif

system = build_machine.system()
if system == 'linux'
  assert(false, 'Graphics not working (yet) on linux, pleaseo do -DIGRAPHICS=[NO_GRAPHICS]')
  
  # the following includes & sources were from the linux branch
  
  # includes += include_directories('./xcbt')
  # includes += include_directories('./glad_GLX/include/')
  # includes += include_directories('./glad_GLX/src/')
  sources += files (
    # './glad_GLX/src/glad_glx.c',
    # './glad_GL2/src/glad.c',
    # './xcbt/xcbt.c'
    )
endif
