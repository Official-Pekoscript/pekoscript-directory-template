$clang15 mysqlglue.c -c -I./include `psc --os linux --arch arm --clang-flags`    -o objects/mysql_glue_linux_arm.o
$clang15 mysqlglue.c -c -I./include `psc --os linux --arch x86_64 --clang-flags` -o objects/mysql_glue_linux_x86_64.o
$clang15 mysqlglue.c -c -I./include `psc --os osx --arch arm --clang-flags`      -o objects/mysql_glue_osx_arm.o
$clang15 mysqlglue.c -c -I./include `psc --os osx --arch x86_64 --clang-flags`   -o objects/mysql_glue_osx_x86_64.o
$clang15 mysqlglue.c -c -I./include `psc --os win32 --arch i686 --clang-flags`   -o objects/mysql_glue_win32.o
$clang15 mysqlglue.c -c -I./include `psc --os android --clang-flags`             -o objects/mysql_glue_android.o
$clang15 mysqlglue.c -c -I./include `psc --os ios --clang-flags`                 -o objects/mysql_glue_ios_arm.o
$clang15 mysqlglue.c -c -I./include `psc --os ios --arch x86_64 --clang-flags`   -o objects/mysql_glue_ios_x86_64.o