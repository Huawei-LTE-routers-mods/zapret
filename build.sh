#!/bin/bash
set -e

# Balong Hi6921 V7R11 (E3372h, E5770, E5577, E5573, E8372, E8378, etc) and Hi6930 V7R2 (E3372s, E5373, E5377, E5786, etc)
# softfp, vfpv3-d16 FPU, Android API 19
make clean
CFLAGS="-D__ANDROID_API__=19 -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16 -mthumb" make
mv binaries/my/tpws binaries/tpws_vfp3-api19

# Balong Hi6920 V7R1 (E3272, E3276, E5372, etc)
# soft, novfp, Android API 9
make clean
CFLAGS="-D__ANDROID_API__=9 -march=armv7-a -mfloat-abi=soft -mthumb" make
mv binaries/my/tpws binaries/tpws_novfp_api9

echo
echo Check binaries/ folder for Huawei binaries
