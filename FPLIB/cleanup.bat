@echo off
del *.lst
del *.a03
del *.r03
del *.log
for %%f in ( *.map ) do if not "%%f" == "SFR552.MAP" del %%f