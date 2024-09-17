##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=TP3A23
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/Ting-Wei/Downloads/A23_Outils_CPP/A23_Outils_CPP/A23_codelite/C11_1169
ProjectPath            :=C:/Users/Ting-Wei/Downloads/A23_Outils_CPP/A23_Outils_CPP/A23_codelite/C11_1169/TP3A23
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ting-Wei
Date                   :=12/16/2023
CodeLitePath           :=D:/CodeLite
LinkerName             :=C:/MesLogiciels/msys64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/MesLogiciels/msys64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="TP3A23.txt"
PCHCompileFlags        :=
MakeDirCommand         :=C:/MesLogiciels/msys64/usr/bin/mkdir.exe -p
RcCmpOptions           := 
RcCompilerName         :=C:/MesLogiciels/msys64/mingw64/bin/windres.exe
LinkOptions            :=  $(shell wx-config --debug=yes --libs --unicode=yes)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/MesLogiciels/msys64/mingw64/bin/ar.exe -r
CXX      := C:/MesLogiciels/msys64/mingw64/bin/g++.exe
CC       := C:/MesLogiciels/msys64/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes --debug=yes) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes --debug=yes) $(Preprocessors)
ASFLAGS  := 
AS       := C:/MesLogiciels/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\CodeLite
Objects0=$(IntermediateDirectory)/RcheDlgNom.cpp$(ObjectSuffix) $(IntermediateDirectory)/RcheDlgPays.cpp$(ObjectSuffix) $(IntermediateDirectory)/RcheEntreAns.cpp$(ObjectSuffix) $(IntermediateDirectory)/Aire.cpp$(ObjectSuffix) $(IntermediateDirectory)/AirePtgApp.cpp$(ObjectSuffix) $(IntermediateDirectory)/RcheDlgAns.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/RcheDlgNom.cpp$(ObjectSuffix): RcheDlgNom.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Ting-Wei/Downloads/A23_Outils_CPP/A23_Outils_CPP/A23_codelite/C11_1169/TP3A23/RcheDlgNom.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RcheDlgNom.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RcheDlgNom.cpp$(PreprocessSuffix): RcheDlgNom.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RcheDlgNom.cpp$(PreprocessSuffix) RcheDlgNom.cpp

$(IntermediateDirectory)/RcheDlgPays.cpp$(ObjectSuffix): RcheDlgPays.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Ting-Wei/Downloads/A23_Outils_CPP/A23_Outils_CPP/A23_codelite/C11_1169/TP3A23/RcheDlgPays.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RcheDlgPays.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RcheDlgPays.cpp$(PreprocessSuffix): RcheDlgPays.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RcheDlgPays.cpp$(PreprocessSuffix) RcheDlgPays.cpp

$(IntermediateDirectory)/RcheEntreAns.cpp$(ObjectSuffix): RcheEntreAns.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Ting-Wei/Downloads/A23_Outils_CPP/A23_Outils_CPP/A23_codelite/C11_1169/TP3A23/RcheEntreAns.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RcheEntreAns.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RcheEntreAns.cpp$(PreprocessSuffix): RcheEntreAns.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RcheEntreAns.cpp$(PreprocessSuffix) RcheEntreAns.cpp

$(IntermediateDirectory)/Aire.cpp$(ObjectSuffix): Aire.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Ting-Wei/Downloads/A23_Outils_CPP/A23_Outils_CPP/A23_codelite/C11_1169/TP3A23/Aire.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Aire.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Aire.cpp$(PreprocessSuffix): Aire.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Aire.cpp$(PreprocessSuffix) Aire.cpp

$(IntermediateDirectory)/AirePtgApp.cpp$(ObjectSuffix): AirePtgApp.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Ting-Wei/Downloads/A23_Outils_CPP/A23_Outils_CPP/A23_codelite/C11_1169/TP3A23/AirePtgApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AirePtgApp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AirePtgApp.cpp$(PreprocessSuffix): AirePtgApp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AirePtgApp.cpp$(PreprocessSuffix) AirePtgApp.cpp

$(IntermediateDirectory)/RcheDlgAns.cpp$(ObjectSuffix): RcheDlgAns.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Ting-Wei/Downloads/A23_Outils_CPP/A23_Outils_CPP/A23_codelite/C11_1169/TP3A23/RcheDlgAns.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RcheDlgAns.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RcheDlgAns.cpp$(PreprocessSuffix): RcheDlgAns.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RcheDlgAns.cpp$(PreprocessSuffix) RcheDlgAns.cpp

##
## Clean
##
clean:
	$(RM) -r ./Debug/


