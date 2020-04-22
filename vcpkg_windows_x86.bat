mkdir build
cd build || goto :error
git clone https://github.com/Microsoft/vcpkg.git vcpkg.windows.x86 || goto :error
cd vcpkg.windows.x86 || goto :error
git checkout 2020.04 || goto :error
call bootstrap-vcpkg.bat || goto :error

vcpkg.exe install ^
	sdl2:x86-windows-static ^
	sdl2-mixer:x86-windows-static ^
	|| goto :error

cd ..
cd ..

exit /b


:error
echo Failed with error #%errorlevel%.
exit /b %errorlevel%
