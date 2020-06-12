subdir('IPlug')

if igraphics.contains('NO_IGRAPHICS')
  assert(igraphics.length() == 1, 'in the case of NO_IGRAPHICS you cannot pass more options in the IGRAPHICS option')
  if system == 'linux'
    # ..xcbt etc are used in IPlugVST3_RunLoop ..
    # so let's include it for now, see if I can build the vst
    subdir('IGraphics')
  endif
else
  assert(system == 'windows', 'graphics only implemented for windows at the moment')
  assert(igraphics.length() > 0, 'please pass an IGRAPHICS backend')
  subdir('IGraphics')
endif
