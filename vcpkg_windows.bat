mkdir build
cd build || goto :error
git clone https://github.com/Microsoft/vcpkg.git vcpkg.windows || goto :error
cd vcpkg.windows || goto :error
git checkout 2020.01 || goto :error
call bootstrap-vcpkg.bat || goto :error

vcpkg.exe install ^
	enet:x86-windows-static ^
	sdl2:x86-windows-static ^
	sdl2-mixer:x86-windows-static ^
	|| goto :error

cd ..
cd ..

exit /b


:error
echo Failed with error #%errorlevel%.
exit /b %errorlevel%
