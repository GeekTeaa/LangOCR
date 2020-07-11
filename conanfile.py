from conans import ConanFile, tools

class LangOcrConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "qt/5.14.2@bincrafters/stable", "tesseract/4.1.1", "leptonica/1.79.0", "zstd/1.4.5"
    generators = "json"

    def imports(self):
        self.copy("*", src="@includedirs", dst="packages/include")
        self.copy("*", src="@libdirs", dst="packages/lib")
        self.copy("*", src="@bindirs", dst="packages/bin")
        self.copy("*", src="@resdirs", dst="packages/res")


