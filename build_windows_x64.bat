cd build || goto :error
mkdir windows.x64 || goto :error
cd windows.x64 || goto :error
cmake -D VCPKG_TARGET_TRIPLET=x64-windows-static -D CMAKE_TOOLCHAIN_FILE=../vcpkg.windows.x64/scripts/buildsystems/vcpkg.cmake -G "Visual Studio 17 2022" -A "x64" ../.. || goto :error
msbuild BelgianChocolateDuke3D.sln /t:Rebuild /p:Configuration=Release /p:Platform=x64 || goto :error
cd ..
cd ..

exit /b


:error
echo Failed with error #%errorlevel%.
exit /b %errorlevel%