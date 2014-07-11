Project-HandsPower
==================

HowTo debug/run OpenCV-based code (MS VisualStudio 2013):

1. Download and install OpenCV from the official site (ATM last version is 2.4.9)
2. Suppose to install it in "C:\OpenCV" (so in that folder you see "build" and "sources" subfolders)
2a. Create a new project on MSVS (File>New Project>Select "VisualC++"+"Win32 Console Application">OK>Next>Select "Console Application">Tick on "Empty Project">Finish)
2b. If it isn't present, add the Property Manager (View>Other Windows>Property Manager)
3a. Under the toolbars, click on Win32 combobox, then Configuration Manager and on "Active solution platform" click on <New...>
3b. Select "x64" on the type and "Win32" on "Copy settings from" > OK > Close
4. RightClick on Debug|Win32>Add New Project Property Sheet...>Name it "OpenCV.props">Add
5. DoubleClick on the new file "OpenCV" in the Debug|Win32 folder
6. Common Preference>VC++ Directories> Include Directories > Add "C:\OpenCV\build\x86\vc10\bin" and "C:\OpenCV\build\include"
7. Common Preference>VC++ Directories> Library Directories > Add "C:\OpenCV\build\x86\vc10\lib"
8. Common Preference>C/C++>Additional Include Directories > Add "C:\OpenCV\build\include\opencv2"
9. Common Preference>Linker>Input>Additional Dipendencies > Add all these (249 is the 2.4.9 opencv version, change with yours):
```
opencv_calib3d249d.lib
opencv_contrib249d.lib
opencv_core249d.lib
opencv_features2d249d.lib
opencv_flann249d.lib
opencv_gpu249d.lib
opencv_haartraining_engined.lib
opencv_highgui249d.lib
opencv_imgproc249d.lib
opencv_legacy249d.lib
opencv_ml249d.lib
opencv_nonfree249d.lib
opencv_objdetect249d.lib
opencv_photo249d.lib
opencv_stitching249d.lib
opencv_ts249d.lib
opencv_video249d.lib
opencv_videostab249d.lib
```
10. Repeat the steps from 4 to 8 but RightClick on Release|Win32, in the step 9 instead put these values (249 only if your opencv version is 2.4.9)
```
opencv_calib3d249.lib
opencv_contrib249.lib
opencv_core249.lib
opencv_features2d249.lib
opencv_flann249.lib
opencv_gpu249.lib
opencv_haartraining_engined.lib
opencv_highgui249.lib
opencv_imgproc249.lib
opencv_legacy249.lib
opencv_ml249.lib
opencv_nonfree249.lib
opencv_objdetect249.lib
opencv_photo249.lib
opencv_stitching249.lib
opencv_ts249.lib
opencv_video249.lib
opencv_videostab249.lib
```
11. Repeat the steps from 4 to 9 but with Debug|x64 and step 10 with Release|x64
12. Enjoy OpenCV > VisualStudio > C++!
