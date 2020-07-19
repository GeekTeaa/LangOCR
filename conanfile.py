from conans import ConanFile, CMake, tools

class LangOcrConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "qt/5.14.2@bincrafters/stable", "tesseract/4.1.1", "leptonica/1.79.0", "zstd/1.4.5"
    generators = "cmake", "cmake_find_package"


    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()



