Project-HandsPower
==================

HowTo debug/run OpenCV-based code (MS VisualStudio 2013):

1. Download and install OpenCV from the official site (ATM last version is 2.4.9)
2. Suppose to install it in "C:\OpenCV" (so in that folder you see "build" and "sources" subfolders)
3. Create a new project on MSVS (File>New Project>Select "VisualC++"+"Win32 Console Application">OK>Next>Select "Console Application">Tick on "Empty Project">Finish)
4. If it isn't present, add the Property Manager (View>Other Windows>Property Manager)
5. Under the toolbars, click on Win32 combobox, then Configuration Manager and on "Active solution platform" click on <New...>
6. Select "x64" on the type and "Win32" on "Copy settings from" > OK > Close
7. RightClick on Debug|Win32>Add New Project Property Sheet...>Name it "OpenCV.props">Add
8. DoubleClick on the new file "OpenCV" in the Debug|Win32 folder
9. Common Preference>VC++ Directories> Include Directories > Add "C:\OpenCV\build\x86\vc12\bin" and "C:\OpenCV\build\include"
10. Common Preference>VC++ Directories> Library Directories > Add "C:\OpenCV\build\x86\vc12\lib"
11. Common Preference>C/C++>Additional Include Directories > Add "C:\OpenCV\build\include\opencv2"
12. Common Preference>Linker>Input>Additional Dipendencies > Add all these (249 is the 2.4.9 opencv version, change with yours):
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
13\. Repeat the steps from 7 to 11 but RightClick on Release|Win32, in the step 12 instead put these values (249 only if your opencv version is 2.4.9)
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
14\. Repeat the steps from 7 to 12 but with Debug|x64 and step 13 with Release|x64 (obviously replace every path containing "x86" folder with "x64")
