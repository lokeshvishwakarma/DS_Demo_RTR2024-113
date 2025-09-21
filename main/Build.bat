del *.obj
cl.exe /c /EHsc main.c
cl.exe /c /EHsc ../props/Intro.c
cl.exe /c /EHsc ../props/Scene1.c
cl.exe /c /EHsc ../utils/SceneRender.c
cl.exe /c /EHsc ../utils/common.c
rc.exe main.rc
link.exe main.obj SceneRender.obj common.obj Intro.obj Scene1.obj main.res User32.lib GDI32.lib /SUBSYSTEM:WINDOWS
