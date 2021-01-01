from conans.model.conan_file import ConanFile
from conans import CMake


class TestConanGTestExample(ConanFile):
    name = "TestConanGTestExample"
    version = "0.1.0"
    author = "lasote"
    url = "https://github.com/lasote/conan-gtest-example"
    license = "MIT"
    settings = "os", "compiler", "arch", "build_type"
    generators = "cmake"
    cmake = None
    requires = "gtest/1.8.1@bincrafters/stable"
    default_options = "gtest:shared=True"

    def build(self):
        self.cmake = CMake(self)
        self.cmake.configure()
        self.cmake.build()
        self.cmake.test()

    def test(self):
        target_test = "RUN_TESTS"
        self.cmake.build(target=target_test)
