cd build || goto :error
mkdir windows.x86 || goto :error
cd windows.x86 || goto :error
cmake -D VCPKG_TARGET_TRIPLET=x86-windows-static -D CMAKE_TOOLCHAIN_FILE=../vcpkg.windows/scripts/buildsystems/vcpkg.cmake -G "Visual Studio 16 2019" -A "Win32" ../.. || goto :error
msbuild BelgianChocolateDuke3D.sln /t:Rebuild /p:Configuration=Release /p:Platform=Win32 || goto :error
cd ..
cd ..

exit /b


:error
echo Failed with error #%errorlevel%.
exit /b %errorlevel%