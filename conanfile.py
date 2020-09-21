from conans import ConanFile, CMake, tools
import os.path
import shutil
import glob

class LangOcrConan(ConanFile):
    build_requires = "cmake/3.17.3"
    settings = "os", "compiler", "build_type", "arch"
    requires = "qt/5.14.2@bincrafters/stable", "tesseract/4.1.1", "leptonica/1.79.0", "zstd/1.4.5"
    generators = "cmake", "cmake_find_package"
    build_folder = "build"

    def build(self):
        self.build_folder = "build"
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def imports(self):
        # Because there are so many nested dependencies
        # we end up with way too many Find cmake files.
        # We just need QT because of CMake's requirement of finding Moc.
        qt_cmake = os.path.abspath(f"Findqt.cmake")
        shutil.move(qt_cmake, qt_cmake + ".tmp")
        files = glob.glob(os.path.abspath("Find*.cmake"))
        [os.remove(file) for file in files]
        shutil.move(qt_cmake + ".tmp", qt_cmake)

