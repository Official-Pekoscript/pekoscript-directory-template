#!/bin/zsh

$clang15pp gc.cc `psc --os win32 --clang-flags` -o ../objects/gc_win32.o -c
$clang15pp gc.cc `psc --os linux --arch x86_64 --clang-flags` -o ../objects/gc_linux_x86_64.o -c
$clang15pp gc.cc `psc --os linux --arch arm --clang-flags` -o ../objects/gc_linux_arm.o -c
$clang15pp gc.cc `psc --os osx --arch x86_64 --clang-flags` -o ../objects/gc_osx_x86_64.o -c
$clang15pp gc.cc `psc --os osx --arch arm --clang-flags` -o ../objects/gc_osx_arm.o -c

$clang15pp gc.cc `psc --os android --clang-flags` -o ../objects/gc_android.o -c
$clang15pp gc.cc `psc --os ios --arch x86_64 --clang-flags` -o ../objects/gc_ios_x86_64.o -c
$clang15pp gc.cc `psc --os ios --clang-flags` -o ../objects/gc_ios_arm.o -c

$clang15 rt.c `psc --os win32 --clang-flags` -o ../objects/rt_win32.o -c
$clang15 rt.c `psc --os linux --arch x86_64 --clang-flags` -o ../objects/rt_linux_x86_64.o -c
$clang15 rt.c `psc --os linux --arch arm --clang-flags` -o ../objects/rt_linux_arm.o -c
$clang15 rt.c `psc --os osx --arch x86_64 --clang-flags` -o ../objects/rt_osx_x86_64.o -c
$clang15 rt.c `psc --os osx --arch arm --clang-flags` -o ../objects/rt_osx_arm.o -c

$clang15 rt.c `psc --os android --clang-flags` -o ../objects/rt_android.o -c
$clang15 rt.c `psc --os ios --arch x86_64 --clang-flags` -o ../objects/rt_ios_x86_64.o -c
$clang15 rt.c `psc --os ios --clang-flags` -o ../objects/rt_ios_arm.o -c