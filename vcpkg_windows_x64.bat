mkdir build
cd build || goto :error
git clone https://github.com/Microsoft/vcpkg.git vcpkg.windows.x64 || goto :error
cd vcpkg.windows.x64 || goto :error
git checkout 2020.04 || goto :error
call bootstrap-vcpkg.bat || goto :error

vcpkg.exe install ^
	sdl2:x64-windows-static ^
	sdl2-mixer:x64-windows-static ^
	|| goto :error

cd ..
cd ..

exit /b


:error
echo Failed with error #%errorlevel%.
exit /b %errorlevel%
