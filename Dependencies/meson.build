subdir('IPlug')

if igraphics.contains('NO_IGRAPHICS')
  assert(igraphics.length() == 1, 'in the case of NO_IGRAPHICS you cannot pass more options in the IGRAPHICS option')
else
  assert(system == 'windows', 'graphics only implemented for windows at the moment')
  assert(igraphics.length() > 0, 'please pass an IGRAPHICS backend')
  
  subdir('IGraphics')
endif
