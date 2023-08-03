#!/bin/zsh

# export PATH="/Users/preston/Work/llvm15/bin:$PATH"
$clang15pp webio_win32.cc `psc --os win32 --clang-flags` -o ../objects/webio_win32.o -c
$clang15pp webio_unix.cc `psc --os linux --arch x86_64 --clang-flags` -o ../objects/webio_linux_x86_64.o -c
$clang15pp webio_unix.cc `psc --os linux --arch arm --clang-flags` -o ../objects/webio_linux_arm.o -c
$clang15pp webio_unix.cc `psc --os osx --arch x86_64 --clang-flags` -o ../objects/webio_osx_x86_64.o -c
$clang15pp webio_unix.cc `psc --os osx --arch arm --clang-flags` -o ../objects/webio_osx_arm.o -c -Xclang -no-opaque-pointers
$clang15pp webio_android.cc -fpic `psc --os android --clang-flags` -o ../objects/webio_android.o -c -Xclang -no-opaque-pointers
$clang15pp webio_unix.cc `psc --os ios --clang-flags` -o ../objects/webio_ios_arm.o -c -Xclang -no-opaque-pointers
$clang15pp webio_unix.cc `psc --os ios --arch x86_64 --clang-flags` -o ../objects/webio_ios_x86_64.o -c -Xclang -no-opaque-pointers
# /Users/prestonwallitsch/Work/NDK/toolchains/llvm/prebuilt/darwin-x86_64/bin/armv7a-linux-androideabi19-clang webio_android.cc -c -o ../objects/webio_android.o
