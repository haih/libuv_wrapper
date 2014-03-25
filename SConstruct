# --------------------------------- #
# Scons Compiler Script             #
# version 1.03                      #
# 03/25/2014                        #
#                                   #
# INSTRUCTIONS                      #
# 1. Using scons to compile         #
# 2. scons -Q to filter the not-    #
#   important information           #
# 3. scons -c to clean project      #
# --------------------------------- #

VariantDir('./obj/','./src/',duplicate=0)
env=Environment(CCFLAGS = ['-std=c++0x','-g','-Wall'], 
       #         ENV = os.environ, 
                CPPPATH= './src/',
				LIBS=['glog','pthread','uv']
                )
env.Program('./bin/test', [Glob('./obj/*.cpp')])

