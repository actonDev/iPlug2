project('iplug2', 'cpp', 'c')

sources = []
includes = []

message('in iplug2 project..')
message('igraphics option is ' + ', '.join(get_option('IGRAPHICS')))
igraphics = get_option('IGRAPHICS')

# https://mesonbuild.com/Reference-manual.html#array-object
if igraphics.contains('NO_IGRAPHICS')
  assert(igraphics.length() == 1, 'in the case of NO_IGRAPHICS you cannot pass more options in the IGRAPHICS option')
else
  assert(igraphics.length() > 0, 'please pass an IGRAPHICS backend')
  subdir('IGraphics')
  subdir('Dependencies/IGraphics')
endif

arguments = []
foreach igraphic : igraphics
  argument = '-D'+igraphic
  message('adding argument ' + argument)
  arguments += argument
  # the add_project_arguments directive works if we add iplug2 as a subdir
  # but as a subproject, the parent project should get the 'arguments'
  # and foreach of those run the add_project_arguments
  
  # add_project_arguments(argument, language : 'cpp')
endforeach

subdir('IPlug')
subdir('Dependencies')
subdir('WDL')

iplug2_dep = declare_dependency(
  include_directories: includes,
  sources: sources
  )
