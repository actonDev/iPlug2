# project('iplug2', 'cpp', 'c')

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
# todo: iterate IGRAPHICS option, and add the defines
foreach igraphic : igraphics
  argument = '-D'+igraphic
  message('adding argument ' + argument)
  # it seems like it doesn't work with add_project_arguments ?
  # however add_global_arguments doesn't work in subprojects
  arguments += argument
  add_project_arguments(argument, language : 'cpp')
endforeach

subdir('IPlug')
subdir('Dependencies')
subdir('WDL')

iplug2_dep = declare_dependency(
  include_directories: includes,
  sources: sources
  )
