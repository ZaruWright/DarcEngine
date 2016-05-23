IF NOT EXIST _build (mkdir _build)

cd _build
cmake ../ -G "Visual Studio 12"
msbuild "Game.sln" /property:Configuration=Debug
msbuild "INSTALL.vcxproj" /property:Configuration=Debug
msbuild "Game.sln" /property:Configuration=Release
msbuild "INSTALL.vcxproj" /property:Configuration=Release
cd ..